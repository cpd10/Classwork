/*
    Darius Hooks
    COMP 322
    Lab #3
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <dirent.h>
#include <errno.h>
#include <wait.h>
void permissions(struct stat);

void main(int argc, char* argv[])
{
	DIR* dir = NULL;
	struct dirent* d = NULL;
    struct passwd pwd;
    struct passwd* result;
    struct stat bf;
	int pipefd[2];
    char* buf;
    size_t bufsize;
    pid_t cpid;
    int i, count = 1;
	int value, v2 = 1;
	
	if(argc == 1)
	{
		dir = opendir(".");
		while(d = readdir(dir))
		{
				argv[count] = d->d_name;
				count++;
		}
		argc += count;
		closedir(dir);
	}
	
	bufsize = sysconf(_SC_GETPW_R_SIZE_MAX);
    buf = (char*) malloc(bufsize);
	
	if(pipe(pipefd) == -1)
	{
		printf("Pipe Failue!");
		exit(1);
	}
	
	//write(pipefd[1], &v2, sizeof(value));
	//close(pipefd[1]);
    for(i = 1; i < argc; i++)
    {
		cpid = fork();
		
		if(cpid > 0)
		{
			continue;
		}
		
		else if(cpid == 0)
		{
			//close(pipefd[1]);
			//read(pipefd[0], &value, sizeof(value));
			//close(pipefd[0]);
			
			if(stat(argv[i], &bf) == -1)
			{
				fprintf(stderr, "\t%s: cannot access %s\n\n", argv[0], argv[i]);
				exit(1);
			}
		
			getpwuid_r(bf.st_uid, &pwd, buf, bufsize, &result);
			printf("\tFile: %s\n", argv[i]);
			printf("\tDirectory: %s\n", pwd.pw_dir);
			permissions(bf);
			//write(pipefd[1], &value, sizeof(value));
			//close(pipefd[1]);
			exit(0);
		}
		

		else
		{
			perror("Fork failed");
			exit(1);
		}
    }
	
	for(i = 1; i < argc; i++)
		wait(NULL);
    printf("Done\n");
	free(buf);
    exit(0);
}

void permissions(struct stat bf)
{
	//
	//OWNER PERMISSIONS
	//
	if(getuid() == bf.st_uid)
	{
		printf("\tYou have owner permissions:");
		if(bf.st_mode & S_IRUSR)
			printf(" read");
		if(bf.st_mode & S_IWUSR)
			printf(" write");
		if(bf.st_mode & S_IXUSR)
			printf(" execute");
	}
	//
	//GROUP PERMISSIONS
	//
	else if(getgid() == bf.st_gid)
	{
		printf("\tYou have group permissions:");
		if(bf.st_mode & S_IRGRP)
			printf(" read");
		if(bf.st_mode & S_IWGRP)
			printf(" write");
		if(bf.st_mode & S_IXGRP)
			printf(" execute");
	}
	//
	//GENERAL PERMISSIONS
	//
	else
	{
		printf("\tYou have general permissions:");
		if(bf.st_mode & S_IROTH)
			printf(" read");
		if(bf.st_mode & S_IWOTH)
			printf(" write");
		if(bf.st_mode & S_IXOTH)
			printf(" execute");
	}
	
	printf("\n\n");
}
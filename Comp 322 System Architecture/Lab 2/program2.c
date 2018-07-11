/*
    Darius Hooks
    COMP 322
    Lab #2
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

void main(int argc, char* argv[])
{
    pid_t cpid;
    int i;
    for(i = 1; i < argc; i++)
    {
	cpid = fork();
	
	if(cpid > 0)
	{
		continue;
	}
    
    	else if(cpid == 0)
	{
		printf("\tFilename: %s\tPID: %d\n", argv[i], getpid());
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
    exit(0);
}

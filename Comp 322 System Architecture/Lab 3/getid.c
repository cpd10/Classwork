#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    struct passwd pwd;
    struct passwd *result;
    char *buf;
	uid_t uid;
    size_t bufsize;

   bufsize = sysconf(_SC_GETPW_R_SIZE_MAX);
   buf = malloc(bufsize);

   getpwuid_r(520969563, &pwd, buf, bufsize, &result);

   printf("Name: %s; UID: %ld; DIR: %s\n", pwd.pw_name, (long) pwd.pw_uid, pwd.pw_dir);
}
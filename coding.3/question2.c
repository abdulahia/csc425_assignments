#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
int main(int argc, char* argv[])
{
	FILE *fp;
        fp=fopen("test2.txt", "w");
        int rc=fork();

        if (rc<0){
                printf("fork failed\n");
                exit(1);
        }
        else if (rc==0){
                printf("child process\n");
		fputs("this is the child writing into the file", fp);

        }else if (rc>0){
                wait(NULL);
                printf("parent process\n");
		fputs("this is the parent writing ", fp);
        }
	fclose(fp);
        return 0;
}
/* 2. Both the child and the parent can open the file but only one can write
into it eatch time and its random. I have tried it commenting each one out to
see which one will go first but its random but only one can write at time
 */

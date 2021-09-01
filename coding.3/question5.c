#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
        int rc=fork();

        if (rc<0){
                printf("fork failed\n");
                exit(1);
        }
        else if (rc==0){
		int wt= wait(NULL);
                printf("child process: \n");
                printf("hello %d \n", wt);

        }else if (rc>0){
		int wt = wait(NULL);
                printf("parent process: \n");
                printf("goodbye %d \n", wt);
        }
        return 0;
}
/* Ahmed Abdulahi
5.wait returns the PID of the child process. But when you also insert wait
child it exits with exit -1. 
 */


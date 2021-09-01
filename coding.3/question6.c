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
                printf("child process: \n");
                printf("hello \n");

        }else if (rc>0){
               
        	int wt = waitpid(rc, &status, WUNTRACED);
       		printf("parent process: \n");

		printf("goodbye  %d\n", wt);
        }
        return 0;
}
/* Ahmed Abdulahi
6.waitpid allows you to wait for specific process in this case we provide
the pid number and it would proceed after that child process is finished.
 */

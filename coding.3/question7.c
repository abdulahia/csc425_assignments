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
		close(STDOUT_FILENO);
                printf("child process: \n");
                printf("hello \n");

        }else if (rc>0){

                int wt = wait(NULL);
                printf("parent process: \n");
                printf("goodbye  %d \n", wt);
        }
        return 0;
}
/* Ahmed Abdulahi
7. It doesn't print out anything but moves on to the parent. There is no error
either.
 */

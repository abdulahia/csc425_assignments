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
               
                printf("parent process: \n");
                printf("goodbye \n");
        }
        return 0;
}
/* Ahmed Abdulahi
3. No, the parent will always print if you don't have wait() system call, 
but if there is wait(), then the child will always print first 
 */

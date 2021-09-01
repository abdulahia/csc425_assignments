
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
                char *args[]={"/bin/ls", NULL};
		/*execvp(args[0], args);*/
                execv(args[0], args);



        }else if (rc>0){

                wait(NULL);
        }
        return 0;
}
/* Ahmed Abdulahi
4. They all work different also the way their syntax is supposed to be written is different from one and another
 */
   

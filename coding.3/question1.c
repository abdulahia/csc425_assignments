#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
int main(int argc, char* argv[])
{

	int x = 100;
	int rc=fork();

	if (rc<0){
		printf("fork failed\n");
		exit(1);
	}
	else if (rc==0){
		printf("child process\n");
		printf("x before change:%d\n",x); 
		x = 50;
		printf("x after change:  %d\n",x);

	}else if (rc>0){
		wait(NULL);
		printf("parent process\n");
                printf("x before change: %d\n",x);
		x=25;
		printf("x after change: %d\n:",x);
	}
	return 0;
}

/*    
Ahmed Abdulahi
1. is the same as  originally set,but when I  change the child process, it
 changes first then parent changes but whatever changes we made in the child
 doesn't reflect in the parent. They are opereting seperately, they both have
access to the original x but what they with it does not affect the other. 

 */

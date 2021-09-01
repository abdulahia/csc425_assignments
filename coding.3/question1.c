#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
int maint()
{

	int x = 100;
	int rc=fork();

	if (rc<0){
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
	else if (rc==0){
		printf(stderr, "child process\n");
		printf("x before change:%d\n",x); 
		x = 50;
		printf("x after change:  %d\n:",x);

	}else if (rc>0){
		int rc_wait = wait(NULL);
		printf("parent process\n");
                printf("x before change: %d\n",x);
		x=25;
		printf("x after change: %d\n:",x);
	}
	return 0;
}


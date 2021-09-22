#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(int argc, char *argv[]) {
    size_t memory=atoi(argv[1]);
    const size_t num_size=memory*1024*1024/sizeof(int);
    int list[num_size];
    while(list){
    for(int i=0;i<num_size;++i)
        list[i]=i;
        printf("id %d/n", getpid());
    }
    return 0;

}

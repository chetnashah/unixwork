
#include<stdio.h>
#include<unistd.h>
int main(){
    printf("hello world\n");
    char *bootpath;

    bootpath = getbootfile();
    printf("bootfile = %s", bootpath);
}



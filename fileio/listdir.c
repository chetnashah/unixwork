#include <fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>
int main(){
    int buf[1024];
    int fd = open(".", O_RDONLY);
    printf("opened . fd = %d\n",fd); 
    int contentsFd = open("lsoutput.txt", O_WRONLY | O_CREAT | O_TRUNC);
    int n;
    n = read(fd, buf, 1024);
    printf("read errno = %d\n", errno);
    printf("human readable error = %s\n", strerror(errno));
    printf("n = %d\n",n);
    close(contentsFd);
    close(fd);
    return 0;
}


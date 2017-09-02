#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<time.h>
// headers for stat
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/sysmacros.h>
int main(){
    // the stat struct that will be populated by system call
    struct  stat sb;
    char* pathName = ".";
    
    if(stat(pathName, &sb) == -1) {
        int errorsv = errno;
        printf("error occured doing stat : %s\n", strerror(errorsv));
    }

    printf("ID of containing device: [%lx, %lx]\n", (long) major(sb.st_dev), (long)minor(sb.st_dev));

    printf("File type           ");
    switch(sb.st_mode & S_IFMT) {
        case S_IFBLK: printf("block device\n"); break;
        case S_IFCHR: printf("charachter device\n"); break;
        case S_IFDIR: printf("directory\n"); break;
        case S_IFIFO: printf(" FIFO/PIPE \n"); break;
        case S_IFLNK: printf("symlink\n"); break;
        case S_IFREG: printf("regular file\n"); break;
        case S_IFSOCK: printf("socket\n"); break;
        default: printf("unknown?\n"); break;
    }
    return 0;
}

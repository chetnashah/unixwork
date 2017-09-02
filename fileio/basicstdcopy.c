
#include<stdio.h>
#include<stdlib.h>

int main(){
    int c;
    while((c = getc(stdin)) != EOF) {
        if (putc(c, stdout) == EOF) {
            printf("write error!");
        }
        if (ferror(stdin)) {
            printf("read error!");
        }
    }
    exit(0);
}

#include<stdio.h>
#include<string.h>

int main(){
    char mystr[100];
    fgets(mystr, 100, stdin);
    printf("str length - %d", strlen(mystr));
    
    return 0;
}

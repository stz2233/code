#include<stdio.h>
#include<malloc.h>
#include <string.h> 
int main(){
    char a[5] ="2390", b[5];
    strcpy(b,a);
    printf("%s\n", b);
    return 0;
}
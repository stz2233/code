#include  <stdio.h>      /*标准输入输出定义*/
#include  <stdlib.h>     /*标准函数库定义*/
#include  <unistd.h>     /*Unix 标准函数定义*/
#include <sys/types.h> 
#include <sys/stat.h>
#include <fcntl.h>      /*文件控制定义*/
#include <termios.h>    /*PPSIX 终端控制定义*/
#include <errno.h>      /*错误号定义*/
#include <stdint.h>
#include<string.h>
int main(){
    int fd = -1;
    fd = open("/dev/", O_RDWR);
    if(fd==-1){
        perror("open error!\n");
    }
}
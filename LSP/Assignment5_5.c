#include<stdio.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fd = 0;
    int Ret = 0;
    struct stat sobj;
    char Buffer[BLOCKSIZE];

    fd = creat(argv[1], 0777);

    Ret = open(argv[1], O_RDWR);   

    fstat(Ret, &sobj);

    printf("File Name : %s\n", argv[1]);
    printf("File Size : %d\n", sobj.st_size);
    printf("Number of links : %d\n", sobj.st_nlink);
    printf("Inode number : %d\n", sobj.st_ino);
    printf("File system number : %d\n", sobj.st_dev);
    printf("Number of blocks : %d\n", sobj.st_blocks);

    return 0;
}
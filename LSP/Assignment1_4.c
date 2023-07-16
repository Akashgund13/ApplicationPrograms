#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat sobj;
    int fd = 0;

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }   

    fd = open(argv[1], O_RDONLY);
    stat(argv[1], &sobj);

    printf("File name : %s\n", argv[1]);
    printf("File size : %d\n", sobj.st_size);
    printf("Number of links : %d\n", sobj.st_nlink);
    printf("Inode number : %d\n", sobj.st_ino);
    printf("File System number : %d\n", sobj.st_dev);
    printf("Number of blocks : %d\n", sobj.st_blocks);

    return 0;
}
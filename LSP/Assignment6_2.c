#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    char FileHole[1024];
    int fd = -1;

    if(argc < 2)
    {
        fprintf(stderr, "Usage : %s <filename>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0666);

    if(fd < 0)
    {
        perror("Cant open file: ");
        return 2;
    }

    write(fd, FileHole, 1024);
    lseek(fd, 5*4096, SEEK_CUR);
    write(fd, FileHole, 1024);

    close(fd);

    return 0;
}
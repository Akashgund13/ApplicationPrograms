#include<stdio.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    int fd = 0;

    if(argc != 3)
    {
        printf("Insufficient number of arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to open the directory\n");
        return -1;
    }

    fd =  mkdir(argv[2], 0777);

    if(fd == -1)
    {
        printf("Unable to create the directory\n");
        return -1;
    }
    close(fd);
    close(dp);

    return 0;
}
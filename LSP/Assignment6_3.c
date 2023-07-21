#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;
    int fd = 0;
    char name[20];

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

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name, "%s/%s", argv[1], argv[2]);
        fd = creat(name, 0777);

        if(fd == -1)
        {
            printf("Unable to create the file\n");
            return -1;
        }
    }
    closedir(dp);
    

    return 0;
}
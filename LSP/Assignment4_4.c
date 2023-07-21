#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>

int main(int argc, char *argv[])
{
    struct stat sobj;
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

    fd = creat(argv[2], 0777);

    if(fd == -1)
    {
        printf("Unable to create the file\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name, "%s/%s", argv[1], entry->d_name);
        stat(name, &sobj);
        
        if(S_ISREG(sobj.st_mode))
        {
            strcpy(argv[2], entry->d_name);
            write(fd, argv[2], 10);
        }
    }
    closedir(dp);
    
    return 0;
}
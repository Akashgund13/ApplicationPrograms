#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    
    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        if(strcmp(argv[2], entry->d_name) == 0)
        {
            printf("File is present in the directory\n");
            break;
        }
    }
    
    if(entry == NULL)
    {
        printf("There is no such file\n");
        return -1;
    }
    
    closedir(dp);

    return 0;
}
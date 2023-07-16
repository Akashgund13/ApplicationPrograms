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
    char DirName[20];
    char Name[20];

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
        printf("%s\n", entry->d_name);
        sprintf(Name, "%s/%s", DirName, entry->d_name);

        if(strcmp(argv[2], entry->d_name) == 0)
        {
            break;
        }
    }
    
    fd = access(argv[2], O_RDONLY);
    
    if(fd == -1)
    {
        printf("File is not present\n");
    }
    else
    {
        printf("File is present\n");
    }
    
    closedir(dp);

    return 0;
}
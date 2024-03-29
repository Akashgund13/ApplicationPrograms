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
    char namecopy[30] = {'\0'};
    struct stat sobj;

    if(argc != 2)
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
        sprintf(name, "%s/%s", argv[1], entry->d_name);
        stat(name, &sobj);

        if(S_ISREG(sobj.st_mode))
        {
            if(sobj.st_size > 100)
            {
                remove(name);
            }
        }
    }

    closedir(dp);
    
    return 0;
}
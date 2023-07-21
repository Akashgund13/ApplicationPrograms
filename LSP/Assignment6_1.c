#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[30];
    struct stat sobj;
    int fd = 0;

    printf("Enter the name of directory name : ");
    scanf("%s", DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open the dirctory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s", DirName, entry->d_name);
        stat(name, &sobj);
        
        if(S_ISREG(sobj.st_mode))
        {
            if(sobj.st_size > 10)
            {
                printf("File name : %s File size : %ld\n", name, sobj.st_size);
            }
        }
    }

    closedir(dp);
    
    return 0;
}


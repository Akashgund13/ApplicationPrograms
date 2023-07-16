#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;
    struct stat sobj;

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to open the directory\n");
        return -1;
    }
    
    printf("------------------------------------------\n");
    printf("Entries from the directory files are : \n");
    printf("------------------------------------------\n");
    printf("\tFile Name\t File Type\n");

    while((entry = readdir(dp)) != NULL)
    {
        stat(entry->d_name, &sobj);
        printf("%20s : %c :", entry->d_name, entry->d_type);
        
        if(S_ISREG(sobj.st_mode))
        {
            printf("Its a reguler file\n");
        }
        else if(S_ISDIR(sobj.st_mode))
        {
            printf("Its a directory\n");
        }
        else if(S_ISLNK(sobj.st_mode))
        {
            printf("Its a symbolic link\n");
        }

    }

    printf("-----------------------------------------\n");

    
    return 0;
}
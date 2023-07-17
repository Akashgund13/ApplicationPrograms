#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char oldname[50];
    char newname[50];

    if(argc != 3)
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

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(oldname, "%s/%s", argv[1], entry->d_name);
        sprintf(newname, "%s/%s", argv[2], entry->d_name);

        rename(oldname, newname);
    }

    closedir(dp);

    return 0;
}
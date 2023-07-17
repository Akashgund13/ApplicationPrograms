#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

#pragma pack(1)

struct FileInfo
{
    char FileName[20];
    int FileSize;
};

int main(int argc, char *argv[])
{
    int fd = 0;
    char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[30];
    struct stat sobj;
    char namecopy[30] = {'\0'};
    int iMax = 0;
    struct FileInfo fobj;

    printf("Enter the name of directory name : \n");
    scanf("%s", DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open the dirctory\n");
        return -1;
    }

    fd = creat("FileCombine.txt", 0777);

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s", DirName, entry->d_name);
        stat(name, &sobj);
        if(S_ISREG(sobj.st_mode))
        {
            fobj.FileSize = sobj.st_size;
            strcpy(fobj.FileName, entry->d_name);
            write(fd, &fobj, sizeof(fobj));
        }
    }

    closedir(dp);
    
    return 0;
}
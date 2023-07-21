#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fd = 0;
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    char Buffer[BLOCKSIZE];
    int Ret = 0;

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

    printf("------------------------------------------------------\n");
    printf("\t File Name \t Inode Number \t File Type\n");
    printf("-------------------------------------------------------\n");

    while((entry = readdir(dp)) != NULL)
    {
        stat(entry->d_name, &sobj);
        printf("%20s : %d : %c ", entry->d_name, entry->d_ino, entry->d_type);

        if(S_ISDIR(sobj.st_mode))
        {
            printf("Its a directory\n");
        }
        else if(S_ISREG(sobj.st_mode))
        {
            printf("Its a regular file\n");
        }

        if(S_ISREG(sobj.st_mode))
        {
            fd = open(entry->d_name, O_RDONLY);
        
            ((Ret = read(fd, Buffer, sizeof(Buffer))) != 0);
            {
                write(1, Buffer, sizeof(Buffer));
                //memset(Buffer, 0, sizeof(Buffer));
            }

        }

        //close(ret);
    }


    closedir(dp);

    return 0;
}
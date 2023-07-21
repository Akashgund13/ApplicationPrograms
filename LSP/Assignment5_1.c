#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#pragma pack(1)

struct Student
{
    int RollNo;
    char sName[20];
    float Marks;
    int Age;
};

int main(int argc, char *argv[])
{
    struct Student sobj;
    char Fname[20];
    int fd = 0;
    int ret = 0;

    sobj.RollNo = 11;
    sobj.Marks = 89.99f;
    sobj.Age = 25;
    strcpy(sobj.sName, "Rahul");

    if(argc != 2)
    {
        printf("Insufficient number of argumants\n");
        return -1;
    }

    fd = creat(argv[1], 0777);

    if(fd == -1)
    {
        printf("Unable to create the file\n");
        return -1;
    }

    ret = open(argv[1], O_RDONLY);
    if(ret == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }

    write(ret, &sobj, sizeof(sobj));

    read(ret, &sobj, sizeof(sobj));

    printf("Roll number : %d \n", sobj.RollNo);
    printf("Name : %s  \n", sobj.sName);
    printf("Marks : %f  \n", sobj.Marks);
    printf("Age : %d  \n", sobj.Age);

    close(ret);

    return 0;
}
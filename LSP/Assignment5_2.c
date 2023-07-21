#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#pragma pack(1)

struct Employee
{
    int EmployeeID;
    char sName[20];
    int Experience;
    float Salary;
};

int main(int argc, char *argv[])
{
    struct Employee eobj;
    char Fname[20];
    int fd = 0;
    int ret = 0;

    eobj.EmployeeID = 13;
    eobj.Experience = 2;
    eobj.Salary = 7.5f;
    strcpy(eobj.sName, "Akash");

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

    write(ret, &eobj, sizeof(eobj));

    read(ret, &eobj, sizeof(eobj));

    printf("Employee ID : %d \n", eobj.EmployeeID);
    printf("Name : %s  \n", eobj.sName);
    printf("Experience : %d Years  \n", eobj.Experience);
    printf("Salary : %f Lakh  \n", eobj.Salary );

    close(ret);

    return 0;
}
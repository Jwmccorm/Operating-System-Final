//PRABHJOT SINGH
//0860228

#include<iostream>
#include<stdio.h>
#include<conio.h>

int main()
{

    int status;
    char file_name[100];

    printf("\nPlease Mention the File to Delete :");
    gets(file_name);

    status = remove(file_name);

    if(file_name==0)
    {
        printf("\n File is Deleted Suxessfully ");

    }
    else
        printf("\nDid you Entered the Right File Name !");
    return 0;

}


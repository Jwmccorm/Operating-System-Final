//PRABHJOT SINGH
//0860228

#include<iostream>
#include<stdio.h>
#include<iostream>
#include<string>
#include<conio.h>

using namespace std;


string deleteFile(string command, string directoryString){
    if (!command.compare("-h")){
        return "To use the delete command:  \"delete file.extension\"";
    }
    int status;
    char file_name[100];
    string fileAndExtention = directoryString  +"\\"+ command;
    status = remove(fileAndExtention.c_str());

    if(file_name==0)
    {
        printf("\n File is Deleted Successfully ");

    }
    else
        return "File is Not Found, Unable To Delete";
}

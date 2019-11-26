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
        string fileAndExtention = directoryString  +"\\"+ command;

        FILE *file = fopen((fileAndExtention).c_str(), "r");
   if(!file){
            return "Unable to find file - Use  \"copy -h\" for help!\n";
        }
    else{
           fclose(file);

    }
    char file_name[100];


    status = remove(fileAndExtention.c_str());

    if(file_name==0)
    {
        return "Unable to locate file";
    }
    else
        return "File has been deleted";
}

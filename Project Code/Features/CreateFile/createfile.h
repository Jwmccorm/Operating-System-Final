#include<iostream>
#include<iostream>
#include <fstream>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
using namespace std;


string createFile(string command, string path){
    if (!command.compare("-h")){
        return "How to use create file command:  \"create file.extension\"";
    }
    else if(command.find('.') == string::npos){
        return "Invalid use of copy file, needs file extension. Use -h for help";
    }

    DIR *dr = opendir(path.c_str());
    struct dirent *de;
    int duplicateFound = 0;
    while ((de = readdir(dr)) != NULL){
        string names = de->d_name;
        if (!names.compare(command)){
            duplicateFound = 1;
        }
    }

    if(duplicateFound){
        return "File exist with that name. Use \"dir\" to see the directory or create -h";
    }

    FILE * pFile;
    pFile = fopen ((path + "\\"+ command).c_str(),"w");
    if (pFile!=NULL){
        fputs ("",pFile);
        fclose (pFile);
    }
    else{
        cout << "Invalid creation of file";
      }
    return "The file "+ command +" has been created!";
}

#pragma once
#include<iostream>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int validDir(DIR *dr){
    if (dr == NULL){
        cout << "Invalid Directory Change\n";
        return 0;
    }
    return 1;
}
string current_working_directory()
{
    char* cwd = _getcwd( 0, 0 ) ; // **** microsoft specific ****
    string working_directory(cwd) ;
    free(cwd) ;
    return working_directory ;
}


void listDir(DIR *dr){
    struct dirent *de;  // Pointer for directory entry
    while ((de = readdir(dr)) != NULL){
        string names = de->d_name;
        if (names.find('.') == string::npos || !names.compare(".") || !names.compare("..")){
            cout << "<DIR>    " << de->d_name <<endl;
        }else{
            cout << "         " << de->d_name << endl;

        }
    }
}

string directoryChange(string remainder, string directoryString){
    if (!remainder.compare("..")){
        directoryString = directoryString.substr(0, directoryString.find_last_of("\\"));
        DIR *dr = opendir(directoryString.c_str());
        return directoryString;
    }
    else{
        DIR *dd = opendir((directoryString + "\\"+remainder).c_str());
        if(validDir(dd)){
            directoryString += "\\"+remainder;
            DIR *dr = opendir(directoryString.c_str());
        }

    }
    return directoryString;

}

void changeDirectory(string directoryString){
        DIR *dr = opendir(directoryString.c_str());
        listDir(dr);
}

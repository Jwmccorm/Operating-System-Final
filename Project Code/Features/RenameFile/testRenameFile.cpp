#include<iostream>
#include "renamefile.h"

using namespace std;

int main(){
    cout << "Tek Subedi ID 0869016" <<endl;
    cout << "Killer Group" <<endl;
    int counter = 0, i;
     // pointer to directory
    DIR *currentWorkingDir;

    // structure which has field char d_name[]
    struct dirent *directoryReading;
    // array to hold the current path info
    char dirPath[100];
    string path;

    //opening the current working directory so that we can use readdir fun to read
    currentWorkingDir = opendir("./");
    // checking if the current dir is empty or getcwd returns null ie no file
    if (currentWorkingDir!= NULL && getcwd(dirPath, sizeof(dirPath)) !=NULL)
    {
        // printing info about dir and existing files in it
        cout<< "We are in the following directory :\n"<<dirPath<<endl;
        cout<< "The existing files in this directory are : "<<endl;
        //reading and printing all the files on the screen
        directoryReading = readdir(currentWorkingDir);

        while(directoryReading != NULL)
        {
            cout<<counter <<" "<<directoryReading->d_name<<endl;
            counter++;
            // reading next entry in the directory
            directoryReading = readdir(currentWorkingDir);
        }
        // closing the current directory after done reading
        closedir(currentWorkingDir);

    }
    else
        cout<<"Directory not found. "<<endl;

    cout<<"The path is "<<dirPath<<endl;
    for(i = 0; i<strlen(dirPath); i++)
    {
        path = path + dirPath[i];
    }
    cout<<"str path is "<<path<<endl;
    renameFile(" ", path);
    return 0;
}


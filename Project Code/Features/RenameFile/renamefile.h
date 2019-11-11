
#include<iostream>
#include<dirent.h>
#include<stdlib.h>
#include <cstring>
using namespace std;

int myRename(char curName[], char nName[])
{
    int i;
    for(int i = 0; i<strlen(curName); i++)
    {
        if(i<strlen(nName))
            curName[i] = nName[i];
        else
            curName[i] = '\0';
    }
    cout<<curName<<endl;
    cout<<nName<<endl;
    if(strcmp(curName, nName) == 0)
    {
        return 0;
    }
    else
        return -1;

}

// function to rename the desired file in the current directory
void renameFile()
{
    // local declarations and assignments
     int counter = 0, tempValue, tempInt, index = 30;
     char tempArray[index], temp1[index];
    // pointer to directory
    DIR *currentWorkingDir;
    // structure which has field char d_name[]
    struct dirent *directoryReading;
    // array to hold the current path info
    char dirPath[100];
    // arrays to hold current name and new name
    char currentName[index],newName[index];
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

    // prompt to user to give the name of the file they wish to rename
    cout<<"Please enter the name of the file you wish to rename."<<endl;
    cin>>currentName;
    // access return is -ve, i.e. file doesn't exist
    while(access(currentName, 0)== -1)
        {
            cout<< currentName<<" The file does not exist.\nPlease enter valid file name to continue OR \nEnter Return to go back to main menu.\n"<<endl;
            cin>>currentName;
            // return if user want to return
            if (strcmp(currentName,"Return")==0)
                return;
            }
    // if file exists then renaming
    if(access(currentName, 0)!= -1)
    {
        cout<<"Please enter the new name for the file named "<<currentName<<endl;
        cin>>newName;
        //if acess return is not -ve i.e. this file name already exists in the dir so getting another desired name
         while(access(newName, 0)!= -1)
            {
                cout<<newName<<" already exists.\nPlease enter valid file name to continue OR \nPlease Enter Return to go back to main menu."<<endl;
                cin>>newName;
                // return if user want to return
                if ((strcmp(newName,"Return"))==0)
                    return;
            }
        // storing return value of rename function
        tempInt = rename(currentName, newName);
        /*
        //tempInt = myRename(currentName, newName);----- my rename is not working why
        //?????????????????????????????????
        OR even here without calling function name

    for(int i = 0; i<strlen(currentName); i++)
    {
        if(i<strlen(newName))
            currentName[i] = newName[i];
        else
            currentName[i] = '\0';
    }
    cout<<currentName<<endl;
    cout<<newName<<endl;
    if(strcmp(currentName, newName) == 0)
    {
        tempInt = 0;
    }
    else
        tempInt = -1;
        */

        // if tempInt is 0, i.e. file successfully renamed
        if(tempInt == 0)
        {
            cout<< currentName << "file is successfully renamed to " <<newName<<endl;
            cout<< "Please Enter Return to go back to main menu."<<endl;
            cin>>tempArray;
            // for catching the invalid return entry
            tempInt = (strcmp(tempArray, "Return"));
            while(tempInt!= 0)
            {
                cout<<"Invalid entry, Please enter Return to go back to main menu. "<<endl;
                cin>>tempArray;
                tempInt = (strcmp(tempArray, "Return"));
            }
            // retrun when the user enters Return
            if(tempInt == 0)
                return;
        }

    }
}

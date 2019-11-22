
#include<iostream>
#include<dirent.h>
#include<stdlib.h>
#include <cstring>
#include<string>

using namespace std;

// function returning the extension of the file dot inclusive
string checker(string curName)
{
    // local declarations and assignments
    int i, temp, tempIndex, dotCount =0 ;
    string str;
    // for loop to find the the last dot that is the starting of extension
    for(int i = 0; i< curName.length(); i++)
    {
        // finds the dot and saves the index of the last dot in temp
        if(int(curName[i])== 46)
        {
            temp = i;
        }
    }
    // storing the extension in the string called str
    for(i = temp; i<curName.length(); i++)
    {
        str = str + curName[i];
    }
    return str;
}
// assigning the old extension if user puts the new extension as extension can't be changed
void keepExtension(char curName[], string oldExtension)
{
    // local declaration and assignments
    int i, temp, j =0;
    int n = oldExtension.length();
    char tempAr[n];
    // copying the string into array
    strcpy(tempAr, oldExtension.c_str());
    // putting the original extension to the new file name
    for(i = strlen(curName); i<(strlen(curName) + n); i++)
    {
        curName[i] = tempAr[j++];
    }
    cout<<"making sure that original extension is added to new name "<<curName<<endl;
}
// removing the extension if user entered
void removeExt(char curName[])
{
    int i, temp ;
    for(i = 0; i<strlen(curName); i++)
    {
        if(int(curName[i])== 46)
        {
            temp = i;
        }
    }
    // removing the extension
    for(i = temp; i<strlen(curName); i++)
    {
        curName[i] = '\0';
    }
}

// function to rename the desired file in the current directory
string renameFile(string command, string path)
{

        bool complete;
        string originalFileName;
        string originalFileExtention;
        string newFileName;
        int counter = 0;
        int spaceCount= 0;
        int dotCount = 0;
    int i =0;
        for (i = 0; i < command.length(); i++){
            if (command[i] == ' '){
                spaceCount += 1;
                continue;
            }

            if (dotCount > 1){
                return "Too many dots!! use -h for help";
            }
            if (command[i] == '.'){
                dotCount += 1;
            }
            if (spaceCount > 1){
                return "Too many spaces, sorry please use -h for help";
            }
            if(spaceCount ==0 && dotCount == 0){
                originalFileName += command[i];
            }
            if (spaceCount == 0 && dotCount == 1){
                originalFileExtention += command[i];
            }
            if(spaceCount == 1){
                newFileName += command[i];
            }
        }

        //      Take this
        string originalFileNameNameAndExt = path + "\\"+originalFileName + originalFileExtention;


        string newFileNameNameAndExt = path + "\\"+newFileName + originalFileExtention;

        /// THIS IS THE ONE WITH THE PATH . FILE NAME and EXT (OF THE OLD ONE)
        cout << originalFileNameNameAndExt<< endl;

        /// THIS IS THE NEW FILE NAME
        cout << newFileNameNameAndExt << endl;



    // local declarations and assignments
    int tempInt, index = 30;
    if (!command.compare("-h")){
        return "To use the rename command:  \" file.extension then newname\"";
    }
    char tempArray[index], temp1[index];
    // arrays to hold current name and new name
    char currentName[index],newName[index];
    // string for current and new name
    string cName, nName;
    // string to hold old and new(if user enters) extension
    string cExtension, nExtension;

    // prompt to user to give the name of the file they wish to rename
    cout<<"Please enter the name of the file you wish to rename."<<endl;
    ///cin>>currentName;
    // saving the old extension to be used for new name
    cExtension = checker(currentName);
    // access return is -ve, i.e. file doesn't exist


    /*while(access(currentName, 0)== -1)
        {
            cout<< currentName<<" The file does not exist.\nPlease enter valid file name to continue OR \nEnter Return to go back to main menu.\n"<<endl;
            cin>>currentName;
            // saving the old extension to be used for new name
            cExtension = checker(currentName);
            // return if user want to return
            if (strcmp(currentName,"Return")==0)
                return "";
            }
    // if file exists then renaming
    if(access(currentName, 0)!= -1)
    {
        cout<<"Please enter the new name for the file named "<<currentName<<endl;
        cin>>newName;
        // disregarding user's extension
        removeExt(newName);
        // keeping the original extension
        keepExtension(newName, cExtension);

        //if acess return is not -ve i.e. this file name already exists in the dir so getting another desired name
         while(access(newName, 0)!= -1)
            {
                cout<<newName<<" already exists.\nPlease enter valid file name to continue OR \nPlease Enter Return to go back to main menu."<<endl;
                cin>>newName;
                // disregarding user's extension
                removeExt(newName);
                // keeping the original extension
                keepExtension(newName, cExtension);
                // return if user want to return
                if ((strcmp(newName,"Return"))==0)
                    return "";
            }
        // storing return value of rename function
        tempInt = rename(currentName, newName);

        // if tempInt is 0, i.e. file successfully renamed
        if(tempInt == 0)
        {
            cout<< currentName << "File is successfully renamed to  " <<newName<<endl;
            cout<< "Please Enter Return to go back to main menu."<<endl;
            cin>>tempArray;
            // for catching the invalid return entry
            tempInt = (strcmp(tempArray, "Return"));
            while(tempInt!= 0)
            {
                cout<<"Invalid entry, Please enter Return to go back to main menu."<<endl;
                cin>>tempArray;
                tempInt = (strcmp(tempArray, "Return"));
            }
            // retrun when the user enters Return
            if(tempInt == 0)
                return "";
        }

    }*/
    return " ";
}


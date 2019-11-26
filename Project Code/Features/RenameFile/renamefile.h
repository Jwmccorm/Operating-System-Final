
#include<iostream>
#include<dirent.h>
#include<stdlib.h>
#include <cstring>
#include<string>

using namespace std;

// function to rename the desired file in the current directory
string renameFile(string command, string path)
{
    //local declarations and assignments
    int tempInt;
    string originalFileName;
    string originalFileExtention;
    string newFileName;
    int spaceCount= 0;
    int dotCount = 0;
    int i =0;
    // for loop to count the dots, space
    for (i = 0; i < command.length(); i++)
    {
        if (command[i] == ' ')
        {
            // increment spaceCount is there is space
            spaceCount += 1;
            continue;
        }
        // if the dotcount is more than 1, display the messasge to use help
        if (dotCount > 1)
        {
            return "Too many dots!! use -h for help";
        }
        if (command[i] == '.')
        {
            // if ith element of command is dot, increment dotcount
            dotCount += 1;
        }
        // if the space count is greater than 1, display message saying too much space, ask to use help
        if (spaceCount > 1)
        {
            return "Too many spaces, sorry please use -h for help";
        }
        // if no space and no dot put the character into the original file name
        if(spaceCount ==0 && dotCount == 0)
        {
            originalFileName += command[i];
        }
        // if no space and dot is one then save the extension
        if (spaceCount == 0 && dotCount == 1)
        {
            originalFileExtention += command[i];
        }
        // is space is one then , new file = command[i]
        if(spaceCount == 1)
        {
            newFileName += command[i];
        }
    }
    //original and new file names with path and extension
    string originalFileNameWithExt = path + "\\"+originalFileName + originalFileExtention;
    string newFileNameWithExt = path + "\\"+newFileName + originalFileExtention;
    // storing return value of rename function
    tempInt = rename(originalFileNameWithExt.c_str(), newFileNameWithExt.c_str());
    // if tempInt is 0 i.e. rename is successful, print the success message
    if(tempInt == 0)
    {
        cout<<"Rename Successful"<<endl;
    }

    return " ";

}

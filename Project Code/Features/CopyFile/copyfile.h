#include<iostream>
#include<string>
#include <fstream>
using namespace std;


string copyFile(string command){
    int i;
    if (!command.compare("\h")){
        return "To use the copy command:  \"copy file.extention CopyName\"";
    }
    else{

        bool complete;
        string originalFileName;
        string originalFileExtention;
        string newFileName;
        int counter = 0;
        int spaceCount= 0;
        int dotCount = 0;

        for (i = 0; i < command.length(); i++){
            if(command[i] == '.'){
                dotCount+= 1;
            }
            if (command[i] == ' '){
                spaceCount += 1;
                continue;
            }
            if(dotCount == 1 && spaceCount != 1){
                originalFileExtention += command[i];
            }
            if(dotCount ==0 && spaceCount ==0){
                originalFileName += command[i];
            }
            if(dotCount == 1 && spaceCount == 1){
                newFileName += command[i];
            }
        }

        if (spaceCount != 1){
            return "ERROR: New File Name Can Not Contain Spaces!";
        }
        else if (!originalFileName.compare(newFileName)){
                cout << originalFileName<<endl;
            cout << newFileName << endl;
            cout << originalFileName.compare(newFileName);
            return "ERROR: The two files can not have the same name!";
        }
        else{
            originalFileName.append(originalFileExtention);
            newFileName.append(originalFileExtention);

            //TODO: Change the finished file that was appended to a string stream
            ifstream  src("test.txt", ios::binary);
            ofstream  dst("swag.txt",   ios::binary);
            dst << src.rdbuf();
            return originalFileName + " now has a copy called " + newFileName;

        }

    }
}

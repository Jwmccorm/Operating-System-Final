#include<iostream>
#include<string>
#include <fstream>
using namespace std;


string copyFile(string command, string directoryString){
    int i;
    if (!command.compare("-h")){
        return "To use the copy command:  \"copy file.extension CopyName\"";
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

        if (spaceCount == 0){
            return "ERROR: Must contain a space to separate copy file name - Use \"copy -h\" for help!";
        }
        else if(spaceCount > 1){
            return "ERROR: Only one space allowed for file names - Use  \"copy -h\" for help!";
        }
        else if (!originalFileName.compare(newFileName)){
            return "ERROR: The two files can not have the same name! - Use  \"copy -h\" for help!";
        }
        else{
            originalFileName =  directoryString +  "\\"+ originalFileName + originalFileExtention;
            newFileName= directoryString + "\\"+ newFileName + originalFileExtention;
            cout << newFileName << endl;
            ifstream  src(originalFileName.c_str(), ios::binary);
            ofstream  dst(newFileName.c_str(),   ios::binary);
            dst << src.rdbuf();
            return "";//originalFileName + " now has a copy called " + newFileName << endl;

        }

    }
}

#include <iostream>
#include <dirent.h>
#include <string>
#include <cstring>
#include "../Features/Directory/directory.h"

using namespace std;

string moveFile(string command, string path){

    if(!command.compare("-h")) {
        return "To use the move command: \"move file.extension \"\nThen cd to destination directory...\n";
    }

    int i = 0;
    string originalFileName;
    string originalFileExtention;
    string fileName;
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
    }
    fileName = originalFileName + originalFileExtention;

    if (spaceCount == 0){
        return "ERROR: Must contain a space to separate file name - Use \"move -h \" for help!\n";
    }
    else if (dotCount == 0) {
        return "ERROR: Must specify the file's extension - Use \"move -h \" for help!\n";
    }
    else if(spaceCount > 1){
        return "ERROR: Only one space allowed for file names - Use  \"move -h \" for help!\n";
    }
    else{
        cout << "\t1. Navigate to where you'd like to move the file: using for example \"cd ..\"" << endl;
        cout << "\t2. Enter \"here\" to complete operation or" << endl;
        cout << "\t   Enter \"cancel\" to cancel operation" << endl;

        string localPath = path;
        DIR *dr = opendir(localPath.c_str());
        string userInput = "";
        string action = "";
        string remainder = "";

        while(1) {
            action = "";
            remainder = "";
            cout << localPath + ">";

            getline(cin, userInput);
            action = userInput.substr(0, userInput.find(' '));
            remainder = userInput.substr(userInput.find(' ')+1, userInput.find('\0'));

            if (!action.compare("cd"))  localPath = directoryChange(remainder, localPath);
            else if (!action.compare("dir")) changeDirectory(localPath);
            else if (!action.compare("-h")) {
                cout << "\t1. Navigate to where you'd like to move the file: using for example \"cd ..\"" << endl;
                cout << "\t2. Enter \"here\" to complete operation or" << endl;
                cout << "\t   Enter \"cancel\" to cancel operation" << endl;
            }
            else if (!action.compare("cancel")) return "Operation Cancelled\n";
            else if (!action.compare("here")) {
                /*
                    The copying and the pasting of the file
                */
                string newFileName = localPath + "\\"+ originalFileName + originalFileExtention;
                ifstream  src((path + "\\" + fileName).c_str(), ios::binary);
                ofstream  dst(newFileName.c_str(), ios::binary);
                dst << src.rdbuf();
                cout << "file moved successfully\n";
                break;
            }
            else{
                cout << "Invalid Command, use \"-h\" for help!" << endl;
            }
        }
        /*
            Afterwards we need to delete the file that was moved from the original directory
        */
        char* moveFile = strcpy(moveFile, fileName.c_str());
        if (!remove(moveFile)) {
            return "";
        }
        else {
            return "Error";
        }
    }
}

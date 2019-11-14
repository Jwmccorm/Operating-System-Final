#include<iostream>
#include <dirent.h>
#include "../Features/Directory/directory.h"

using namespace std;

string moveFile(string command, string path){

    if(!command.compare("-h")) {
        return "\tTo use the move command: \"move file.extension\"\n\tThen cd to destination directory...\n";
    }

    int i = 0;
    string originalFileName;
    string originalFileExtention;
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
    if (spaceCount == 0){
        return "ERROR: Must contain a space to separate file name - Use \"move -h\" for help!";
    }
    else if(spaceCount > 1){
        return "ERROR: Only one space allowed for file names - Use  \"move -h\" for help!";
    }

    else{
        cout << "Navigate to where you'd like to move the file..." << endl;
        cout << "Enter \"here\" to complete operation" << endl;

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
            else if (!action.compare("/h")) cout << "\"Some help\"";
            else if (!action.compare("here")) {
                    /*
                            The copying and the pasting of the file will go here
                    */
                return "file moved\n";
            }
            else{
                cout << "Invalid Command, you need spaces, use /h for help";
            }
        }

        /*
                Afterwards we need to delete the file that was moved from the original directory
        */
    }
}

    //changeDirectory(path);
//    char[BUFFER] destination;
//    char[BUFFER] fileName;

//    cout << "Destination path: " << endl;
//    cin >> destination;
//    cout << "File: " << endl;
//    cin >> fileName;
//
//    dirp = opendir(".");
//
//    while (dirp) {
//        errno = 0;
//        if ((dp = readdir(dirp)) != NULL) {
//            if (strcmp(dp->d_name, name) == 0) {
//                closedir(dirp);
//                return FOUND;
//            }
//        } else {
//            if (errno == 0) {
//                closedir(dirp);
//                return NOT_FOUND;
//            }
//            closedir(dirp);
//            return READ_ERROR;
//        }
//    }
//
//    return OPEN_ERROR;
//}

#include <iostream>
#include <dirent.h>
#include <string>
#include <cstring>
#include "../Features/Directory/directory.h"

using namespace std;

/**
 * Move file function - By: Nicholas Pinney
 * Accepts 2 strings; 1 a command (e.g. -h or the filename), and the other is the current path/location in the system.
 * This function is used by passing a file as a command then navigate to the directory you wish to move the file to, then move it there.
 */
string moveFile(string command, string path)
{

    //Print out help text if command is -h
    if(!command.compare("-h")) {
        return "To use the move command: \"move file.extension \"\nThen cd to destination directory...\n";
    }

    //Some variables to store file name along with some if its properties for error checking
    int i = 0;
    string originalFileName;
    string originalFileExtention;
    string fileName;
    int spaceCount= 0;
    int dotCount = 0;

    //Loop that itterates over the command (filename) to count the numbers of dots to get the correct file extension
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
    //Store the full filename for use later
    fileName = originalFileName + originalFileExtention;

    //return error if there is no file extension...
    if (dotCount == 0) {
        return "ERROR: Must specify the file's extension - Use \"move -h \" for help!\n";
    }
    //and if there is more than one space in front of the command
    else if(spaceCount > 1){
        return "ERROR: Only one space allowed for file names - Use  \"move -h \" for help!\n";
    }
    //if conditions are satisfied, then allow the user to move to the directory of choice...
    else
    {
        //Instructions:
        cout << "\t1. Navigate to where you'd like to move the file: using for example \"cd ..\"" << endl;
        cout << "\t2. Enter \"here\" to complete operation or" << endl;
        cout << "\t   Enter \"cancel\" to cancel operation" << endl;

        //Variable to hold the path during each directory change
        string localPath = path;
        DIR *dr = opendir(localPath.c_str());
        //Empty strings to hold the user input
        string userInput = "";
        string action = "";
        string remainder = "";

        //loop to give user functionality of navigating to directory of choice ("sub system")
        while(1)
        {
            //resetting the input to 0
            action = "";
            remainder = "";
            //displaying the current path the user is in
            cout << localPath + ">";

            //get the input of the user...
            getline(cin, userInput);
            //Extract the action and remainder of the command (e.g.: "cd" -> action ".." -> remainder)
            action = userInput.substr(0, userInput.find(' '));
            remainder = userInput.substr(userInput.find(' ')+1, userInput.find('\0'));

            //The actions to perform based on the input of the user
            if (!action.compare("cd"))  localPath = directoryChange(remainder, localPath); //change directory
            else if (!action.compare("dir")) changeDirectory(localPath); //display directory
            else if (!action.compare("-h")) { //print help
                cout << "\t1. Navigate to where you'd like to move the file: using for example \"cd ..\"" << endl;
                cout << "\t2. Enter \"here\" to complete operation or" << endl;
                cout << "\t   Enter \"cancel\" to cancel operation" << endl;
            }
            else if (!action.compare("cancel")) return "Operation Cancelled\n"; //cancel the operation
            else if (!action.compare("here")) { //move the file here
                //string representing the new path of the file
                string newFileName = localPath + "\\"+ originalFileName + originalFileExtention;
                //The next 2 lines are used to copy the contents of the original file into a new file
                ifstream  src((path + "\\" + fileName).c_str(), ios::binary);
                ofstream  dst(newFileName.c_str(), ios::binary);
                dst << src.rdbuf();
                cout << "file moved successfully\n";
                break; //break once the requested destination has been selected and a new file created
            }
            else{
                cout << "Invalid Command, use \"-h\" for help!" << endl;
            }
        }
        //Afterwards we need to delete the file from the original directory
        char* moveFile = strcpy(moveFile, fileName.c_str());
        if (!remove(moveFile)) {
            return "";
        }
        else {
            return "Error";
        }
    }
}

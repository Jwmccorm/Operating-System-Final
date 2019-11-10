#include <iostream>
#include "../Features/CopyFile/copyfile.h"
#include "../Features/CreateFile/createfile.h"
#include "../Features/DeleteFile/deletefile.h"
#include "../Features/MoveFile/movefile.h"
#include "../Features/RenameFile/renamefile.h"
#include "../Features/Directory/directory.h"
#include "../Features/TextModification/textmodification.h"
#include <dirent.h>


using namespace std;



int main(){
    /*
        This fist section is just for user input of the string
    */
    cout << "Welcome! Please Input Instructions" << endl;
    string directoryString = current_working_directory();
    DIR *dr = opendir(directoryString.c_str());
    string command;
    string remainder;
    string userInput;

    while(1){
        command = "";
        remainder = "";
        cout << directoryString + ">";

        //      Catching help command off of root
        getline(cin, userInput);

        if (!userInput.compare("-h")){
            cout << "THIS WILL DISPLAY THE HELP OPTIONS";
            continue;
        }
        else if(!userInput.compare("exit")){
            break;
        }
        else if (userInput.find(' ') == string::npos){
            if(!userInput.compare("dir")){
                command = "dir";
            }else{
                cout << "Invalid Command, you need spaces, use /h for help";
                continue;
            }
        }else{
            command = userInput.substr(0, userInput.find(' '));
            remainder = userInput.substr(userInput.find(' ')+1, userInput.find('\0'));
        }

        /*
            Bulk of the information for the problem it self, use this to link up commands.
        */
        if  (!command.compare("copy")) cout << copyFile(remainder, directoryString);
        else if (!command.compare("delete")) deleteFile();
        else if (!command.compare("move")) moveFile();
        else if (!command.compare("rename")) renameFile();
        else if (!command.compare("modify")) textModification();
        else if (!command.compare("-h"));
        else if (!command.compare("cd"))  directoryString = directoryChange(remainder, directoryString);
        else if (!command.compare("dir")) changeDirectory(directoryString);
        else{
            cout << "Invalid Command, you need spaces, use /h for help";
        }

    }

}

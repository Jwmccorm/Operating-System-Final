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
    cout << "Welcome! Please Input Instructions. Type -h for help" << endl;
    string path = current_working_directory();
    DIR *dr = opendir(path.c_str());
    string command;
    string remainder;
    string userInput;

    while(1){
        command = "";
        remainder = "";
        cout << path + ">";

        //      Catching help command off of root
        getline(cin, userInput);
        if (!userInput.compare("cat")) {
            printCat();
            command = "cat";
        }
        else if (!userInput.compare("-h")){
            cout << "\nThank you for asking for help! Here are the valid commands\n" << endl;
            cout << copyFile("-h", path) +"\n"<< endl;
            cout << deleteFile("-h", path) +"\n"<< endl;
            cout << moveFile("-h", path) << endl;
            cout << createFile("-h", path) +"\n"<< endl;
            cout << renameFile("-h", path)+"\n" << endl;
            cout << textModification("-h", path) +"\n" << endl;
            cout << "To list folders and files use \"dir\"" <<endl;
            cout << "To go up a directory use \"cd ..\"" <<endl;
            cout << "To change to a specific folder us \"cd FOLDERNAME\"\n" <<endl;
            continue;
        }
        else if(!userInput.compare("exit")){
            break;
        }
        else if (userInput.find(' ') == string::npos){
            if(!userInput.compare("dir")){
                command = "dir";
            }else{
                cout << "Invalid Command, you need spaces, use /h for help" << endl;
                continue;
            }
        }else{
            command = userInput.substr(0, userInput.find(' '));
            remainder = userInput.substr(userInput.find(' ')+1, userInput.find('\0'));
        }

        /*
            Bulk of the information for the problem it self, use this to link up commands.
        */
        if  (!command.compare("copy")) cout << copyFile(remainder, path);
        else if (!command.compare("delete"))cout << deleteFile(remainder, path) << endl;
        else if (!command.compare("move")) cout << moveFile(remainder, path);
        else if (!command.compare("create")) cout << createFile(remainder, path) << endl;
        else if (!command.compare("rename")) cout << renameFile(remainder, path) << endl;
        else if (!command.compare("modify")) cout << textModification(remainder, path) << endl;
        else if (!command.compare("-h") || !command.compare("cat"));
        else if (!command.compare("cd"))  path = directoryChange(remainder, path);
        else if (!command.compare("dir")) changeDirectory(path);
        else{
            cout << "Invalid Command, you need spaces, use /h for help" << endl;
        }

    }

}

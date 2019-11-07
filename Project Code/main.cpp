#include <iostream>
#include "../Features/CopyFile/copyfile.h"
#include "../Features/CreateFile/createfile.h"
#include "../Features/DeleteFile/deletefile.h"
#include "../Features/MoveFile/movefile.h"
#include "../Features/RenameFile/renamefile.h"
#include "../Features/TextModification/textmodification.h"


using namespace std;

int main(){
    /*
        This fist section is just for user input of the string
    */
    cout << "Welcome! Please Input Instructions" << endl;

    while(1){
        cout << endl;
        string userInput;
        //      Catching help command off of root
        getline(cin, userInput);
        string command,remainder;
        if (!userInput.compare("-h")){
            cout << "THIS WILL DISPLAY THE HELP OPTIONS";
            continue;
        }
        else if(!userInput.compare("exit")){
            break;
        }
        else if (userInput.find(' ') == string::npos){
            cout << "Invalid Command, you need spaces, use /h for help";
            continue;
        }else{
            command = userInput.substr(0, userInput.find(' '));
            remainder = userInput.substr(userInput.find(' ')+1, userInput.find('\0'));
        }

        /*
            Bulk of the information for the problem it self, use this to link up commands.
        */
        if  (command == "copy") cout << copyFile(remainder);
        else if (command == "delete") deleteFile();
        else if (command == "move") moveFile();
        else if (command == "rename") renameFile();
        else if (command == "modify") textModification();
        else if (command == "-h");
        else{
            cout << "Invalid Command, you need spaces, use /h for help";
        }

    }

}

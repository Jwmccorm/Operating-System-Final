#include<iostream>
#include "../Features/CopyFile/copyfile.h"
#include "../Features/CreateFile/createfile.h"
#include "../Features/DeleteFile/deletefile.h"
#include "../Features/MoveFile/movefile.h"
#include "../Features/RenameFile/renamefile.h"
#include "../Features/TextModification/textmodification.h"


using namespace std;

int main(){

    string command,remainder;

    cout << "Welcome! Please Input Instructions" << endl;

    //      Catching help command off of root
    cin >> command;
    if (command != "\\h"){
        cin >> remainder;
    }

    //      Commands switch statement (No switch statement for strings)
    if  (command == "copy") copyFile();
    else if (command == "delete") deleteFile();
    else if (command == "move") moveFile();
    else if (command == "rename") renameFile();
    else if (command == "modify") textModification();
    else if(command == "\\h"){
        cout << "HELP";
    }

    else{
        cout << "Invalid Command use \"\\h\" for help";
    }

}

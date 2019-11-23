#include<iostream>
using namespace std;


string textModification(string command, string path){
        if (command == "-h"){

            cout << "This is the help options\n Use append command to add text. \n Use insert command to add text at a particular location.\n Use remove command to clear the file.\n Use Display command to display the content of the file";
        }
        bool complete;
        string commandCatcher;
        string textFileName;
        int counter = 0;
        int spaceCount= 0;
        int dotCount = 0;
    int i =0;
        for (i = 0; i < command.length(); i++){
            if (command[i] == ' '){
                spaceCount += 1;
                continue;
            }
            if (spaceCount > 1){
                return "Invalid spaces! Only one allowed. Use -h for help";
            }
            if (dotCount > 1){
                return "Too many dots!! use -h for help";
            }
            if (command[i] == '.'){
                dotCount += 1;
            }
            if (spaceCount > 1){
                return "Too many spaces, sorry please use -h for help";
            }
            if(spaceCount ==0 && dotCount == 0){
                commandCatcher += command[i];
            }
            if (spaceCount == 1){
                textFileName+= command[i];
            }
        }
        cout << commandCatcher << endl;

        textFileName = path + "\\" + textFileName;
        cout << textFileName<< endl;

        return " ";
}

#include<iostream>
using namespace std;
#include <cstdlib>

#include<string>
string textModification(string command, string path){
        if (command == "-h"){//check if user asked for help

            return  "Use append: \"modify append fileName.extension\"\nUse insert: \"modify insert fileName.extension\"\nUse remove: : \"modify remove fileName.extension\"\nUse Display : : \"modify display fileName.extension\"";//some of the commands used in the program
        }
        bool complete;
        string commandCatcher;//just to check for commands
        string textFileName;//takes in the file we are working on
        int counter = 0;
        int spaceCount= 0;//used for counting number of spaces in the input
        int dotCount = 0;//used for counting the number of dots in the input
    int i =0;
        for (i = 0; i < command.length(); i++){//looping till the length of commands
            if (command[i] == ' '){//check for empty space or no commands
                spaceCount += 1;//increment the number of spaces
                continue;
            }
            if (spaceCount > 1){//error detection for more than 1 space
                return "Invalid spaces! Only one allowed. Use -h for help";//returns tahts its invalid
            }
            if (dotCount > 1){//checks for more than 1 dots in the input
                return "Too many dots!! use -h for help";//returns invalid
            }
            if (command[i] == '.'){
                dotCount += 1;
            }
            if (spaceCount > 1){
                return "Too many spaces, sorry please use -h for help";
            }
            if(spaceCount ==0 && dotCount == 0){//if no space and no dots then take the command
                commandCatcher += command[i];
            }
            if (spaceCount == 1){//for exact 1 space
                textFileName+= command[i];
            }
        }

        textFileName = path + "\\" + textFileName;//add the path to the text file

        FILE *file = fopen((textFileName).c_str(), "r");
            if(!file){
            return "Unable to find file - Use  \"copy -h\" for help!\n";
        }

        string str1;// stored the user input to append
        string name;//used for displaying the text
        std::ofstream outfile;//std ofstream for tracking the file
        fstream fs (textFileName.c_str(), ios::in | ios::out);//adding text at specific location
        fs.seekg (0, ios::end);//start seeking from character 0
        streamoff position = fs.tellg();//gets the total characters i.e. size of the file
        string str2;
        if (commandCatcher == "append"){//check if the user wants to append
            cout<< "enter text to be inserted at the end"<<endl;//prompt user for thext to apppend
            //cin.ignore();//ignoring the spaces
            getline(cin,str1);//taking the whole string as input

            //cout << str1;
            //cin >> str;
            outfile.open(textFileName.c_str(), std::ios_base::app); // append at the end of the text
            outfile << str1;//text which gets appended
            outfile.close();
            return "text has been appended";
        }

        else if (commandCatcher == "insert"){//check if the command is insert
        string pos;
        string finalString;
        string userInput;
        cout<< "enter position(counted by character) to insert new text: ";//prompt user for the specific position to input the text
        getline(cin,pos);
        cout<< "enter text to be inserted at position : ";
        getline(cin,userInput);

        ifstream ifs(textFileName.c_str());
        string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
        int posConvert =atoi(pos.c_str());
        content.insert(posConvert, userInput.c_str());
        remove(textFileName.c_str());//remove the text file
        outfile.open(textFileName.c_str());//recreate the file
        outfile << content;//text which gets appended
        outfile.close();
        return "text as been inserted";
        }

        else if (commandCatcher == "remove"){//check if the command is remove
            remove(textFileName.c_str());//remove the text file
            outfile.open(textFileName.c_str());//recreate the file
            return "The text has been removed";
        }

        else if (commandCatcher == "display"){//check if the command is display
                    std::ifstream outFile(textFileName.c_str());//takes in the test.txt file for display

                while (!outFile.fail() && !outFile.eof() )//ignores the end of line
        {
              outFile >> name ;
              cout << name << endl;
        }
        return "";
        }
        else{
            cout << "Not valid";
        }


        return "Invalid Command. Please use modify -h for help";
}



void printCat(){

printf("                         /)        \n");
printf("                /\\___/\\ ((         \n");
printf("                \\`o_o'/  ))        \n");
printf("                {_:Y:.}_//         \n");
printf("  --------------{_}---{_}--------------\n");
printf(" I'm a cat and I think they deserve a A+\n");
printf("  -------------------------------------\n");

}


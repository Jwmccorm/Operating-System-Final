//Problems:
//4.dont know how to pause
//Divya lakkad
//0869692
#include<iostream>
#include<fstream>
#include<string>
#include <dirent.h>
#include "../Features/Directory/directory.h"
#include "textmodification.h"

using namespace std;
int main(){


    string commandCatcher = "insert";
    string textFileName = "test.txt";
    string str1;
    string name;
    std::ofstream outfile;
    fstream fs ("test.txt", ios::in | ios::out);//adding text at specific location
    fs.seekg (0, ios::end);//start seeking from character 0
    streamoff position = fs.tellg();//gets the total characters i.e. size of the file
    string str2;
    string command;
    if (commandCatcher == "append"){
        cout<< "enter text to be inserted at the end"<<endl;
        cin.ignore();
        getline(cin,str1);

        cout << str1;
        //cin >> str;
        outfile.open(textFileName.c_str(), std::ios_base::app); // append at the end of the text
        outfile << str1;//text which gets appended
        outfile.close();
    }
    else if (commandCatcher == "insert"){
    cout<< "enter position(counted by character) to insert new text: ";
    cin >> position;
    cout<< "enter text to be inserted at position : ";
    cin.ignore();
    getline(cin,str2);
    fs.seekp (position);    // I picked 3rd position from the end to add the text
    fs.write ("Hey we added text at specific position ",position);// This is the text to be inserted with how many characters to add
    }
    else if (commandCatcher == "remove"){
        remove("test.txt");
        outfile.open("test.txt");
    }

    else if (commandCatcher == "display"){
                std::ifstream outFile("test.txt");

            while (!outFile.fail() && !outFile.eof() )
    {
          outFile >> name ;
          cout << name << endl;
    }
    }
    else{
        cout << "Not valid";
    }

    /*



    std::ofstream outfile;
    fstream fs ("test.txt", ios::in | ios::out);//adding text at specific location
    fs.seekg (0, ios::end);//start seeking from character 0
    streamoff position = fs.tellg();//gets the total characters i.e. size of the file

string str1;
string str2;
string command;
    //      modify
    std::ifstream outFile("test.txt");
    cout<< "enter the command here: ";
    cin>> command;

if(!command.compare(append)){
        cout<< "enter text to be inserted at the end"<<endl;
        cin.ignore();
        getline(cin,str1);
        //cin >> str;
     outfile.open("test.txt", std::ios_base::app); // append at the end of the text
  outfile << str1;//text which gets appended

}
elseif (command = specificpos){
    cout<< "enter position(counted by character) to insert new text: ";
    cin >> position;
    cout<< "enter text to be inserted at position : ";
    cin.ignore();
    getline(cin,str2);
   fs.seekp (position);    // I picked 3rd position from the end to add the text
    fs.write (str2,1);// This is the text to be inserted with how many characters to add
}
elseif (command == remove){
remove("test.txt");
outfile.open("test.txt");
}
elseif (command==show){
    while (!outFile.fail() && !outFile.eof() )
    {
          outFile >> name ;
          cout << name << endl;
    }

}
else{
    cout<<"Incorrect input! Please try again";
}
*/
}

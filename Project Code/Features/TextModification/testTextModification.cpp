//Every thing Seems working
//Problems:
//4.dont know how to pause
//Divya lakkad
//0869692
#include<iostream>
#include<fstream>
#include<string>
#include "textmodification.h"

using namespace std;

int main(){
    std::ofstream outfile;
    fstream fs ("test.txt", ios::in | ios::out);//adding text at specific location
    fs.seekg (0, ios::end);//start seeking from character 0
    streamoff position = fs.tellg();//gets the total characters i.e. size of the file

int x=0;
//int position=0;
string str1;
string str2;
cout<<" 1: Append text at the end \n 2: Insert text at specific location \n 3: Remove all text from fie \n4: Show content with pause/page"<<endl;
cin >> x;
string name ;
    std::ifstream outFile("test.txt");

switch(x)
{
case 1:
        cout<< "enter text to be inserted at the end"<<endl;
        cin.ignore();
        getline(cin,str1);
        //cin >> str;
     outfile.open("test.txt", std::ios_base::app); // append at the end of the text
  outfile << str1;//text which gets appended
  break;

case 2 :
    cout<< "enter position(counted by character) to insert new text: ";
    cin >> position;
    cout<< "enter text to be inserted at position : ";
    cin.ignore();
    getline(cin,str2);
   fs.seekp (position);    // I picked 3rd position from the end to add the text
    fs.write("text.txt" ,getline(cin,str2),position);// This is the text to be inserted with how many characters to add
break;

case 3:
remove("test.txt");
outfile.open("test.txt");
break;
case 4:
    while (!outFile.fail() && !outFile.eof() )
    {
          outFile >> name ;
          cout << name << endl;
    }

    break;
default :
    cout<<"Incorrect input! Please try again";
    break;

    }

return 0;

}

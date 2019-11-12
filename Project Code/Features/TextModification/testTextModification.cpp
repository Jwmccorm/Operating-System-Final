//Divya lakkad
//0869692
#include<iostream>
#include<fstream>
#include "textmodification.h"

using namespace std;

int main(){
 std::ofstream outfile;
  fstream fs ("test.txt", ios::in | ios::out);//adding text at specific location
fs.seekg (0, ios::end);//start seeking from character 0
streamoff filesize = fs.tellg();//gets the total characters i.e. size of the file

int x=0;
int position=0;
char str[100] = "";
cout<<" 1: Append text at the end \n 2: Insert text at specific location \n 3: Remove all text from fie \n4: Show content with pause/page"<<endl;
cin >> x;

switch(x)
{
case 1:
        cout<< "enter text to be inserted at the end"<<endl;
        cin >> str;
     outfile.open("test.txt", std::ios_base::app); // append at the end of the text
  outfile << str;//text which gets appended
  break;

case 2 :
    cout<< "enter position(counted by character) to insert new text: ";
    cin >> position;
    cout<< "enter text to be inserted at %d position",&position;
    cin>> str;
   fs.seekp (position);    // I picked 3rd position from the end to add the text
    fs.write( str , position );// This is the text to be inserted with how many characters to add
break;

case 3:
remove("test.txt");
outfile.open("test.txt");
break;
case 4:
cout<< "in progress4";
    break;
default :
    cout<<"Incorrect input! Please try again";
    //break;

    }

return 0;
    /*textModification();
    std::ofstream outfile;

  outfile.open("test.txt", std::ios_base::app); // append at the end of the text
  outfile << "\nAppend text done ";//text which gets appended
fstream fs ("test.txt", ios::in | ios::out);//adding text at specific location
fs.seekg (0, ios::end);//start seeking from character 0
streamoff filesize = fs.tellg();//gets the total characters i.e. size of the file
fs.seekp (10);    // I picked 3rd position from the end to add the text
fs.write( "text insert at specif", 10 );// This is the text to be inserted with how many characters to add
fs.close();
  return 0;*/


}

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
cout<<" 1: Append text at the end \n 2: Insert text at specific location \n 3: Remove all text from fie \n4: Show content with pause/page";
cin >> x;

switch(x)
{
case 1:
     outfile.open("test.txt", std::ios_base::app); // append at the end of the text
  outfile << "\nAppend text done ";//text which gets appended
  break;

case 2 :
   fs.seekp (10);    // I picked 3rd position from the end to add the text
fs.write( "text insert at specif", 10 );// This is the text to be inserted with how many characters to add
break;

case 3:
cout << "in progress3";
break;
case 4:
cout<< "in progress4";
    break;
default :
    cout<<" in progressdef";
    break;

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

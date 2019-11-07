#include<iostream>
#include "copyfile.h"


//  James McCormack
//  0507425

using namespace std;

int main()
{

    string returnValue = copyFile("text.txt swag");

    cout << returnValue;
}

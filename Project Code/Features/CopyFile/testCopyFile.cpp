#include<iostream>
#include "copyfile.h"


//  James McCormack
//  0507425

using namespace std;
int main(int argc, char** argv)
{

  std::ifstream ifs("myfile.txt");
  std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );

  content.insert(1, "penis");
  cout << content;
  return 0;
}

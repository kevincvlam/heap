// string::rfind
#include <iostream>
#include <string>
using namespace std;

int main ()
{
  string str ("Does rfind find CSC108H?");
  string key ("CSC108H");
  size_t found;

  found=str.rfind(key);
  if (found!=string::npos)
    str.replace (found,key.length(),"CSC Courses");

  cout << str << endl;

  return 0;
}

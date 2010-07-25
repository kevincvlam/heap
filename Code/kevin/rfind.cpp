// string::rfind
#include <iostream>
#include <string>
using namespace std;

int main ()
{
  string str ("Does rfind find CSC108H? 1st");
  string key ("1st");
  size_t found;

  found=str.rfind(key);
  if (found!=string::npos)
    str.replace (found,key.length(),"Yes!");
  key = "CSC108H";
  found=str.rfind(key);
  if (found!=string::npos)
    str.replace (found,key.length(),"CSC Courses");

  cout << str << endl;

  return 0;
}

/*
 * g++ -std=c++0x HelloWorld.cpp
 */
#include <iostream>

using namespace std;

class Blarg {
public:
  Blarg () {};
  Blarg (const Blarg& original) {}; /* Copy constructor */
  Blarg (Blarg&& original) {}; /* Move constructor */
};

int main(int argc, char *argv[])
{
  Blarg b;
  
  cout << "hello, world!" << endl;
  
  return 0;
}

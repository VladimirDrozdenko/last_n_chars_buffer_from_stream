#include <iostream>
#include "Buffer.h"
using namespace std;


int main() {
  Buffer<10> bb;
  bb.Add("Zopa popa ");
  bb.Add('c');
  bb.Add(" kalbasa!");

  bb.Add("abc");

  cout << bb.GetBuffer() << endl;
}
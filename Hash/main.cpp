#include "Hash.cpp"
#include <iostream>
using namespace std;
int main() {
  Hash hash;
  hash.Hash32("This is Original Text");
  hash.Hash64("This is Original Text");

  return 0;
}
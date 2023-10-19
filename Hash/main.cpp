#include "Hash.cpp"
#include "HashTable.cpp"
#include <iostream>
using namespace std;
int main() {
  // Hash hash;
  // hash.Hash32("This is Original Text");
  // hash.Hash64("This is Original Text");

  // return 0;

  HashTable table;
  table.Print();
  table.Set("Sinar", "sinar@gmail.com");
  table.Set("Elvis", "elvis@gmail.com");
  table.Set("Tane", "tane@gmail.com");
  // table.Print();
  cout << "[get] " << table.Get("Sinar") << endl;
  // cout << "[get] " << table.Get("Tane") << endl;
  table.Set("Gerti", "gerti@gmail.com");
  table.Set("Arist", "arist@gmail.com");
  // table.Print();
  cout << "[get] " << table.Get("Sinar") << endl;

  return 0;
}
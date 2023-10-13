#include "Dictionary.cpp"
// #include "Hash.cpp"
// #include "HashTable.cpp"
#include <iostream>
using namespace std;
int main() {
  
  Dictionary dic;
  dic.Print();

  dic.Set("Sinar", "sinar@gmail.com");
  dic.Set("Elvis", "elvis@gmail.com");
  dic.Print();

  dic.Set("Tane", "tane@gmail.com");
  dic.Set("Gerti", "gerti@gmail.com");
  dic.Set("Arist", "arist@gmail.com");

  dic.Print();

  cout << dic.Get("Tane") << endl;
  cout << dic.Get("Sinar") << endl;
  cout << dic.Get("Elviaaa") << endl;

  dic.Remove("Sinar");
  dic.Remove("Elvis");
  dic.Remove("Tane");
  dic.Remove("Gerti");
  dic.Remove("Arist");
  dic.Print();

  dic.Set("Sinar", "sinar@gmail.com");
  dic.Print();

  return 0;
}
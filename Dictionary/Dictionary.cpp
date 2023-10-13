#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
class Dictionary {
public:
  Dictionary() {
    initialSize = 3;
    entries = vector<pair<string, string>>(initialSize);
    entriesCount = 0;
  }

  void ResizeOrNot() {
    // Check if dictionary needs resizing
    if (entriesCount < entries.size()) {
      return;
    }

    // Resize the dictionary
    int newSize = entries.size() + initialSize;

    cout << "[resize] from " << entries.size() << " to " << newSize << endl;

    vector<pair<string, string>> newArray(newSize);
    for (int i = 0; i < entries.size(); i++)
      newArray[i] = entries[i];
    entries.clear();
    entries.resize(newSize);
    entries = newArray;
  }

  int Size() { return entriesCount; }

  void Set(string key, string value) {
    // Search for an existing entry with the same key
    for (int i = 0; i < entriesCount; i++) {
      if (entries[i].first != "" && entries[i].first == key) {
        entries[i].second = value;
        return;
      }
    }

    // Add a new entry to the dictionary
    ResizeOrNot();
    pair<string, string> newPair({key, value});
    entries[entriesCount] = newPair;
    entriesCount++;
  }

  string Get(string key) {
    // Search for the entry with the specified key
    for (int i = 0; i < entriesCount; i++) {
      if (entries[i].first != "" && entries[i].first == key) {
        return entries[i].second;
      }
    }
    return "";
  }

  bool Remove(string key) {
    // Search for the entry with the specified key
    for (int i = 0; i < entriesCount; i++) {
      if (entries[i].first != "" && entries[i].first == key) {
        entries[i] = entries[entriesCount - 1];
        entries[entriesCount - 1] = pair<string, string>({"", ""});
        entriesCount--;
        return true;
      }
    }
    return false;
  }

  void Print() {
    cout << "----------" << endl;
    cout << "[size] " << Size() << endl;
    for (int i = 0; i < entries.size(); i++) {
      if (entries[i].first == "") {
        cout << "[" << i << "]" << endl;
      } else {
        cout << "[" << i << "]" << entries[i].first << ":" << entries[i].second
             << endl;
      }
    }
    cout << "==========" << endl;
  }

private:
  int initialSize;
  vector<pair<string, string>> entries;
  int entriesCount;
};
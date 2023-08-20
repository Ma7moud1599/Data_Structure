#include <cstring>
#include <iostream>

using namespace std;

class OurArray
{
public:
  // Resizes the given array to the new size
  template <typename T>
  void Resize(T *&source, int newSize)
  {
    if (newSize <= 0) return;
    if (source == nullptr) return;
    if (newSize == static_cast<int>(sizeof(source))) return;
    T *newArray = new T[newSize];
    memcpy(newArray, source, sizeof(T) * newSize);
    delete[] source;
    source = newArray;
  }

  // Returns the item at the given index in the given array
  template <typename T>
  T GetAt(T *source, int index, int sizeOf)
  {
    if (index < 0) return T();
    char *zeroAddr = reinterpret_cast<char *>(source);
    char *itemAddr = zeroAddr + (index * sizeOf);
    /* reinterpret_cast is used to cast the address of the memory location
     * pointed to by itemAddr to a pointer of type T*, and then dereference it
     * to get the value stored in that memory location.*/
    return *reinterpret_cast<T *>(itemAddr);
  }
};

int main()
{

  // time complexity: O(n), space complexity: O(n)
  int *arr = new int[3]{4654, 921, 762};
  OurArray our;
  our.Resize<int>(arr, 5);
  for (int i = 0; i < 5; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  int item = our.GetAt<int>(arr, 1, sizeof(int));
  cout << item << endl;
  cout << arr[1] << endl;

  delete[] arr;
  return 0;
}

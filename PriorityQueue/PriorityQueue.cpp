#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue {
private:
  vector<pair<int, int>> data_list; // vector to hold the data and their
                                    // respective priorities in the queue
  int size;                         // holds the number of elements in the queue
public:
  PriorityQueue() { size = 0; }

  void enqueue(int priority, int data) {
    int i = size;
    data_list.push_back(make_pair(priority, data));
    size++;
    int parent_index = floor((i - 1) / 2);
    while (i != 0 && data_list[i].first < data_list[parent_index].first) {
      pair<int, int> temp = data_list[i];
      data_list[i] = data_list[parent_index];
      data_list[parent_index] = temp;
      i = parent_index;
      parent_index = floor((i - 1) / 2);
    }
  }

  pair<int, int> dequeue() {
    if (size == 0)
      return make_pair(NULL, NULL);
    int i = 0;
    pair<int, int> data = make_pair(data_list[i].first, data_list[i].second);
    pair<int, int> last_node =
        make_pair(data_list[size - 1].first, data_list[size - 1].second);

    // copy last node to root
    data_list[i] = last_node;

    // delete last node
    data_list[size - 1] = make_pair(NULL, NULL);
    size--;

    int left_index = 2 * i + 1;
    while (left_index < size) {
      int right_index = 2 * i + 2;

      int smaller_index = left_index; // just initial value;
      if (right_index < size &&
          data_list[right_index].first < data_list[left_index].first) {
        smaller_index = right_index;
      }
      if (data_list[smaller_index].first >= data_list[i].first) {
        break;
      }

      // swap
      pair<int, int> temp = data_list[i];
      data_list[i] = data_list[smaller_index];
      data_list[smaller_index] = temp;

      i = smaller_index;
      left_index = 2 * i + 1;
    }
    return data;
  }

  bool hasData() { return size > 0; }

  void print() {
    string print_data = "";
    for (int i = 0; i < size; i++) {
      print_data += to_string(data_list[i].second) + " - ";
    }
    cout << print_data << endl;
  }

  int getSize() { return size; }

  void draw() {
    int levels_count = log2(getSize()) + 1;
    int line_width = pow(2, levels_count - 1);
    int j = 0;

    for (int i = 0; i < levels_count; i++) {
      int nodes_count = pow(2, i);
      int space = ceil(line_width - nodes_count / 2);
      int space_between = ceil(levels_count / nodes_count);
      space_between = space_between < 1 ? 1 : space_between;
      int k = j;
      string str(space + space_between, ' ');

      for (; j < k + nodes_count; j++) {
        if (j == getSize()) {
          break;
        }
        if (data_list[j].first != NULL && data_list[j].second != NULL) {
          str += to_string(data_list[j].second) + "[" + to_string(data_list[j].first) + "]" + string(space_between, ' ');
        }
      }
      str += string(space, ' ') + "\n";
      cout << str;
    }
  }
};
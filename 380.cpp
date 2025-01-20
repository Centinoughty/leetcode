// Insert delete getrandom O(1)
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
  vector<int> arr;

public:
  RandomizedSet() {}

  int search(int val) {
    auto pos = find(arr.begin(), arr.end(), val);
    if (pos != arr.end()) {
      return distance(arr.begin(), pos);
    } else {
      return -1;
    }
  }
  
  bool insert(int val) {
    if (search(val) == -1) {
      arr.push_back(val);
      return true;
    }

    return false;
  }
  
  bool remove(int val) {
    int pos = search(val);
    if (pos != -1) {
      arr.erase(arr.begin() + pos);
      return true;
    }

    return false;
  }
  
  int getRandom() {
    return arr[rand() % arr.size()];
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
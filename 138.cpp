// Copy list with random pointer
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int val;
  Node* next;
  Node* random;
  
  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  Node* copyRandomList(Node* head) {
    if (!head) {
      return nullptr;
    }

    auto pos = map.find(head);
    if (pos != map.end()) {
      return pos->second;
    }

    Node* newNode = new Node(head->val);
    map[head] = newNode;
    newNode->next = copyRandomList(head->next);
    newNode->random = copyRandomList(head->random);
    return newNode;
  }

private:
  unordered_map<Node*, Node*> map;
};

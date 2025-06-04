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

/*
// Definition for a Node.
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
*/

class Solution {
public:
  Node* copyRandomList(Node* head) {
    Node *temp = new Node(0);
    Node *next = temp;
    Node *curr = head;
    while (curr) {
      next->next = new Node(curr->val);
      map[curr] = next->next;
      curr = curr->next;
      next = next->next;
    }

    next = temp->next;
    curr = head;
    while (curr) {
      next->random = map[curr->random];
      curr = curr->next;
      next = next->next;
    }

    return temp->next;
  }

private:
  unordered_map<Node*, Node*> map;
};

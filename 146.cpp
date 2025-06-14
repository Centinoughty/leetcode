// LRU cache
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    struct ListNode {
        int key;
        int val;
        ListNode *next;
        ListNode *prev;
        ListNode() : key(-1), val(-1), next(nullptr), prev(nullptr) {}
        ListNode(int x, int y) : key(x), val(y), next(nullptr), prev(nullptr) {}
    };

    LRUCache(int capacity) {
        total = capacity;
        size = 0;
        dll = new ListNode();
        tail = new ListNode();
        dll->next = tail;
        tail->prev = dll;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            ListNode* dummy = mp[key];
            removeNode(dummy);
            insertNode(dummy);
            return dummy->val;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            ListNode *dummy = mp[key];
            removeNode(dummy);
            size --;
        }

        if (size == total) {
            ListNode *dummy = tail->prev;
            removeNode(dummy);
            mp.erase(dummy->key);
            size --;
        }

        ListNode *temp = new ListNode(key, value);
        insertNode(temp);
        mp[key] = temp;
        size ++;
    }

private:
    int total, size;
    ListNode *dll, *tail;

    unordered_map<int, ListNode*> mp;

    void removeNode(ListNode* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    void insertNode(ListNode* node) {
        node->next = dll->next;
        node->prev = dll;
        dll->next->prev = node;
        dll->next = node;
    }
};

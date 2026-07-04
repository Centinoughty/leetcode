// LFU Cache
// HARD

#include <bits/stdc++.h>
using namespace std;

class LFUCache {
public:
    LFUCache(int capacity) {
        rem = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        ListNode* temp = mp[key];
        deleteNode(temp, temp->cnt);
        
        temp->cnt ++;
        insertNode(temp, temp->cnt);

        return temp->value;
    }
    
    void put(int key, int value) {
        if (mp.find(key) == mp.end()) {
            ListNode* temp = new ListNode(key, value);
            mp[key] = temp;
            temp->cnt ++;

            if (rem == 0) {
                auto it = freq.begin();
                ListNode* h = it->second.first;

                mp.erase(h->next->key);
                deleteNode(h->next, h->next->cnt);
            } else {
                rem --;
            }

            insertNode(temp, 1);
        } else {
            ListNode* temp = mp[key];
            deleteNode(temp, temp->cnt);
            
            temp->value = value;
            temp->cnt ++;
            insertNode(temp, temp->cnt);
        }
    }

private:
    struct ListNode {
        int key;
        int value;
        int cnt;
        ListNode* prev;
        ListNode* next;


        ListNode() : key(-1), value(0), cnt(0), prev(nullptr), next(nullptr) {};
        ListNode(int k, int v) : key(k), value(v), cnt(0), prev(nullptr), next(nullptr) {};
    };

    int rem;
    unordered_map<int, ListNode*> mp;
    map<int, pair<ListNode*, ListNode*>> freq;

    void insertNode(ListNode* node, int f) {
        if (freq.find(f) == freq.end()) {
            ListNode* temp1 = new ListNode();
            ListNode* temp2 = new ListNode();

            temp1->next = temp2;
            temp2->prev = temp1;

            freq[f] = {temp1, temp2};
        }

        ListNode* h = freq[f].first;
        ListNode* t = freq[f].second;

        node->prev = t->prev;
        node->next = t;

        t->prev->next = node;
        t->prev = node;

        h->value ++;
    }

    void deleteNode(ListNode* node, int f) {
        ListNode* h = freq[f].first;
        ListNode* t = freq[f].second;

        node->prev->next = node->next;
        node->next->prev = node->prev;

        h->value --;
        if (h->value == 0) {
            freq.erase(f);
        }
    }
};

// Using unordered_map and not map
class LFUCache {
public:
    LFUCache(int capacity) {
        rem = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        ListNode* temp = mp[key];
        deleteNode(temp, temp->cnt);
        
        temp->cnt ++;
        insertNode(temp, temp->cnt);

        return temp->value;
    }
    
    void put(int key, int value) {
        if (mp.find(key) == mp.end()) {
            ListNode* temp = new ListNode(key, value);
            mp[key] = temp;
            temp->cnt ++;

            if (rem == 0) {
                ListNode* h = freq[minFreq].first;

                mp.erase(h->next->key);
                deleteNode(h->next, h->next->cnt);
            } else {
                rem --;
            }

            insertNode(temp, 1);
            minFreq = 1;
        } else {
            ListNode* temp = mp[key];
            deleteNode(temp, temp->cnt);
            
            temp->value = value;
            temp->cnt ++;
            insertNode(temp, temp->cnt);
        }
    }

private:
    struct ListNode {
        int key;
        int value;
        int cnt;
        ListNode* prev;
        ListNode* next;


        ListNode() : key(-1), value(0), cnt(0), prev(nullptr), next(nullptr) {};
        ListNode(int k, int v) : key(k), value(v), cnt(0), prev(nullptr), next(nullptr) {};
    };

    int rem, minFreq;
    unordered_map<int, ListNode*> mp;
    unordered_map<int, pair<ListNode*, ListNode*>> freq;

    void insertNode(ListNode* node, int f) {
        if (freq.find(f) == freq.end()) {
            ListNode* temp1 = new ListNode();
            ListNode* temp2 = new ListNode();

            temp1->next = temp2;
            temp2->prev = temp1;

            freq[f] = {temp1, temp2};
        }

        ListNode* h = freq[f].first;
        ListNode* t = freq[f].second;

        node->prev = t->prev;
        node->next = t;

        t->prev->next = node;
        t->prev = node;

        h->value ++;
    }

    void deleteNode(ListNode* node, int f) {
        ListNode* h = freq[f].first;
        ListNode* t = freq[f].second;

        node->prev->next = node->next;
        node->next->prev = node->prev;

        h->value --;
        if (h->value == 0) {
            freq.erase(f);

            if (minFreq == f) minFreq ++;
        }
    }
};

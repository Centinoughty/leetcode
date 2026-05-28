// Implement trie (prefix tree)
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isLeaf;

    TrieNode() {
        isLeaf = false;
        for (int i = 0; i < 26; i ++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for (const char& c : word) {
            int pos = c - 'a';
            if (temp->children[pos] == nullptr) {
                temp->children[pos] = new TrieNode();
            }

            temp = temp->children[pos];
        }

        temp->isLeaf = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for (const char& c : word) {
            int pos = c - 'a';
            if (temp->children[pos] == nullptr) {
                return false;
            }

            temp = temp->children[pos];
        }

        return temp->isLeaf;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for (const char& c : prefix) {
            int pos = c - 'a';
            if (temp->children[pos] == nullptr) {
                return false;
            }

            temp = temp->children[pos];
        }

        return true;
    }

private:
    TrieNode* root;
};

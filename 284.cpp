// Peeking iterator
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Iterator {
		struct Data;
 		Data* data;
public:
		Iterator(const vector<int>& nums);
 		Iterator(const Iterator& iter);

		int next();

		bool hasNext() const;
};

class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {}
    
    int peek() {
        return Iterator(*this).next();
    }
    
    int next() {
        return Iterator::next();
    }
    
    bool hasNext() const {
        return Iterator::hasNext();
    }
};

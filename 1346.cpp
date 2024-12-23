// Check if N and its double exist
// EASY

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> table;

        for (const int i : arr) {
            if (table.count(i * 2) > 0 || (i % 2 == 0 && table.count(i / 2) > 0)) {
                return true;
            }

            table.insert(i);
        }

        return false;
    }
};
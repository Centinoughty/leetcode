// Shuffle an array
// MEDIUM

#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
    Solution(vector<int>& nums): nums(nums) {
        
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        vector<int> A(nums);
        for (int i = A.size() - 1; i >= 0; i --) {
            const int j = rand() % (i + 1);
            swap(A[i], A[j]);
        }

        return A;
    }

    private:
        vector<int> nums;
};
// Group the people given the group size they belong to
// MEDIUM

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> result;
        unordered_map<int, vector<int>> group;

        for (int i = 0; i < groupSizes.size(); i ++) {
            group[groupSizes[i]].push_back(i);
        }

        for (const auto& [size, index]: group) {
            vector<int> indices;
            for (const int i: index) {
                indices.push_back(i);
                if (indices.size() == size) {
                    result.push_back(indices);
                    indices.clear();
                }
            }
        }

        return result;
    }
};
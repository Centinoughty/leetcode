// Time Based Key-Value Store
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class TimeMap {
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) return "";

        vector<pair<int, string>>& temp = mp[key];
        int l = 0, r = temp.size() - 1;

        int res = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (temp[mid].first <= timestamp) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return res == -1 ? "" : temp[res].second;
    }

private:
    unordered_map<string, vector<pair<int, string>>> mp;
};

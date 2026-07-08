// Task Scheduler
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        auto compare = [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second < b.second;
        };

        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(compare)> pq;

        unordered_map<char, int> freq;
        for (const char& task : tasks) {
            freq[task] ++;
        }

        for (auto [x, y] : freq) {
            pq.push({x, y});
        }

        queue<pair<int, pair<int, char>>> q;

        int timer = 0;
        while (!pq.empty() || !q.empty()) {
            timer ++;
            while (!q.empty() && q.front().first <= timer) {
                auto [t, x] = q.front();
                auto [cnt, ch]  =x;

                q.pop();
                pq.push({ch, cnt});
            }

            if (!pq.empty()) {
                auto [task, cnt] = pq.top(); pq.pop();
                cnt --;
                
                if (cnt > 0) {
                    q.push({timer + n + 1, {cnt, task}});
                }
            }
        }

        return timer;
    }
};

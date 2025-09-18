// Design task manager
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class TaskManager {
private:
    priority_queue<pair<int, int>> pq;
    unordered_map<int, int> mpPriority;
    unordered_map<int, int> mpOwner;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& task : tasks) {
            add(task[0], task[1], task[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        pq.push({priority, taskId});
        mpPriority[taskId] = priority;
        mpOwner[taskId] = userId;
    }
    
    void edit(int taskId, int newPriority) {
        pq.push({newPriority, taskId});
        mpPriority[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        mpPriority[taskId] = -1;
    }
    
    int execTop() {
        while (!pq.empty()) {
            const auto task = pq.top();
            pq.pop();
            if (task.first == mpPriority[task.second]) {
                mpPriority[task.second] = -1;
                return mpOwner[task.second];
            }
        }

        return -1;
    }
};

// My Calendar I
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class MyCalendar {
public:
    MyCalendar() {}
    
    bool book(int startTime, int endTime) {
        endTime --;

        int pos = 0;
        for (int i = 0; i < intervals.size(); i ++) {
            if (endTime < intervals[i].first || startTime < intervals[i].second) {
                return false;
            } else {
                if (startTime > intervals[i].second) {
                    pos ++;
                }
            }
        }

        pair<int, int> interval = {startTime, endTime};
        insert(intervals, pos, interval);

        return true;
    }

private:
    vector<pair<int, int>> intervals;

    void insert(vector<pair<int, int>>& intervals, int pos, pair<int, int> interval) {
        intervals.push_back(interval);

        int n = intervals.size();

        for (int i = n - 1; i > pos; i --) {
            intervals[i] = intervals[i - 1];
        }

        intervals[pos] = interval;
    }
};

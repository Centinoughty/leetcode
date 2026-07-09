// Design Twitter
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Twitter {
public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        insertNode(userId, tweetId, timer);
        timer++;
    }
    
    vector<int> getNewsFeed(int userId) {
        auto compare = [](const ListNode* a, const ListNode* b) {
            return a->time < b->time;
        };

        vector<int> res;
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq;

        for (auto [x, y] : tweets) {
            auto mp = following[x];
            if (x == userId || mp.find(userId) != mp.end()) {
                pq.push(y);
            }
        }

        int k = 0;
        while (!pq.empty() && k < 10) {
            auto top = pq.top(); pq.pop();
            res.push_back(top->val);
            k ++;

            if (top->next) {
                pq.push(top->next);
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        following[followeeId].insert(followerId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followeeId].erase(followerId);
    }

private:
    struct ListNode {
        int val;
        int time;
        ListNode* next;

        ListNode() : val(-1), time(-1), next(nullptr) {}
        ListNode(int d, int t) : val(d), time(t), next(nullptr) {}
    };

    int timer = 1;
    unordered_map<int, ListNode*> tweets;
    unordered_map<int, unordered_set<int>> following;

    void insertNode(int userId, int tweetId, int time) {
        if (tweets.find(userId) == tweets.end()) {
            tweets[userId] = new ListNode(tweetId, time);
        } else {
            ListNode* temp = tweets[userId];
            ListNode* newNode = new ListNode(tweetId, time);
            newNode->next = temp;

            tweets[userId] = newNode;
        }
    }
};

// Design spreadsheet
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
private:
    unordered_map<string, int> mp;
    int maxRows = 0;

    int getToken(const string& token) {
        return isdigit(token[0]) ? stoi(token) : (mp.contains(token) ? mp[token] : 0);
    }

public:
    Spreadsheet(int rows) {
        maxRows = rows;
    }
    
    void setCell(string cell, int value) {
        mp[cell] = value;
    }
    
    void resetCell(string cell) {
        mp[cell] = 0;
    }
    
    int getValue(string formula) {
        const int i = formula.find('+');
        return getToken(formula.substr(1, i - 1)) + getToken(formula.substr(i + 1));
    }
};

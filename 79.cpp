// Word search
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool exist(vector<vector<char>>& board, string word) {
    int rows = board.size();
    int cols = board[0].size();

    for (int i = 0; i < rows; i ++) {
      for (int j = 0; j < cols; j ++) {
        if (dfs(board, i, j, word, 0)) {
          return true;
        }
      }
    }

    return false;
  }

private:
  bool dfs(vector<vector<char>>& board, int i, int j, string word, int pos) {
    if (pos == word.size()) {
      return true;
    }


    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[pos]) {
      return false;
    }

    char temp = board[i][j];
    board[i][j] = '#';

    bool status = dfs(board, i - 1, j, word, pos + 1) ||
                dfs(board, i, j - 1, word, pos + 1) ||
                dfs(board, i, j + 1, word, pos + 1) ||
                dfs(board, i + 1, j, word, pos + 1);
    
    board[i][j] = temp;
    return status;
  }
};

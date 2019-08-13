#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        int x = click[0], y = click[1];
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, -1}, {0, 1},{1, -1}, {-1, 1}, {-1, -1}, {1, 1}};
        
        if (board[x][y] == 'M') board[x][y] = 'X';
        else {
            int cnt = 0;
            for (auto dir : dirs){
                auto xi = x + dir[0], yi = y + dir[1];
                if (xi < 0 || xi >= m || yi < 0 || yi >= n) continue;
                if (board[xi][yi] == 'M') cnt++;
            }
            board[x][y] = cnt == 0 ? 'B' : cnt + '0';
            if (board[x][y] == 'B') {
                for (auto dir : dirs){
                    auto xi = x + dir[0], yi = y + dir[1];
                    if (xi < 0 || xi >= m || yi < 0 || yi >= n || board[xi][yi] != 'E') continue;
                    vector<int> p{xi, yi};
                    board = updateBoard(board, p);
                }
            }
        }
        
        return board;
    }
};
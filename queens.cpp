#include <bits/stdc++.h>
using namespace std;

int count = 0;

bool isSafe(vector<string>& board, int i, int j) {
    int ti = i;
    int tj = j;
    while (ti >= 0) {
        if (board[ti][tj] == 'Q') {
            return false;
        }  
        ti--;
    }
    ti = i; tj = j;
    while (ti >= 0 && tj >= 0) {
        if (board[ti][tj] == 'Q') return false;
        ti--;tj--;
    }
    ti = i; tj = j;
    while (ti >= 0 && tj >= 0) {
        if (board[ti][tj] == 'Q') return false;
        ti--;tj++;
    }
    return true;
}

void backtrack(int i, vector<string>& board) {
    if (i == 8) {
        ::count++;
        return;
    }

    for (int j = 0; j < 8; j++) {
        if (board[i][j] == '*') continue;
        if (isSafe(board, i, j)) {
            board[i][j] = 'Q';
            backtrack(i + 1, board);
            board[i][j] = '.';
        }
    }
}

int main() {
    vector<string> board(8);
    
    for (auto &row : board) {
        cin >> row;
    }

    backtrack(0, board);

    cout << ::count;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

string clearDigits(string s) {
        int n = s.size();
        vector<int> check(n, 1);
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                check[i] = 0;
                int j = i - 1;
                while (j >= 0 && isdigit(s[j])) {
                    j--;
                }
                s[j] = '1';
                check[j] = 0;
            }
        }   
        string res = "";
        for (int i = 0; i < n; i++) {
            if (check[i]) {
                res += s[i];
            }
        }
        return res;
}

 string clearDigits2(string s) {
        int n = s.size();
        stack<char>st;
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                st.pop();
            } else {
                st.push(s[i]);
            }
            
        }   
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;

        
    }

     int findWinningPlayer(vector<int>& skills, int k) {
        unordered_map<int,int> mp;
        int n = skills.size();
        deque<int> dq;
        
        for (int i = 0; i < n; i++) {
            mp[skills[i]] = i;
            dq.push_back(skills[i]);
        }
        
        int streak = 0;
        int cur = -1;
        
        while (streak != k) {
            int first = dq.front();
            dq.pop_front();
            int second = dq.front();
            dq.pop_front();
            int winner = max(first, second);
            int loser = min(first, second);
            if (cur == winner) {
                streak++;
            } else {
                streak = 1;
                cur = winner;
            }
            dq.push_back(loser);
            dq.push_front(winner);
        }
        
        return mp[cur];
        
    }

int main() {

    cout << clearDigits2("abc") << endl;
    return 0;
}
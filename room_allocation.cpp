#include <bits/stdc++.h>
using namespace std;

int cur_rooms[(int)(2 * 1e5 + 1)];

int main() {
    int n;

    cin >> n;
    

    int used = 0;

    using pipii = pair<int,pair<int,int>>;

    priority_queue<pipii, vector<pipii>, greater<pipii> > pq;

    queue<int> freeRooms;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pq.push( {a, {0, i}} );
        pq.push( {b, {1, i}} );
    }

    while (!pq.empty()) {
        
        int day = pq.top().first;
        int leaving = pq.top().second.first;
        int who = pq.top().second.second;

        pq.pop();

        if (leaving) {
            freeRooms.push(cur_rooms[who]);
            continue;
        }

        if (!freeRooms.empty()) {
            int room = freeRooms.front();
            freeRooms.pop();
            cur_rooms[who] = room;
            continue;
        }

        used++;

        cur_rooms[who] = used;
    }

    cout << used << endl;

    for (int i = 0; i < n; i++) {
        cout << cur_rooms[i] << " ";
    }


    return 0;
}
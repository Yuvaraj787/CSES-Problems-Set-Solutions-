#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll n, target;
    cin >> n >> target;
    vector<ll> prefixSum(n, 0);
    ll sum = 0;
    ll ele;
    for (ll &i : prefixSum) {
        cin >> ele;
        sum += ele;
        i = sum;
    }
    
    map<ll,ll> mp;

    ll count = 0;

    mp[0] = 1;

    for (ll i : prefixSum) {
        ll x = i - target;
        if (mp.find(x) != mp.end()) {
            count += mp[x];
        }
        mp[i]++;
    }

    cout << count << endl;

    return 0;
}
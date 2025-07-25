#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,ull>
using namespace std;
using ull = unsigned long long;
const int INF = 1e18;
const int maxn = 1e9;

//Hash
ull splitmix64(ull x) {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
}

void solve(){
    int n;
    cin >> n;
    vector<pii> events;
    events.reserve(2LL * n);
    for(int i = 0; i < n; i++){
        long long l, r;
        cin >> l >> r;
        ull h = splitmix64((ull)i + 1);
        events.emplace_back(l,h);
        events.emplace_back(r + 1, h);
    }

    sort(events.begin(), events.end(),[](auto &a, auto &b){ 
        return a.first < b.first; 
    });

    unordered_set<ull> S;
    S.reserve(events.size() + 1);
    ull cur = 0;
    S.insert(cur);
    size_t idx = 0, m = events.size();
    
    while(idx < m){
        int pos = events[idx].first;
        while(idx < m && events[idx].first == pos){
            cur ^= events[idx].second;
            idx++;
        }
        S.insert(cur);
    }
    cout << S.size() << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

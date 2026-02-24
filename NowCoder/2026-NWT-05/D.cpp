#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
constexpr int MOD = 1e9 + 7;

void solve(){
    int n;cin >> n;
    priority_queue<int,vector<int>,greater<int>> pq;
    map<int,int> freq;
    for(int i = 1; i <= n; i++){
        int c,w;cin >> c >> w;
        freq[w] += c;
        pq.push(w);
    }

    int ans = 0;
    while(pq.size() > 1){
        int x = pq.top();
        if(freq[x] == 1) pq.pop();
        freq[x]--;
        // cerr << x << " ";

        int y = pq.top();
        if(freq[y] == 1) pq.pop();
        freq[y]--;

        int cost = x + y;
        ans = (ans + cost) % MOD;
        freq[cost]++;
        pq.push(cost);
    }

    cout << ans % MOD << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
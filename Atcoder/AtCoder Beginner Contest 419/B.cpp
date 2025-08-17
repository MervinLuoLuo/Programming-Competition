#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int Q;cin >> Q;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(Q--){
        int op;cin >> op;
        if(op == 1){
            int x;cin >> x;
            pq.push(x);
        }
        else {cout << pq.top() << endl;pq.pop();}
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin >> n;
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i = 0; i < n; i++){
        int x;cin >> x;
        q.push(x);
    }
    int ans = 0;
    while(q.size() >= 2){
        int x = q.top();
        q.pop();
        int y = q.top(); q.pop();
        ans += x + y;
        q.push(x + y);
    }
    cout << ans << endl;
    return 0;
}
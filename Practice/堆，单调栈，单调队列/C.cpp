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
    vector<int> h(n), v(n);
    for(int i = 0; i < n; i++){
        cin >> h[i] >> v[i];
    }
    stack<int> s;
    vector<int> sum(n);
    for(int i = 0; i < n; i++){
        while(!s.empty() and h[s.top()] < h[i]){
            sum[i] += v[s.top()];
            s.pop();
        }
        if(!s.empty()) sum[s.top()] += v[i];
        s.push(i);
    }
    int ans = -1;
    for(auto p : sum) ans = max(ans , p);
    cout << ans << endl;
    return 0;
}
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
    vector<int> a(n + 1), ans(n + 1);
    for(int i = 1; i <=n; i++){
        cin >> a[i];
    }
    stack<int> s;
    for(int i = n; i>= 0;i--){
        while(!s.empty() and a[s.top()] <= a[i]) s.pop();
        if(s.empty()) ans[i] = 0;
        else ans[i] = s.top();
        s.push(i);
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
    return 0;
}
/*https://www.luogu.com.cn/problem/P5788*/
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
    int n;cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){cin >> a[i];}
    stack<int> st;
    vector<int> ans(n + 1, 0);
    for(int i = n; i >= 1; i--){
        while(!st.empty() && a[st.top()] <= a[i]) st.pop();
        ans[i] = (st.empty() ? 0 : st.top());
        st.push(i);
    }
    for(int i = 1; i <= n; i++) cout << ans[i] <<  " ";
    cout << endl;    
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
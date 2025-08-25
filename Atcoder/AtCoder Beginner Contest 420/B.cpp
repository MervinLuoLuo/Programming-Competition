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
    int n,m;cin >> n >> m;
    vector<int> ans(m + 1,0);
    for(int i = 0; i < n; i++){
        string s;cin >> s;
        vector<int> a,b;
        for(int j = 0; j < m;j++){
            if(s[j] == '0') a.push_back(j + 1);
            else b.push_back(j + 1);
        }
        if(a.empty() || b.empty()) continue;
        if(a.size() < b.size()){
            for(int k = 0; k < a.size(); k++) ans[a[k]]++;
        }
        else{
            for(int k = 0;k < b.size(); k++) ans[b[k]]++;
        }
    }
    int maxs = *max_element(ans.begin(),ans.end());
    for(int i = 1; i <= m; i++){
        if(ans[i] == maxs) cout << i << " ";
    }
    cout << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
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
    string s;
    cin >> s;
    map<int,int> stat;
    set<int> ans;
    for(int i = 0; i < m;i++){
        int x;cin >> x;
        stat[x] = 1;
        ans.insert(x);
    }

    int pos = 1;
    for(int i = 0;i < n; i++){
        if(i != 0 && s[i - 1] == 'B'){
            while(stat[pos] == 1) pos++;
        }
        if(s[i] == 'A') pos++;
        else{
            pos++;
            while(stat[pos] == 1) pos++;
        }
        stat[pos] = 1;
        // cout << pos << " ";
        ans.insert(pos);
    }
    // cout << endl;
    cout << ans.size() << endl;
    for(auto it : ans) cout << it << " ";
    cout << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
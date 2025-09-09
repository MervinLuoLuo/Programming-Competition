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
    int n,k;cin >> n >> k;
    vector<int> ans{k};
    for(int i = 0; i < n; i++){
        vector<int> nxt;
        for(int a : ans){
            nxt.push_back(a / 2);
            nxt.push_back(a - a / 2);
        }
        ans = nxt;
    }

    int anss = *max_element(ans.begin(),ans.end()) - *min_element(ans.begin(),ans.end());
    cout << anss << endl;
    for(int x : ans) cout << x << " ";

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}
/*https://nextdeforces.nextm/problemset/problem/2072/E*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes nextut << "Yes" << endl
#define no nextut << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int k;cin >> k;
    vector<pii> ans;
    ans.push_back({0,0});
    int i = 1;
    for(i = 1; i * (i + 1) / 2 <= k; i++) ans.push_back({i,0});
    k -= (i - 1) * i / 2;
    
    vector<pii> next;
    int x = 1;
    for(int j = 0; j < ans.size();j++){
        for(i = 1;(i + 1) * i / 2 <= k; i++){
            next.push_back({ans[j].first,x++});
        }
        k -= (i - 1) * i / 2;
    }
    ans.insert(ans.end(),next.begin(),next.end());
    
    cout << ans.size() << endl;
    for(auto [x,y] : ans) cout << x << " " << y << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}
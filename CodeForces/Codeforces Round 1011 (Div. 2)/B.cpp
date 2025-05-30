/*https://codeforces.com/contest/2085/problem/B*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
void solve(){
    int n;cin >> n;
    vector<int> a(n + 5);
    for(int i = 1; i<= n; i++)cin >> a[i];
    vector<pii> ans;
    if(a[1] == a[n] and a[1] ==0){
        ans.push_back({n - 1, n});
        a[n - 1] = 10;
        n--;
    }
    int cnt = 0;
    for(int i = 1; i <= n ; i++){
        if(a[i] == 0) cnt++;
    }
    if(cnt >= 2){
        int be = -1, ed = -1;
        for(int i = 1; i <= n ; i++){
            if(a[i] == 0) {
                if(be == -1) be = i;
                ed = i;
            }
        }
        ans.push_back({be,ed});
        ans.push_back({1,n - (ed - be)});
    }
    else if(cnt == 1){
        int pos = -1;
        for(int i =1 ; i<= n; i++){
            if(a[i] == 0) pos = i;
        }
        if(pos == 1) ans.push_back({1,2});
        else ans.push_back({pos-1,pos});
        ans.push_back({1,n-1});
    }
    else ans.push_back({1,n});
    cout << ans.size() << endl;
    for(auto it : ans) cout << it.first << " " << it.second << endl;
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
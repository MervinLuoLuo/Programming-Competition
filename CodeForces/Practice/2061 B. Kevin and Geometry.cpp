/*https://codeforces.com/problemset/problem/2061/B*/
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
    vector<int> a(n);
    for(int &x : a) cin >> x;
    sort(a.begin(),a.end(),greater<int>());
    int pos = -1;
    for(int i = 1; i < n; i++){
        if(a[i] == a[i - 1]) {pos = i;break;}
    }
    if(pos == -1){cout << -1 << endl;return;}
    vector<int> ans;
    ans.push_back(a[pos]);
    ans.push_back(a[pos]);
    int last = -1, cur = -1;
    int minx = maxn, p1 = -1, p2 = -1;
    for(int i = 0; i <n; i++){
        if(i == pos || i == pos - 1) continue;
        last = cur;cur = i;
        if(last == -1) continue;
        if(a[last] - a[cur] < minx){
            minx = a[last] - a[cur];
            p1 = last, p2 = cur;
        }
    }
    ans.push_back(a[p1]);ans.push_back(a[p2]);
    sort(ans.begin(),ans.end(),greater<int>());
    if(ans[0] < ans[1] + ans[2] + ans[3]){
        for(int i = 0; i < 4; i++) cout << ans[i] <<  " ";
        cout << endl;
    }
    else cout << -1 << endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    //t = 1;
    while(t--){
       solve();
    }
    return 0;
}
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
    vector<int> a;
    a.push_back(-1);
    for(int i = 1; i <= n; i++){
        int x;cin >> x;
        if(a.back() == x)continue;
        a.push_back(x);
    }
    a.push_back(-1);
    int ans= 0;
    for(int i = 1; i < a.size() - 1; i++){
        if(a[i - 1] < a[i] and a[i + 1] < a[i]) ans++;
    }
    cout << ans << endl;
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
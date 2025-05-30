#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
typedef long long ll;

void solve(){
    int n, l ,r;cin >> n >> l >> r;
    vector<int> L ,R;
    l--;
    for(int i = 0; i < n; i++){
        int x;cin >> x;
        if(i < r) L.push_back(x);
        if(i >= l) R.push_back(x);
    }
    sort(L.begin(),L.end());
    sort(R.begin(),R.end());
    ll ansl = accumulate(L.begin(),L.begin() + r - l, 0LL);
    ll ansr = accumulate(R.begin(),R.begin() + r - l, 0LL);
    cout << min(ansl,ansr) << endl;
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
/*https://ac.nowcoder.com/acm/contest/20960/1009*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int maxn = 1e9;

void solve(){
    int l, n;cin >> l >> n;
    vector<int> a(l + 1, 1);
    while(n--){
        int L,R;cin >> L >> R;
        for(int i = L; i <= R; ++i) a[i] = 0;
    }
    int ans = 0;
    ans = count(a.begin(),a.end(),1);
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}
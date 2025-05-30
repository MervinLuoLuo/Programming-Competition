/*https://ac.nowcoder.com/acm/contest/102742*/
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
    vector<int> v(3),a(3);
    for(int i = 0; i < 3; i++) cin >> v[i];
    for(int i = 0; i < 3; i++) cin >> a[i];
    int cnt = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3;j++){
            if(v[j] < a[i]){
                cnt++;
                break;
            }
        }
        //cout << cnt << ' ';
    }
    if(cnt < 2) no;
    else yes;
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
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define VII vector<vector<int>>
#define PII pair<int,int>
using namespace std;
using i128 = __int128;
constexpr int MAXN = 1e9;
constexpr int INF = 1e18;

void solve(){
    int T,s,t;cin >> T >> s >> t;
    if(T > 35 && s == 1 && t >= 33){
        cout << "Bu Tie" << endl;
        cout << T;
        return;
    }
    if(T > 35 && t >= 33 && s == 0){
        cout << "Shi Nei" << endl;
        cout << T;
        return;
    }
    if(s == 1 && (T <= 35 || t < 33)){
        cout << "Bu Re" << endl;
        cout << t;
        return;
    }
    if((T < 35 || t < 33) && s == 0){
        cout << "Shu Shi" << endl;
        cout << t;
    }

}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
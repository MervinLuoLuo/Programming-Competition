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
    int nh = 0,maxd = 0;
    for(int i = 1; i <= 7; i++){
        int x,y;cin >> x >> y;
        if(x + y > 8){
            int res  =x + y - 8;
            if(res > nh){   
                nh = res;maxd = i;
            }
        }
    }   
    cout << maxd << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}
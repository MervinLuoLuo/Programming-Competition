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
    int x,y,z;cin >> x >> y >> z;
    int a = 0,b = 0, c = 0;
    for(int i = 59; i >= 0; i--){
        bool flag = 0;
        int xx = x >> i & 1,yy = y >> i & 1,zz = z >> i & 1;
        for(int aa :{0,1}){
            for(int bb : {0,1}){
                for(int cc:{0,1}){
                    if(((aa & bb) == xx) && ((bb & cc) == yy) && ((cc & aa) == zz)){
                        flag = 1;
                        a |= aa << i;
                        b |= bb << i;
                        c |= cc << i;
                        break;
                    }
                    if(flag) break;
                }
                if(flag) break;
            }
            if(flag) break;
        }
        if(!flag){no;return;}
    }

    yes;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
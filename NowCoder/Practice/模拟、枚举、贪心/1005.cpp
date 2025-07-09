/*https://ac.nowcoder.com/acm/contest/20960/1005*/
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
    int n;cin >> n;
    vector<vector<char>> a(n + 5,vector<char>(n + 5));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    vector<vector<int>> ans(4,vector<int>(2));
    double len = 0.0, maxx = 0.0;
    for(int x1 = 1; x1 <= n; x1++){
        for(int y1 = 1; y1 <= n; y1++){
            if(a[x1][y1] == '#'){
                for(int x2 = 1; x2 <= n; x2++){
                    for(int y2 = 1; y2 <= n; y2++){
                        if(a[x2][y2] == '#'){
                            int x3 ,y3,x4,y4;
                            x3 = x1 + y2-y1;
                            y3=y1-(x2-x1);
                            x4 = x2 + y2-y1;
                            y4 = y2-(x2-x1);
                            if(x3 >= 1 and x3 <= n  and y3 >= 1 and y3 <= n and x4 >=1 and x4 <= n and y4 >= 1 and y4<=n and a[x3][y3] == '#' and a[x4][y4] == '#'){
                                len = (x1-x2) * (x1-x2) + (y1- y2) * (y1-y2);
                                if(len > maxx){
                                    maxx = len;
                                    ans[0][0] = x1;
                                    ans[0][1] = y1;
                                    ans[1][0] = x2;
                                    ans[1][1] = y2;
                                    ans[2][0] = x3;
                                    ans[2][1] = y3;
                                    ans[3][0] = x4;
                                    ans[3][1] = y4;
                                }
                            }
                        }
                    }
                }  
            }
        }
    }
    for(auto it : ans){
        for(auto p :it) cout << p << ' ';
        cout << endl;
    }
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
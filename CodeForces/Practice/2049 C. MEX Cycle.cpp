/*https://codeforces.com/problemset/problem/2049/C*/
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
    int n,x,y;cin >> n >> x >> y;
    vector<int> ans(n + 1, -1);

    if(n & 1){
        if(x == y + 1 || x == y - 1){
            ans[1] = 2;
            for(int i = 2;  i <= n; i++){
                if(i & 1) ans[i] = 0;
                else ans[i] = 1;
            }
        }    
        else{
            if(x != 1){
                if((x % 2) != (y % 2)){
                    ans[1] = 2;
                    for(int i = 2;  i <= n; i++){
                        if(i & 1) ans[i] = 0;
                        else ans[i] = 1;
                    }
                }
                else{
                    ans[x] = 2;
                    for(int i = x + 1; i <= n; i++){
                        if((i - x) & 1) ans[i] = 0;
                        else ans[i] = 1;
                    }
                    for(int i = x - 1;i >= 1; i--){
                        if((x - i) & 1) ans[i] = 1;
                        else ans[i] = 0;
                    }
                }
            }
            else{
                ans[1] = 2;
                for(int i = 2; i <= n; i++){
                    if(i & 1) ans[i] = 0;
                    else ans[i] = 1;
                }
            }
        }
    }

    else{
        for(int i = 1; i <= n; i++){
            if(i & 1) ans[i] = 0;
            else ans[i] = 1;
        }
        if((x % 2) == (y % 2)) {ans[x] = 2;}
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
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
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int maxn = 1e9;

void solve(){
    int n;cin >> n;
    vii sub(411,vector<int>(14, 0));
    while(n--){
        int a,b,c;cin >> a >> b >>c;
        if(sub[a][b] == 0){
            if(c < 240){
                cout << b << endl;
                sub[a][b] = 1;
                sub[a][0]++;
            }
            else{
                if(sub[a][0] < 3){
                    cout << b << endl;
                    sub[a][b] = 1;
                    sub[a][0]++;
                }
                else cout << 0 << endl;
            }
        }
        else cout << 0 << endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
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
    int n;cin >> n;
    vector<vector<char>> a(n + 5,vector<char>(n+ 5));
    for(int i = 1;i <= n; i++){
        int m = i;
        int b = n + 1 - i;
        for(int j = m; j <= b ; j++){
            for(int k = m; k <= b; k++){
                if(j >0 and k > 0 and j <= n and k <= n){
                    if(i % 2) a[j][k] = '#';
                    else a[j][k] = '.';
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cout << a[i][j];
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
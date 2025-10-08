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
    int n,k;cin >> n >> k;
    if(k > n * n - 2 && k ){
        if(k != n * n) no;
        else{
            yes;
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++) cout << 'U';
                cout << endl;
            }
        }
        return;
    }

    vii ans(n + 2,vector<int>(n + 2, 1));
    //设置循环
    ans[n][n] = 3,ans[n][n - 1] = 2;

    int need = n * n - 2 - k;
    bool flag = 1;
    for(int j = n - 2; j >= 1; j--){
        if(need == 0) break;
        ans[n][j] = 2;
        need--;
    }

    if(need){
        for(int i = n - 1;i >= 1; i--){
            for(int j = n;j >= 1; j--){
                if(need == 0){flag = 0;break;}
                ans[i][j] = 4;
                need--;
            }
            if(!flag) break;
        }
    }

    yes;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(ans[i][j] == 1) cout << 'U';
            else if(ans[i][j] == 2) cout << 'R';
            else if(ans[i][j] == 3) cout << 'L';
            else cout << 'D';
        }
        cout << endl;
    }
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
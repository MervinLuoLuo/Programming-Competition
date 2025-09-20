#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define vii vector<vector<int>>
const int MAXN = 1e8;
const int INF = 1e18;

void solve(){
    int n,m;cin >> n >> m;
    n++,m++;
    if(n < m){
        int base = n -  1;
        int h = (n / 2) + (n & 1 ? 1 : 0);
        vii a(h + 5,vector<int>(h + 5,0));

        a[1][1] = base;
        int add = n - 2;
        for(int i = 2; i <= h; i++) {
            a[i][1] = a[i - 1][1] + add;
            add -= 2;
        }

        add = n - 2;
        for(int j = 2; j <= h; j++) {
            a[1][j] = a[1][j - 1] + add;
            add -= 2;
        }

        for(int i = 2; i <= h ; i++){
            add = n - 2;
            for(int j = 2; j <= h; j++){
                a[i][j] = a[i][j - 1] + add;
                add -= 2;
            }
        }
        

    }
    else{

    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    VII a(2,vector<int>(n, 0));
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> a[0][i];
        cnt += a[0][i];
    }

    for(int i = 0; i < n; i++){
        cin >> a[1][i];
        cnt += a[1][i];
    }
    
    if(n % 2 == 0){
        int b = 0,c = 0,d = 0;
        for(int i = 0; i < n; i++) b += a[1][i];
        for(int i = 0; i < n / 2; i++){
            c += a[1][n - i - 1];
            c += a[0][n - i - 1];
        }
        for(int i = 0; i < n / 2 - 1; i++){
            d += a[1][n - i - 1];
            d += a[0][n - i - 1];
        }
        b = min(b,c);
        d = max(b,d);
        if(cnt - d > d) cout << "Mandy" << endl;
        else if(cnt - d == d) cout << "draw" << endl;
        else cout << "brz" << endl;
    }
    else{
        int b = 0,c = 0,d = 0;
        for (int i = 0;i < n;i++) b += a[0][i];
        for (int i = 0;i < n / 2 + 1;i++){
            c += a[0][i];
            c += a[1][i];
        }
        for (int i = 0;i < n / 2;i++){
            d += a[0][i];
            d += a[1][i];
        }
        b = min(b,c);
        d = max(b,d);
        if (cnt-d>d){
            cout<<"brz\n";
        }
        else if (cnt-d==d)
        {
            cout<<"draw\n";
        }else
        {
            cout<<"Mandy\n";
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
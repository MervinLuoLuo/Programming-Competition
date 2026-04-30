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
    VII a(2,vector<int>(n + 1));
    int l1 = 0;
    int sum = 0;
    
    for(int i = 1; i <= n; i++){
        cin >> a[0][i];
        sum += a[0][i];
        l1 += a[0][i];
    }
    for(int i = 1; i <= n; i++){
        cin >> a[1][i];
        sum += a[1][i];
    }

    if(n & 1){
        // 奇数时，抉择方为 brz, 计算 Mandy 最大得分
        int b1 = 0,b2 = 0;
        for(int i = 1; i <= n / 2; i++) b2 += a[0][i] + a[1][i];
        b1 = b2 + a[0][n / 2 + 1] + a[1][n / 2 + 1];
        int maxa = min(b1,l1);
        int maxs = max(maxa, b2);
        if(maxs > sum - maxs) cout << "Mandy" << endl;
        else if(maxs == sum - maxs) cout << "draw" << endl;
        else cout << "brz" << endl;
    }
    else{
        // 偶数时，抉择方为 Mandy，计算 brz 最大得分
        int b1 = 0,b2 = 0;
        for(int i = n / 2 + 2; i <= n; i++) b2 += a[0][i] + a[1][i];
        b1 = b2 + a[0][n / 2 + 1] + a[1][n / 2 + 1];
        int maxb = min(b1,sum - l1);
        int maxs = max(maxb, b2);
        if(sum - maxs > maxs) cout << "Mandy" << endl;
        else if(sum - maxs == maxs) cout << "draw" << endl;
        else cout << "brz" << endl;
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
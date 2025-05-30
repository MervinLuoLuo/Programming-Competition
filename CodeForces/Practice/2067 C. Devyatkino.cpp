/*https://codeforces.com/problemset/problem/2067/C*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

bool check(int n){
    while(n){
        if(n % 10 == 7) return 1;
        n /= 10;
    }
    return 0;
}

void solve(){
    int n;cin >> n;
    if(check(n)){cout << 0 << endl;return;}
    int ans = 9;
    for(int i = 1; i <= 9; i++){
        int tmp = n;
        for(int j = 1; j <= 9; j++){
            tmp += pow(10,i) - 1;
            if(check(tmp)){
                ans = min(ans,j);
                break;
            }
        }
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}
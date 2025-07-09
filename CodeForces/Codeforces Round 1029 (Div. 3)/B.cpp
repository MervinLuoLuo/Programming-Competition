#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> p(n + 5);
    if(n & 1){
        int x = 1;
        for(int i = 1; i <= n/2 + 1; i++){
            p[i] = x;
            x += 2;
        }
        x = 2;
        for(int i = n;i > n / 2 + 1; i--){
            p[i] = x;
            x += 2;
        }
    }
    else{
        int x = 1;
        for(int i = 1; i <= n / 2; i++){
            p[i]= x;
            x +=2;
        }
        x = 2;
        for(int i = n; i > n / 2; i--){
            p[i] = x;
            x +=2;
        }
    }
    for(int i  = 1; i <= n; i++) cout << p[i] << " ";
    cout << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
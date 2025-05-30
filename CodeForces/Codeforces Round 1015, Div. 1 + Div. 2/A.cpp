#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "-1" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n;cin >> n;
    if(n % 2 == 0) {no;return;}
    cout << n << " ";
    for(int i = 1; i <= n - 1; i++){
        cout << i << " ";
    }
    cout << endl;
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
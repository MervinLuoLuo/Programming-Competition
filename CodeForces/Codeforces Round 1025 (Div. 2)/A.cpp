#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i <n ;i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum == n){yes;return;}
    for(int i = 0; i < n - 1; i++){
        if(a[i] == 0 && a[i + 1] == 0) {yes;return;}
    }
    no;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    //t = 1;
    while(t--){
       solve();
    }
    return 0;
}
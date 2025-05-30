#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
typedef long long ll;

void solve(){
    int n;cin >> n;
    for(int i = n; i >= 0; i--){
        int a;cin >> a;
        if(a){
            if(i != n and a > 0) cout << '+';
            if(abs(a) == 1 or i == 0) cout << a;
            if(a == -1 and i) cout << '-';
            if(i > 1) cout << "x^" << i;
            if(i == 1) cout << 'x';
        }
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
#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
#define pii pair<int,int>
using namespace std;
const int maxn = 1e9;
// const int INF = 1e19;

int check(int m,int d){
    if(m > 7 || (m == 7 && d > 11)) return 0;
    else if(m < 6 || (m == 6 && d <= 20)) return 1;
    else return 2;
}

void solve(){
    int n;cin >> n;
    for(int i  =0; i < n; i++){
        int m ,d ,c;cin >> m >> d >> c;
        int ans = check(m,d);
        if(ans == 0) {cout << "Too late!" << endl;}
        else if(ans == 1){
            if(c < 1800) cout << "Need more!" << endl;
            else if(c == 1800) cout << "Ok!" << endl;
            else cout << "^_^" << endl;
        }
        else{
            if(c < 2000) cout << "Need more!" << endl;
            else if(c == 2000) cout << "Ok!" << endl;
            else cout << "^_^" << endl;
        }
    }
}

signed main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n; cin >> n;
    if(n == 11){
        cout << "Yes" << endl;
        cout << "0 0 0 8 7 6 1 2 3 4 5 0" << endl;
    } else if(n == 22){
        cout << "Yes" << endl;
        cout << "0 0 1 8 7 6 1 2 3 4 5 0" << endl;
    } else if(n == 33){
        cout << "Yes" << endl;
        cout << "0 2 1 8 7 6 1 2 3 4 5 0" << endl;
    } else if (n <= 8){
        cout << "Yes" << endl;
        if(n == 1) cout << "0 0 0 0 0 0 0 0 0 0 0 0" << endl;
        if(n == 2) cout << "0 0 0 0 0 0 0 0 0 0 0 1" << endl;
        if(n == 3) cout << "0 0 0 0 0 0 0 0 0 0 2 1" << endl;
        if(n == 4) cout << "0 0 0 0 0 0 0 0 0 3 2 1" << endl;
        if(n == 5) cout << "0 0 0 0 0 0 0 0 4 3 2 1" << endl;
        if(n == 6) cout << "0 0 0 0 0 0 0 5 4 3 2 1" << endl;
        if(n == 7) cout << "0 0 0 0 0 6 0 5 4 3 2 1" << endl;
        if(n == 8) cout << "0 0 0 0 7 6 0 5 4 3 2 1" << endl;
    } else{
        cout << "No" << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) solve();
    return 0;
}
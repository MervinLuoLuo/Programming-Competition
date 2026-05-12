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
    int a,b;cin >> a >> b;
    if(a > b){
        if(a == 30) cout << "Alice";
        else if(a >= 21 && a - b >= 2) cout << "Alice";
        else cout << "Underway";
    }
    else if (a < b){
        if(b == 30) cout << "Bob";
        else if(b >= 21 && b - a >= 2) cout << "Bob";
        else cout << "Underway";
    }
    else cout << "Underway";
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    if(n % 495 == 0) {
        cout << -1;
        return;    
    }

    int rem = n % 495,p = 1;
    for(int len = 1; len <= 3; len++){
        p *= 10;
        int x = (495 - rem * p % 495) % 495;
        if(x < p){
            cout << setw(len) << setfill('0') << x << endl;
            return;
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
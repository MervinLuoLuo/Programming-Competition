#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

void solve(){
    int n;cin >> n;
    vector<vector<bool>> M(17);
    vector<bool> used(17,0);
    for(int p = 1; p <= 16; p++){
        M[p].assign(p, 1);
    }
    for(int i = 0; i < n; i++){
        string s;cin >> s;
        int p = s.size();
        used[p] = 1;
        for(int j = 0; j < p; j++){
            if(s[j] == '0') M[p][j] = 0;
        }
    }
    for(int p = 1; p <= 16; p++){
        if(!used[p]) continue;
        bool any = 0;
        for(int r = 0; r < p; r++){
            if(M[p][r]){ any = 1; break;}
        }
        if(!any){
            cout << -1 << endl;
            return;
        }
    }
    int L = 1;
    for(int p = 1; p <= 16; p++){
        if(used[p]) L = lcm(L, p);
    }
    for(int t = 1; t <= L; t++){
        bool ok = 1;
        for(int p = 1; p <= 16; p++){
            if(!used[p]) continue;
            int r = t % p;
            if(r == 0) r = p;
            if(!M[p][r-1]){
                ok = 0;
                break;
            }
        }
        if(ok){
            cout << t << endl;
            return;
        }
    }
    cout << -1 << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    while(t--){
       solve();
    }
    return 0;
}

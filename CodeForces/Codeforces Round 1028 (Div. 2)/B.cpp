#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
const int mod = 998244353;
vector<int> qpow(1e6);

void qupow(){
    qpow[0] = 1;
    for(int i = 1; i <= 1e5 + 5; i++){
        qpow[i] = (qpow[i - 1] * 2) % mod;
    }
}

void solve(){
    int n;cin >> n;
    vector<int> p(n),q(n);
    for(int &x : p) cin >> x;
    for(int &x : q) cin >> x;
    vector<int> P(n),Q(n);
    P[0] = Q[0] = 0;
    for(int i = 1; i < n; i++){
        if(p[i] > p[P[i-1]]) P[i] = i;
        else P[i] = P[i - 1]; 

        if(q[i] > q[Q[i - 1]]) Q[i] = i;
        else Q[i] = Q[i - 1];
    }

    vector<int> ans;
    for(int i = 0; i < n; i++){
        int x = P[i],y = Q[i];
        int res = 0;
        if(p[x] > q[y]) res = qpow[p[x]] + qpow[q[i - x]];
        else if(p[x] < q[y]) res= qpow[q[y]] + qpow[p[i-y]];
        else {
            if(p[i-y] < q[i - x]) res = qpow[p[x]] + qpow[q[i - x]];
            else res = qpow[q[y]] + qpow[p[i - y]];
        }
        ans.push_back(res % mod);
    }
    for(auto it : ans) cout << it << " ";
    cout << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    // qpow.resize(1e5 + 5);
    qupow();
    while(t--){
        solve();
    }
    return 0;
}
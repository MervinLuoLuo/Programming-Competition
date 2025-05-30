#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const ll maxn = 1e8 + 10;
const ll INF = 1e17;
    
    bool NotPrim[maxn + 10] = {};
    vector<ll> primes;
void ols(int n){
for(int i = 2; i <= n; i++){
        if(!NotPrim[i]) primes.push_back(i);
        for(int j = 0; j < primes.size() && i * primes[j] <= n; j++){
            NotPrim[i*primes[j]] = 1;
            if(i % primes[j] == 0) break;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q;cin >> n >> q;
    ols(n);
    while(q--){
        int k;cin >> k;
        k--;
        cout << primes[k] << endl;
    }
    return 0;
}
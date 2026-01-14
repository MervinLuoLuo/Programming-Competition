#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n,k;cin >> n >> k;
    vector<int> a(k, 0);
    int p = 0;
    
    if(k & 1){
        for(int i = 0; i < k; i++) a[i] = n;
    }
    else{
        for(int i = 30; i >= 0; i--){
            if(n >> i & 1){
                for(int j = 0; j < k; j++){
                    if(j != min(p,k - 1)){
                        a[j] += (1ll << i);
                    }
                }
                if(p < k) p++;
            }
            else{
                for(int j = 0; j < p / 2 * 2; j++) a[j] += (1ll << i);
            }
        }
    }
    for(int x : a) cout << x << " ";
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
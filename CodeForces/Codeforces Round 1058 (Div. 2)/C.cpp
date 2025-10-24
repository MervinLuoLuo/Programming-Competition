#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

int n;
vector<int> bits;
vector<int> pathl,pathr;
// void dfs(int cur){
//     if(pathl.size() == bits.size()){
        
//     }
// }

void solve(){
    cin >> n;
    while(n){
        bits.push_back(n & 1);
        n >>= 1;
    }

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
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

int is_com[maxn];
vector<int> prime;

void Prime(int a,int b){
    for(int i = 2; i <= b; i++){
        if(!is_com[i]) prime.push_back(i);
        for(int p : prime){
            if (1LL * i * p > maxn) break;
            is_com[i * p] = true;
            if (i % p == 0) break;
        }
    }
}

void solve(){
    int a,b;cin >> a >> b;
    Prime(a,b);
    vector<int> res;
    for(int p : prime){
        
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}
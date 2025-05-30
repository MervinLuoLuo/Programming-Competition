/*https://www.luogu.com.cn/problem/P1088*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n,m;
    cin >> n;
    cin >> m;
    vector<int> a(n);
    for(int i =0; i < n; i++) cin >> a[i];
    
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}
/*void solve(){ next_permutaion version
    int n,m;
    cin >> n;
    cin >> m;
    vector<int> a(n);
    for(int i =0; i < n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) next_permutation(a.begin(),a.end());
    for(auto it : a) cout << it << " ";
}*/
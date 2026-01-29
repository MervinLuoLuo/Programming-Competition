/*https://codeforces.com/contests/2188*/
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
    vector<int> a(n + 1, 0);
    if(n % 2){
        int l = n / 2 + 1,r = n / 2;
        for(int i = 1; i <= n; i += 2)a[i] = l++;
        
        for(int i = 2; i <= n; i += 2) a[i] = r--;
    }
    else{
        int l = n / 2,r = n / 2 + 1;
        for(int i = 1;i <= n; i+= 2) a[i] = l--;
        for(int i = 2; i <= n; i += 2) a[i] = r++; 
    }
    for(int i = 1; i <= n; i++)cout << a[i] << " ";
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
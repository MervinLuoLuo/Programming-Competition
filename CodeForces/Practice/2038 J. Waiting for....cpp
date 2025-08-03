/*https://codeforces.com/problemset/problem/2038/J*/
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
int wait = 1;
void solve(){
    char c;
    int x;
    cin >> c >> x;
    if(c == 'P') wait += x;
    else{
        if(x >= wait) yes;
        else no;
        wait = max(wait - x, 1LL);
        if(wait == 0) wait++;
    }
    // cout << wait << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
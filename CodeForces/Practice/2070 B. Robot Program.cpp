/*https://codeforces.com/problemset/problem/2070/B*/
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
    int n,x,k;cin >> n >> x >> k;
    string s;cin >> s;
    int step1 = n + 1,step2 = k + 1;
    for(int i = 0,move = 0; i < n; i++){
        if(s[i] == 'L') x--,move--;//move记录从 0 开始的状态
        else x++,move++;
        if(move == 0 and step2 == k + 1)step2 = i + 1;//0-base 得 +1
        if(x == 0 and step1 == n + 1) step1 = i + 1;
    }
    int ans = 0;
    if(step1 != n + 1 and k >= step1) ans = 1 + (k - step1) / step2;
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
constexpr double eps = 1e-5;

void solve(){
    double a,b;cin >> a >> b;
    string ans = "";
    int cnt = 0;
    while(a >= eps && cnt < 50){
        cnt++;
        a *= 0.5;
        cout << "1";
    }
    double s = 0.5;
    while(b >= eps){
        if(b >= s) {
            ans += '2';
            b -= s; 
        }
        else ans += '1';
        s *= 0.5;
    }
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
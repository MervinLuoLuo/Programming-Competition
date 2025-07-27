#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int n;
string s;
vector<bool> flag;

int calc(){
    int sum = 0, res = 0;
    if(flag[n - 1]){
        for(int i = n - 1; i >= 0; i--){
            if(flag[i]) {sum++;flag[i] = 0;}
            else break;
        }
        for(int i = 0; i < n; i++){
            if(flag[i]){sum++;flag[i] = 0;}
            else break;
        }
        res +=(sum + 1) >> 1;
        sum = 0;
    }
    for(int i = 0; i < n; i++){
        if(flag[i]) sum++;
        else {res += (sum + 1) >> 1;sum = 0;}
    }
    res += (sum + 1) >> 1;
    return res;
}

void solve(){
    cin >> n;
    cin >> s;
    int ans = n;
    flag.assign(n,0);
    for(int i = 0; i < n; i++){
        flag[i] = (s[i] - '0') ^ (i & 1);
    }

    ans = min(ans,calc());
    for(int i = 0; i < n; i++){
        flag[i]= (s[i] - '0') ^ ((i + 1) & 1);
    }
    ans = min(ans,calc());
    cout << ans <<  endl;
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
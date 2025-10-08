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

void solve(){
    int n,k;cin >> n  >> k;
    string s;cin >> s;

    if(n == k){
        for(int i = 1; i <= n; i++) cout << '-';
        cout <<endl;
        return;
    }
    
    int cnt0 = 0,cnt1 = 0,cnt2 = 0;
    for(char c : s){
        if(c == '0')cnt0++;
        else if(c == '1') cnt1++;
        else cnt2++;
    }

    vector<int> ans(n + 1, 1);
    int l = 1;
    for(l = 1; l <= n; l++){
        if(cnt0 == 0) break;
        ans[l] = 0;
        cnt0--;
    }

    int r = n;
    for(r = n;  r >= 1; r--){
        if(cnt1 == 0) break;
        ans[r] = 0;
        cnt1--;
    }

    while(cnt2--){
        ans[l++] = 2,ans[r--] = 2;
    }

    for(int i = 1; i <= n; i++){
        if(ans[i] == 0) cout << '-';
        else if(ans[i] == 1) cout << '+';
        else cout << '?';
    }
    cout << endl;
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
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
    int n;cin >> n;
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end(), greater<int>());
    vector<int> pre(n + 1, 0);
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];

    vector<int> ans;
    for(int k = 1; k <= n; k++){
        if(k == 1 || k == 2) {ans.push_back(0);continue;}
        int sum = pre[k];
        int maxe = a[1];

        int l = 1;
        while(maxe >= sum - maxe && k - l + 1 > 2){
            sum -= maxe;
            l++;
            maxe = a[l];
        }

        if(maxe < sum - maxe) ans.push_back(sum);
        else ans.push_back(0);
    }

    for(auto it : ans ) cout << it << " ";
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
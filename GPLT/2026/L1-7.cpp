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
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    cout << *max_element(a.begin() + 1,a.end()) << " ";
    cout << *min_element(a.begin() + 1,a.end()) << " ";
    int avg = sum / n;
    cout << avg << endl;
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        if(a[i] > (avg * 2)) ans.push_back(i);
    }
    if(ans.size() == 0) cout << "Normal";
    else{
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i];
            if(i != ans.size() - 1) cout << " ";
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
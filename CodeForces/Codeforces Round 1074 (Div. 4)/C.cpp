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
    set<int> st;
    for(int i = 0; i < n; i++){
        int x;cin >> x;
        st.insert(x);
    }
    vector<int> a;
    for(auto it : st){
        a.push_back(it);
        // cerr << it << " ";
    }
    n = a.size();

    int len = 1;
    int l = 0;
    for(int r = 1; r < n; r++){
        if(a[r] - a[r - 1] > 1){
            len = max(len, r - l);
            l = r;
        }
    }
    len = max(len, n - l);
    
    cout << len << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
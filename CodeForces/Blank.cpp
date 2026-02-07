#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

int func(int n,const vector<int> &a){
    int res = 0, cur = 0;
    set<int> st;
    for(int i = 0; i < n; i++){
        if(st.count(a[i]) == 0){
            st.insert(a[i]);
            cur++;
        }
        res += cur;
    }

    return res;
}

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1);
    for(int i =1; i <= n; i++) cin >> a[i];

    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            vector<int> sub;
            cout << "[";
            for(int k = i; k <= j; k++){
                sub.push_back(a[k]);
                cout << a[k] << " ";
            }
            int res = func(sub.size(),sub);
            cout << "]: " << res << endl;
            ans += res;
        }
    }

    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
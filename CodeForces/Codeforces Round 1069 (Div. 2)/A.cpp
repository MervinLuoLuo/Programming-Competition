/*https://codeforces.com/contest/2175*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<int,int>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    set<int> st;
    for(int i = 0 ; i < n; i++){
        int x;cin >> x;
        st.insert(x);
    }

    int cur = st.size();
    int ans = 0;
    while(1){
        if(find(st.begin(),st.end(),cur) != st.end()){
            ans = cur;
            break;
        }
        cur++;
    }
    cout << ans << endl;
}  

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
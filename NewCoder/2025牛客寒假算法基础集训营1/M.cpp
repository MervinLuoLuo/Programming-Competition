/*https://ac.nowcoder.com/acm/contest/95323*/
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1);
    vector<pii> p;
    multiset<int> st;
    for(int i = 1; i <= n; i++){
         cin >> a[i];
         p.push_back({a[i],i});
         st.insert(a[i]);
    }
    sort(p.begin(),p.end());
    auto [l,r] = p[0];
    auto it = st.find(l);
    st.erase(it);
    st.insert(l * 2);
    int ans = *st.rbegin() - *st.begin();
    l = r;
    for(auto &[_,i] : p){
        if(i >= l and i <= r) continue;
        for(int j = l - 1; j >= i; j--){
            auto it = st.find(a[j]);
            st.erase(it);
            st.insert(a[j] * 2);
            ans = min(ans, *st.rbegin() - *st.begin());
        }
        l = min(l, i);
        for(int j = r + 1; j <= i; j++){
            auto it = st.find(a[j]);
            st.erase(it);
            st.insert(a[j] * 2);
            ans = min(ans,*st.rbegin() - *st.begin());
        }
        r = max(r,i);
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}
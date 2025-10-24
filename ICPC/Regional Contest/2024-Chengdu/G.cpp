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
    vector<int> a(n);
    for(int &x : a) cin >> x;
    set<int> st;
    for(int i = 1; i < n; i++){
        int x =a[i - 1], y = a[i];
        st.insert(x);st.insert(y);
        int b = x & y,c=x | y,d=x ^ y;
        st.insert(b);st.insert(c);st.insert(d);
        st.insert((x & d));st.insert((y & d));
        st.insert(0);
    }
    cout << st.size() << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}
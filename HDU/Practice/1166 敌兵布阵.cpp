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

template<typename T>
struct BIT{
#ifndef lowbit
#define lowbit(x) (x & (-x))
#endif
    static const int MAX_SIZE = 1e3 + 50;
    int n;
    vector<T> t;

    BIT<T> () {}
    BIT<T> (int _n): n(_n), t(_n + 1,0) {}
    BIT<T> (int _n, const vector<T> &a): n(_n),t(_n + 1,0) {
        /* 从 1 开始 */
        for (int i = 1; i <= n; ++ i){
            t[i] += a[i];
            int j = i + lowbit(i);
            if (j <= n) t[j] += t[i];
        }
    }

    void add(int i, T x){
        while (i <= n){
            t[i] += x;
            i += lowbit(i);
        }
    }

    /* 1-index */
    T sum(int i){
        T ans = 0;
        while (i > 0){
            ans += t[i];
            i -= lowbit(i);
        }
        return ans;
    }
    /* 1-index [l, r] */
    T sum(int i, int j){
        return sum(j) - sum(i - 1);
    }

};

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1,0);
    for(int i = 1; i <= n; i++) cin >> a[i];

    BIT<int> bit(n,a);
    string s;
    while(cin >> s){
        if(s == "End") return;
        int x,y;cin >> x >> y;
        if(s[0] == 'Q') cout << bit.sum(x,y) << endl;
        else if(s[0] == 'A') bit.add(x,y);
        else if(s[0] == 'S') bit.add(x,-y);
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    int i = 1;
    while(t--){
        cout << "Case " << i << ":" << endl;
        solve();
        i++;
    }
    return 0;
}
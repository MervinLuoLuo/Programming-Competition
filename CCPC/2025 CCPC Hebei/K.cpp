#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n,m;cin >> n >> m;
    vector<int> a(n + 1),L(n + 1),R(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    string s;cin >> s;
    R[n] = 1,L[1] = n;
    for(int i = 2; i <= n; i++) L[i] = i - 1;
    for(int i = 1; i < n; i++) R[i] = i + 1;
    int stat = 0; // 0 顺 1 逆
    int cur = 1;
    
    auto getnext = [&](int x) -> int{
        if(stat == 0) return R[x];
        return L[x];
    };

    auto del = [&](int x){
        int l = L[x],r = R[x];
        L[r] = l;
        R[l] = r;
        L[x] = 0,R[x] = 0;
    };

    for(char c : s){
        int last = cur;
        if(c == 'C') cur = getnext(cur);
        else if(c == 'S'){
            cur = getnext(cur);
            cur = getnext(cur);
        }
        else if(c == 'R'){
            if(stat == 0) stat = 1;
            else stat = 0;
            cur = getnext(cur);
        }
        else{
            cur = getnext(cur);
            a[cur] += 2;
            cur = getnext(cur);
        }
        a[last]--;
        if(a[last] == 0) del(last);
    }
    // for(int i = 1; i <= n; i++){
    //     cerr << i << " " << L[i] << " " << R[i] << endl;
    // }
    for(int i = 1; i <= n; i++) cout << a[i] << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
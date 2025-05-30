#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e13;
const int maxn = 1e9;

void solve(){
    int n,k;cin >> n >> k;
    string s;cin >> s;
    vector<int> a(n,-INF);
    int pos = -1;
    for(int i = 0; i < n; i++){
        int x;cin >> x;
        if(s[i] == '1') a[i] = x;
        else pos = i;
    }
    int maxs = 0, cur = 0;

    //求最大连续子数组和(Kadane算法)
    for(int i = 0; i < n ; i++){
        cur = max(cur + a[i],a[i]);
        maxs = max(maxs,cur);
    }

    if(maxs > k or (maxs != k and pos == -1)){  
        no;return;
    }

    //全是 1 且符合题意就不用这一坨了
    if(pos != -1){
        maxs = 0, cur = 0;
        int l ,r;
        for(int i = pos + 1; i < n; i++){
            cur += a[i];
            maxs = max(cur,maxs);
        }
        l = maxs;

        maxs = 0,cur = 0;
        for(int i = pos - 1; i >= 0; i--){
            cur += a[i];
            maxs = max(maxs,cur);
        }
        r = maxs;

        a[pos] = k - l - r;
    }

    yes;
    for(int i = 0; i< n; i++) cout << a[i] << " ";
    cout << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}
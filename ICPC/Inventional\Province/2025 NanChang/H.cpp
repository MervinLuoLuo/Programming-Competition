#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1),c(n + 1);
    bool flag = 1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        c[i] = a[i] - i;
        if(a[i] < i) flag = 0;
    }

    // for(int i = 1; i <= n; i ++){
    //     cerr << c[i] << " ";
    // }
    // cerr << endl << endl;

    if(flag == 0){
        cout << -1 << endl;
        return;
    }

    int cur = 1;
    vector<int> b = {-1};
    b.push_back(1);
    int diff = a[1] - b[1];

    vector<int> suf(n + 1);
    suf[n] = n;
    // cerr << suf[n] << " ";
    for(int i = n - 1; i >= 1; i--){
        if(c[i] <= c[suf[i + 1]]){
            suf[i] = i;
        }
        else suf[i] = suf[i + 1];
        // cerr << suf[i] << " ";
    }
    // cerr << endl;

    for(int i = 2; i <= n; i++){
        cur++;
        int tar = a[suf[i]] - suf[i] + i;
        // cerr << "----------------" << endl;
        // cerr << "i: " << i << " " << "tar: " << tar << endl;
        // cerr << "diff: " << diff << " " << "cur: " << cur << endl;
        if(tar > cur + diff){
            cur += diff;
            diff = 0;
            b.push_back(cur);
            diff += a[i] - b[i];
        }
        else{
            b.push_back(tar);
            diff -= (tar - cur);
            diff += a[i] - b[i];
            cur = tar;
        }
    }

    // for(int i = 1; i <= n; i++) cerr << suf[i] << " ";
    // cerr << endl;

    // for(int i = 1; i <= n; i++) cerr << b[i] << " ";
    // cerr << endl;

    int ans = cur;
    // for(int i = 1; i <= n; i++){
    //     if(a[i] - b[i] != 0) ans += a[i] - b[i];
    // }

    cout << ans+diff<< endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}

/*
1 2 4 5 5 8 10 9
0 0 1 1 0 2 3 1 

----------------
i: 2 tar: 2
diff: 0 cur: 2
----------------
i: 3 tar: 4
diff: 0 cur: 3
----------------
i: 4 tar: 5
diff: 1 cur: 4
----------------
i: 5 tar: 5
diff: 0 cur: 6
----------------
i: 6 tar: 7
diff: 1 cur: 6
----------------
i: 7 tar: 8
diff: 1 cur: 8
----------------
i: 8 tar: 9
diff: 3 cur: 9
1 2 3 8 5 8 8 8 
1 2 3 5 5 7 8 9 


*/
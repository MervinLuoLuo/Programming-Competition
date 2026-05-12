/*https://qoj.ac/contest/3729/problem/17342*/
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
    int n;cin >> n;
    vector<int> a(n + 1),b(n + 1);
    bool flag = 1;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(i != 1 && a[i] != a[i - 1]) flag = 0;
    }
    if(flag){
        cout << 0 << endl;
        return;
    }
    
    b = a;
    int sum = accumulate(a.begin(),a.end(),0ll);
    if(sum % n != 0){
        cout << -1 << endl;
        return;
    }
    int base = sum / n;
    int ans = -1;
    if(n % 2 == 0){
        int ans1 = INF,ans2 = INF;
        // 按 [1,2] [3,4] ... [n - 1,n]
        for(int i = 1; i < n - 1; i += 2){
            if(a[i] + a[i + 1] != base * 2){
                int need = base * 2 - (a[i] + a[i + 1]);
                a[i + 1] += need;
                a[i + 2] -= need;
                if(ans1 == INF) ans = 0;
                ans1 += need;
            }

            if(a[i] == a[i + 1]) continue;
            if(ans1 == INF) ans1 = 0;
            int d = base - a[i];
            a[i] = a[i + 1] = base;
            ans1 += abs(d);
            cerr << "----------------" << endl;
            cerr << ans1 << endl;
        }
        if(a[n] + a[n - 1] != base * 2) ans1 = INF;
        if(a[n] != a[n - 1] && (a[n] + a[n - 1] == base * 2)){
            int d = (a[n] - a[n - 1]) / 2;
            a[n] = a[n - 1] = base;
            if(ans1 == INF) ans1 = 0;
            ans1 += abs(d);
        }
        // 按 [1] [2,3] ... [n - 2,n - 1] [n]
        if(b[1] != base){
            int need = base - b[1];
            b[1] += need;
            b[2] -= need;
            if(ans2 == INF) ans2 = 0;
            ans2 += need;
        }
        for(int i = 2; i <= n - 2; i += 2){
            if(b[i] + b[i + 1] != base * 2){
                int need = base * 2 - (b[i] + b[i + 1]);
                b[i + 1] += need;
                b[i + 2] -= need;
                if(ans2 == INF) ans2 = 0;
                ans2 += need;
            }
            
            if(b[i] == b[i + 1]) continue;
            if(ans2 == INF) ans2 = 0;
            int d = (b[i] - b[i + 1]) / 2;
            b[i] = b[i + 1] = base;
            ans2 += abs(d);
        }

        if(b[n] != base) ans2 = INF;
        cerr << "----------------" << endl;
        cerr << ans1 << " " << ans2 << endl;
        ans = min(ans1,ans2);
    }
    else{

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
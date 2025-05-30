#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        int h = n / 2;
        int lmid = a[h / 2];
        int rmid = a[h + h / 2];
        int ans = INF;
        for(auto lp : {lmid, lmid - 1}){
            for(auto rp :{rmid, rmid+ 1}){
                if(lp == rp) continue;
                int res = 0;
                for(int i = 0; i < h; i++){
                    res += abs(a[i] - lp);
                    res += abs(a[h + i] - rp);
                }
                ans = min(ans, res);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
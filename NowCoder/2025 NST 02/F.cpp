#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

class Node{
    public:
    int stat = 0;
    int t = -1;
};
void solve(){
    int n,t;cin >> n >> t;
    string s;cin >> s;
    
    //环形数组处理
    vector<int> a(2 * n + 5);
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            a[max(i - t, 0LL)]++;
            a[min(i + t + 1,2*n)]--;
            a[max(i + n - t,0LL)]++;
            a[min(i + n + t + 1,2 * n)]--;
        }
    }

    for(int i = 0; i < 2 * n; i++) a[i + 1] += a[i];
    int ans = 0;
    for(int i = 0; i <n ; i++){
        if(a[i] == 0 && a[i + n] == 0) ans++;
    }

    int cnt = 0, res = 0;
    for(int i = 0; i <2 * n ;i++){
        if(s[i % n] == '1') cnt=0;
        else cnt++;
        res = max(res,cnt);
    }

    cout << ans + max(max(0LL, res - t - 1) - max(0LL, res - 2 * t), 0LL) << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
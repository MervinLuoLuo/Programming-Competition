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

struct Num{
    int cnt = 0;
    int last = 0;
};

void solve(){
    int n;cin >> n;
    vector<int> b(n);
    vector<Num> num(n + 1);
    for(int i = 0; i < n; i++){
        cin >> b[i];
        num[b[i]].cnt++;
    }

    for(int i = 0; i < n; i++){
        if(num[b[i]].cnt % b[i]) {cout << -1 << endl;return;}
    }

    int cur = 1;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        if(num[b[i]].cnt % b[i] != 0 && num[b[i]].cnt != 0){
            a[i] = num[b[i]].last;
        }
        else{
            a[i] = cur;
            num[b[i]].last = cur;
            cur++;
        }
        num[b[i]].cnt--;
    }
    for(auto it : a) cout << it << " ";
    cout << endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
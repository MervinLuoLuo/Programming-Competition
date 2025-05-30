#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >>a[i];
    vector<int> bitc(30, 0);
    //算 1 的个数
    for (int x : a) {
        for (int i = 0; i < 30; ++i) {
            if (x & (1 << i)) {
                bitc[i]++;
            }
        }
    }
    int ans = 0;
    for (int x : a) {//遍历每个 a[k]
        int sum = 0;
        for (int i = 0; i < 30; ++i) {//遍历每一位
            int bit = (x >> i) & 1;
            int ones = bitc[i];// 有多少个数第 i 位是 1
            int zeros = n - ones;// 有多少个数第 i 位是 0
            int cone = bit ? zeros : ones;
            //如果a[k]这位是 1, 0 的个数就是 XOR 后 1的个数,a[k]这位是 0 反之
            sum += (1LL << i) * cone;
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
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
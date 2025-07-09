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
    int n;cin >> n;
    vector<int> a(n + 5);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a.begin() + 1,a.begin() + n + 1);
    int ans = a[n / 2 + 1] - 1;
    cout << ans << endl;
    return 0;
}
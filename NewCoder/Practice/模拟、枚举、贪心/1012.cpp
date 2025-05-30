/*https://ac.nowcoder.com/acm/contest/20960/1012*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

const int N = 5001;
int a[5005][5005];
void solve(){
    int n, r;cin >> n >> r;
    for(int i = 0; i < n; i++){
        int x, y ,v;cin >> x >> y >> v;
        x++;
        y++;
        a[x][y] += v;
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            a[i][j] = a[i][j] + a[i-1][j]+a[i][j - 1]-a[i-1][j-1];
        }
    }
    int ans = 0;
    for(int i = r; i <= N; i++){
        for(int j = r; j <= N; j++){
            int sum = a[i][j] - a[i - r][j] - a[i][j - r] + a[i-r][j-r];
            ans = max(sum,ans);
        }
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}
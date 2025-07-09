/*https://codeforces.com/problemset/problem/2051/D*/
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
    int n,x,y;cin >> n >> x >> y;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    sort(a.begin(),a.end());
    int sum = accumulate(a.begin(),a.end(),0LL);
    int ansx,ansy;
    ansx = ansy = 0;
    //x
    int j = 0;
    for(int i = n - 1; i >= 0;i--){
        while(j < n && sum - a[i] - a[j] >= x) j++;
        ansx +=(n - j);
    }
    for(int i = 0; i < n; i++){
        if(sum - 2 * a[i] < x) ansx--;
    }
    //y
    j = 0;
    for(int i = n - 1; i >= 0; i--){
        while(j < n && sum - a[i] - a[j] >= y + 1) j++;
        ansy +=(n - j);
    }
    for(int i = 0; i < n; i++){
        if(sum - 2*a[i] < y + 1) ansy--;
    }
    cout << (ansy - ansx) / 2 << endl;

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
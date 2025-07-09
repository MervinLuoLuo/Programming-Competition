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
    int a,b,c,d;cin >> a >> b >> c >> d;
    vector<int> dis(n);
    int sum = 0, maxd = -1;
    for(int i = 0; i < n; i++){
        cin >> dis[i];
        sum += dis[i];
        maxd = max(dis[i],maxd);
    }
    int mind = 2 * maxd - sum;
    if(mind <0) mind = 0;
    int dist = (c - a) * (c- a) + (d-b) * (d-b); 
    sum = sum * sum;
    mind = mind * mind;
    if(dist >= mind && dist <= sum) yes;
    else no;

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
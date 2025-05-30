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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    priority_queue<int, vector<int>, greater<int>> odd_pq, even_pq;
    for (int i = 0; i < n; i++) {
        if ((i & 1) == 0) odd_pq.push(a[i]);
        else even_pq.push(a[i]);
    }
    for (int i = 0; i < n; i++) {
        if ((i & 1) == 0) {
            a[i] = odd_pq.top();
            odd_pq.pop();
        } 
        else {
            a[i] = even_pq.top();
            even_pq.pop();
        }
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
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
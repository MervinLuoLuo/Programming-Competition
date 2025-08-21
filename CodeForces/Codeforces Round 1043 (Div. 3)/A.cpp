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

void solve(){
    int n;cin >> n;
    deque<char> a;
    for(int i = 0; i < n; i++){
        char c;cin >> c;
        a.push_back(c);
    }
    int m;cin >> m;
    string b;cin >> b;
    for(int i = 0; i < m; i++){
        char x;cin >> x;
        if(x == 'D') a.push_back(b[i]);
        else a.push_front(b[i]);
    }
    while(!a.empty()){
        char c = a.front();
        a.pop_front();
        cout << c;
    }
    cout << endl;

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
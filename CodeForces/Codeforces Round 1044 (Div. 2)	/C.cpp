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
    map<int,vector<int>> layer;
    vector<int> path;
    int start = 0;

    //找起点
    for(int i = 1; i <= n; i++){
        cout << "? " << i << " " << n;
        for(int j = 1; j <= n; j++){
            cout << " " << j;
        }
        cout << endl;cout.flush();

        int x;cin >> x;
        layer[x].push_back(i);
        if(x > start){
            start = x;path = {i};
        }
    }

    //回溯路径
    for(int d = start - 1;d >= 1; d--){
        for(int cand : layer[d]){
            cout << "? " << path.back() << "2 " << path.back() << " " << cand << endl;
            cout.flush();
            int x;cin >> x;
            if(x == 2){path.push_back(cand);break;}
        }   
    }
    
    cout << "! " << path.size();
    for(int i : path) cout << " " << i;
    cout << endl;
    cout.flush();
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
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
    int n,m;cin >> n >> m;
    map<int,int> freq;
    vii a(n);
    int tmp = 0;
    for(int i = 0; i < n; i++){
        int size;cin >> size;
        a[i].resize(size);
        for(int j = 0; j < size; j++){
            cin >> a[i][j];
            if(freq[a[i][j]] == 0) tmp++;
            freq[a[i][j]]++;
        }
    }
    for(int i = 1; i <= m; i++){
        if(freq[i] == 0){no;return;}
    }

    int cnt = (tmp == m ? 1 : 0);
    for(int i = 0; i < n; i++){
        // map<int,int> cur = freq;
        bool stat = 1;
        for(int j = 0;  j < a[i].size(); j++){
            freq[a[i][j]]--;
            if(freq[a[i][j]] == 0){stat = 0;break;}
        }
        if(stat) cnt++;
        for(int j = 0; j < a[i].size() ;j++){
            freq[a[i][j]]++;
        }
    }
    // cout << cnt << endl;
    if(cnt >= 3) yes;
    else no;
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
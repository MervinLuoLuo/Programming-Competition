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
    int n,m;cin >> n >> m;
    vector<int> room(m);
    for(int &x : room) cin >> x;
    sort(room.begin(),room.end());
    vector<vector<int>> ans(n / 2, vector<int>(2));
    for (int i = 0; i < n / 2; i++) {
        ans[i][0] = room[i];
        ans[i][1] = room[m - n / 2 + i];
    }
    for(int i = 0; i < n - n % 2 ;i++){
        if((i & 1 )== 0){
            for(int j = 0; j < 3 ; j++){
                cout << ans[i / 2][0] << " " << ans[i / 2][1] << " ";
            }
        }
        else{
            for(int j = 0; j < 3; j++){
                cout << ans[i / 2][1] << " " << ans[i / 2][0] << " ";
            }
        }
        cout << endl;
    }
    if(n & 1){
        for(int i = 0; i < 3; i++){
            cout << room[n / 2] << " " << room[m - n / 2 - 1] << " ";
        }
        cout << endl;
    }
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
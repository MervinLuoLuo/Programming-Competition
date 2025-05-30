#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
typedef long long ll;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void solve(){
    int n,m;cin >> n >> m;
    vector<vector<int>> a(n,vector<int> (m));
    int mc = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] > mc) mc = a[i][j];
        }
    }
    vector<int> cost(mc + 1, 0), seen(mc + 1, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int cur = a[i][j];
            if(!seen[cur]){seen[cur] = 1; cost[cur] = 1;}
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int cur = a[i][j];
            if(cost[cur] == 2) continue;
            for(int d = 0; d < 4; d++){
                int nowi = i + dx[d], nowj = j + dy[d];
                if(nowi >= 0 and nowi < n and nowj >= 0 and nowj < m and a[nowi][nowj] == cur){
                    cost[cur] = 2;
                    break;
                }
            }
        }
    }
    int sum = 0, maxx = 0;
    for(int c = 1; c <= mc; c++){
        if(seen[c]){
            sum += cost[c];
            if(cost[c] > maxx) maxx = cost[c];
        }
    }
    int ans = sum - maxx;
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
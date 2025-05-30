#include<bits/stdc++.h>
#define ll  long long
#define endl "\n"
using namespace std;
const ll INF = 1e17;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;cin >> n >> m;
    vector<vector<ll>> d(n,vector<ll>(n,INF));
    for(int i = 0; i < n; i++) d[i][i] = 0;
    while(m--){
        ll u,v, w;cin >> u >> v >> w;
        u--;v--;
        d[u][v] = d[v][u] = min(d[u][v], w);
        
    }//无向关系矩阵
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(d[i][k] < INF && d[k][j] < INF && d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }//floyd
    for(int i = 0; i < n; i++){
            int cnt = 1;
        for(int j = 0; j < n; j++){
            
            if(cnt == n){
                cout << d[i][j] << endl;
            }
            else {
                cout << d[i][j] << ' ';
                cnt++;
            }

        }//输出矩阵
    }
    return 0;
}
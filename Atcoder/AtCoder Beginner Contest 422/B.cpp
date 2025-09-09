#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void solve(){
    int h,w;cin >> h >> w;
    vii g(h + 2,vector<int>(w + 2,0));
    for(int i = 1; i <= h; i++){
        string s;cin >> s;
        s = " " + s;
        for(int j = 1; j <= w; j++){
            if(s[j] == '.') g[i][j] = 0;
            else g[i][j] = 1;
        }
    }
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(g[i][j] == 1){
                int cnt = 0;
                for(int k = 0; k < 4; k++){
                    int nx = i + dx[k],ny = j + dy[k];
                    if(g[nx][ny] == 1) cnt++;
                }
                if(cnt != 2 && cnt != 4) {no;return;}
            }
        }
    }
    yes;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

void solve(){
    int n;cin >> n;
    if (n == 0){cout << 0 << endl;return;}
    vector<vector<int>> grid(n, vector<int>(n, -1));
    //定 0 位
    int x = n >> 1, y = n >> 1;
    if(!(n & 1)) x--,y--;//偶数就取中间左上角

    int cur = 0, step = 1,num = 0;
    grid[x][y] = num;num++;
    while (num < n * n) {
        for (int rep = 0; rep < 2; rep++) {
            int dir = cur % 4;
            for (int s = 0; s < step; s++) {
                int curx = x + dx[dir];
                int cury = y + dy[dir];
                if (curx < 0 || curx >= n || cury < 0 || cury >= n || grid[curx][cury] != -1)break;
                x = curx;y = cury;
                grid[x][y] = num;
                num++;
            }
            cur = (cur + 1) % 4;
        }
        step++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j];
            if (j + 1 < n) cout << " ";
        }
        cout << endl;
    }
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
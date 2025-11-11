#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int maxn = 1e9;

//        a    b    n   p  step
string ans[205][205][25][2][4];


void dfs(int a,int b,int n,int p,int step ,string cur){
    //标记
    if(ans[a][b][n][p][step] != "NA") return;

    ans[a][b][n][p][step] = cur;
    //跑完了就返回
    if(n == 0) return;

    // 操作 1
    if(step == 1){
        cur += '1';
        dfs(a + (p == 0), b + (p == 1), n - 1, p, 2,cur);
        cur.pop_back();
    }

    //操作 2
    else if(step == 2){
        for(int i = 2; i <= 7; i++){
            cur += ('0' + i);
            dfs(a + i * (p == 0), b + i * (p == 1), n, p, (n > 6 ? 1 : 3), cur);
            cur.pop_back();
        }
    }

    //操作 3
    else{
        cur += ('0' + (8 - n));
        dfs(a + (8 - n) * (p == 0), b + (8 - n) * (p == 1), n - 1, p, 3, cur);
        cur.pop_back();
    }
    
    //如果已经在第三轮, 那么换人之后仍然是第三轮,否则就到第一轮
    cur += '/';
    dfs(a,b,n,(1 - p),(step == 3 ? 3 : (n > 6 ? 1 : 3)), cur);
    cur.pop_back();
}

/// 只用跑一次把全部情况记录下来就不用每次都跑了
void ini(){
    for(int a = 0; a <= 200; a++){
        for(int b = 0; b <= 200; b++){
            for(int n = 0; n <= 21; n++){
                for(int p = 0; p <= 1; p++){
                    for(int s = 1; s <= 3; s++){
                        ans[a][b][n][p][s] = "NA";
                    }
                }
            }
            
        }
    }
    dfs(0,0,21,0,1,"");
}

void solve(){
    int a,b,n,p;cin >> a >> b >> n >> p;

    for(int i = 1; i <= 3; i++){
        if(ans[a][b][n][p][i] != "NA"){
            cout << ans[a][b][n][p][i] << endl;
            return;
        }
    }

    cout << "NA" << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    ini();
    while(t--){
        solve();
    }
    return 0;
}
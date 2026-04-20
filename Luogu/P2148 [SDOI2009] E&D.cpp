/*https://www.luogu.com.cn/problem/P2148*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
constexpr int N = 10,M = N + 1;
VII sg(N + 1,vector<int>(N + 1,-1));

int SG(int a,int b){
    if(a == 1 && b == 1) return sg[a][b] = 0;
    if(sg[a][b] != -1) return sg[a][b];
    vector<int> vis(max(a,b),0);

    if(a > 1){
        for(int l = 1, r = a - 1; l < a; l++,r--){
            vis[SG(l,r)] = 1;
        }
    }

    if(b > 1){
        for(int l = b - 1,r = 1; r < b; l--,r++){
            vis[SG(l,r)] = 1;
        }
    }

    int res = 0;
    for(int s = 0; s <= max(a,b); s++){
        if(!vis[s]){
            res = s;
            break;
        }
    }
    sg[a][b] = res; 
    return res;
}

int low0(int x){
    int res = 0;
    while(x){
        if((x & 1) == 0)break;
        x >>= 1;
        res++;
    }
    return res;
}

void solve(){
    // for(int a = 1; a <= N; a++){
    //     for(int b = 1; b <= N; b++){
    //         SG(a,b);
    //     }
    // }
    
    // for(int i = 0; i <= N; i++){
    //     for(int j = 0; j <= N; j++) {
    //         if(i == 0) cout  << j << " ";
    //         else{
    //             if(j == 0) cout << i << " ";
    //             else cout << sg[i][j] << " ";        
    //         }

    //     }
    //     cout << endl;
    // }
    int n;cin >> n;
    int sg = 0;
    for(int i = 1; i <= n; i += 2){
        int a,b;cin >> a >> b;
        sg ^= low0((a - 1) | (b - 1));
    }
    if(sg == 0) cout << "NO" << endl;
    else cout << "YES" << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
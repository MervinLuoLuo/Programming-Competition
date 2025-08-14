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
    int N = n * m;
    int g = gcd(n,m);
    if(g > 1){no;return;}
    vector<int> mat(N,0);
    vector<char> vis(N,0);
    int curr = 0,curc = 0;
    int idx = curr * m + curc;
    mat[idx] = 1;
    vis[idx] = 1;
    int sh = 1,sv = 1;
    bool flag = 1;

    for(int num = 1;num < N;num++){
        int k = num;
        bool flag1 = 0;

        int stepc = k % m;
        if(stepc != 0){
            int d1 = (sh == 1 ? stepc : (m - stepc));
            int d2 = (sh == 1 ? (m - stepc) : stepc);

            int nc = (curc + d1) % m;
            int nr = curr;
            idx = nr * m + nc;
            if(!vis[idx]){
                mat[idx] = num + 1;
                vis[idx] = 1;
                curr = nr;
                curc = nc;
                sh = -sh;
                flag1 = 1;
            }
            if(!flag1){
                nc = (curc + d2) % m;
                idx = nr * m + nc;
                if(!vis[idx]){
                    mat[idx] = num + 1;
                    vis[idx] = 1;
                    curr = nr;
                    curc = nc;
                    sh = -sh;
                    flag1 = 1;
                }
            }
        }
        if(!flag1){
            int stepr = k % n;
            if(stepr != 0){
                int d1 = (sv == 1 ? stepr : (n - stepr));
                int d2 = (sv == 1 ? (n - stepr) : stepr);
                int nr = (curr + d1) % n;
                int nc = curc;
                idx = nr * m + nc;
                if(!vis[idx]){
                    mat[idx] = num + 1;
                    vis[idx] = 1;
                    curr = nr;
                    curc = nc;
                    sv = -sv;
                    flag1 = 1; 
                }
                if(!flag1){
                    nr = (curr + d2) % n;
                    idx = nr * m + nc;
                    if(!vis[idx]){
                        mat[idx] = num + 1;
                        vis[idx] = 1;
                        curr = nr;
                        curc = nc;
                        sv = -sv;
                        flag1 = 1;
                    }
                }
            }   
        }
        if(!flag1){flag = 0;break;}
    }
    if(!flag) {no;return;}
    for(int i = 0; i < n;i ++){
        for(int j  =0; j < m; j++)cout << mat[i * m + j] << " ";
        cout << endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
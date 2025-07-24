#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
const int B = 30;
int b[4][5] = {{1,1,0,0,0},{0,1,1,0,0},{1,0,1,1,0},{0,0,0,1,1}};

void solve(){
    int n;cin >> n;
    int l = 1, r=  0;
    vector<vector<int>> a(207,vector<int>(207));
    for(int i = 0; i < B ;i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0;k < 5;k++){
                a[l + j][r + k] = b[j][k];
            }
        }
        l += 4, r += 4;
    }
    for(int i = 0; i < 30; i++){
         if (n>>i&1) a[0][4*i]=1;
    }
    cout << 4 * B << endl;
    for(int i = 0; i < 4 * B ; i++){
        for(int j = 0; j < 4 * B; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
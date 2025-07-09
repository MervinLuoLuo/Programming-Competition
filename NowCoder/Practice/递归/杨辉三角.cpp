/*https://ac.nowcoder.com/acm/problem/14320*/
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
 
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin >> n;
    vector<vector<int>> a(n + 5,vector<int>(n + 5));
    if(n == 1) {cout << 1;return 0;}
    if(n == 2) {cout << 1 << endl << 1 << ' ' << 1;return 0;}
    a[1][1] = 1; a[2][1] = a[2][2] = 1;
    for(int i = 3; i <= n; i++){
        a[i][1] = a[i][i] = 1;
        for(int j = 2;j < i; j++){
            a[i][j] = a[i - 1][j] + a[i-1][j-1];
        }
    }
    for(int i = 1; i <n; i++){
        for(int j = 1; j < i; j++){
            cout << a[i] [j] << ' ';
        }
        cout << a[i][i] << endl;
    }
    for(int i = 1; i < n; i++){
        cout << a[n][i] << ' ';
    }
    cout << a[n][n];
    return 0;
}
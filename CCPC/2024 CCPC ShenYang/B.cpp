#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii pair<string, int>
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
using namespace std;
const int INF = 1e17;
const int maxn = 1e8;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n, m;cin >> n >> m;
        vector<vector<int>> c(n,vector<int>(m));

    }
    return 0;
}
/*
n行 m 列
有 n*m 种颜色
混合方法: 
c[i][j] = a[i]b[j] mod n*m
问是否能找到一种排列使得每个单元格内的颜色都不一样
Input: 
t cases
n 行 m列
1e6
Output: 
不行就no
行就:
1. yes
2. 行的排列
3. 列的排列
*/
//https://codeforces.com/contest/2047/problem/C
#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int INF = 1e19;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        vector<int> a(n+5), b(n + 5);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> b[i];
        }
        int ans = -INF;
        for(int i = 1; i <=n; i++){
            int sum = a[i] + b[i];
            for(int j = 1; j <= n; j++){
                if(i == j)continue;
                sum += max(a[j], b[j]);
            }
            ans = max(sum, ans);
        }
        cout << ans << endl;
    }
    return 0;
}
/*
2 行 n 列的矩阵
\1 2 3 4 ... n
1
2
最初每个单元格内数据为 a[i][j]
执行任意次数操作(包括 0 次):
    选择任意两列对调
操作完成后 选择一条从(1,1)到(2,n)的路径 只能向右或向下走
value = a[i][j]
求 sumvalue 最大的方案
Input: 
t cases
n
a[1][n]
a[2][n]
n <= 5000
Output: 
最大 sumvalue
*/
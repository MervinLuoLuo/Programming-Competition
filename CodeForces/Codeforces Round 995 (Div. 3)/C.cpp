#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m, k;cin >> n >> m>> k;
        vector<int> a(m + 5), q(k + 5);
        for(int i = 0; i < m; i++) cin >> a[i];
        for(int i = 0; i < k; i++) cin >> q[i];
        
    }
    return 0;
}
/*
n 个问题 编号 1 ~ n
m 行问题 每列有 n-1 个不同的问题
每行编号为 a[i]
a[i] 列中不会出现编号为 i 的问题
知道 k 个问题的答案
判断他是否知道该列问题的全部答案
Input: 
t cases
n m k
a[i]
q[k]
3*1e5
Output: 
m 行
1 都知道
0 有不会的
*/
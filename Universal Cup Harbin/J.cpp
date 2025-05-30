#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define f first
#define se second
#define pii pair<int,int>
using namespace std;
const int INF = 1e19;
const int maxn = 1e9;

bool cmp(pii a, pii b){
    return a.f < b.se; 
}
signed main(){
ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n,m;cin >> n >> m;
        vector<int> a(n + 5);
        vector<pair<int, int>> charge(m + 5);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= m; i++){
            cin >> charge[i].f >> charge[i].se;
        }
        sort(charge.begin(),charge.end(),cmp);
        for(int i = 1; i <= m; i++){
           int c = charge[i].se;
           int used = a[c] - charge[i].f;
           int nc = charge[i + 1].se;
           if(used  < 0)  a[nc] -= 0 - used;
           
        }
    }
    return 0;
}
/*
n 个电瓶
容量为 a[i] 单位
1 单位 = 1公里
不能反向 可以选择汽车行驶的每一公里的电力来自哪个电瓶
初始状态满电 
途中经过 m 个充电站 能给哪个电瓶充电是指定的
x[j] j-th充电站与起点的距离
求最远走多远
Input: 
t cases 
n m
a[i];
x[j]
2*1e5
Output: 
最远公里数

先用下一次的充电站要充的
*/
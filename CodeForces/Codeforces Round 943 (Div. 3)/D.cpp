#include<bits/stdc++.h>
#define endl '\n'
#define B cout << "Bodya" << endl
#define S cout << "Sasha" << endl
#define D cout << "Draw" << endl
#define int long long
using namespace std;
const int INF = 1e17;
const int maxn = 1e7;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n, k , PB ,PS;
        cin >> n >> k >> PB >> PS;
        vector<int> p(n), a(n);
        for(int i = 0 ; i < n; i++){
            cin >> p[i];
        }
        for(int i  = 0;  i < n; i++) cin >> a[i];

    }
    return 0;
}
/*
贪 + 博弈
乱序 p [1 ~ n] 
数组 a
B 从 PB位置开始 S 从 PS 位置开始
k 轮 两人同时进行操作
发生两件事 
1. x 位置加 a[x] 分
2. 选择留在当前位置或者从 x 移动到 px
两人都追求最高分
最后分最高者胜
Input: 
t cases
n k PB PS
p[n]
a[n]
2*1e5
Output: 
B
S
D 平局
*/
#include<bits/stdc++.h>
#define endl '\n'
#define S cout << "Sakurako" << endl
#define K cout << "Kosuke" << endl
#define int long long
using namespace std;
const int maxn = 1e9;
const int INF = 1e19;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        int x = 0;
        for(int i = 1; i <= n; i++){
            if(i % 2 != 0) x = x - (2*i-1);
            else x= x+(2*i-1);
        }
        if(x < 0) K;
        else S; 
    }
    return 0;
}
/*
坐标轴上一点 x 初始位置为 0
S K轮流操作 S先手
i-th 轮 移动 2 * i -1 个单位 
S 往负方向移动 K 往正方向移动
一直操作直到 x < -n or x > n
保证游戏一定能结束
求最后一轮是谁操作
Input: 
t cases
n
100
Output: 
S or K

暴搜就完事了
x < 0则最后一个操作一定是 S
x > 0则最后一个操作一定是 K
*/
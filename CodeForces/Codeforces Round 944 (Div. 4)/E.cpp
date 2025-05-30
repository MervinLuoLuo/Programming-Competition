#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const ll maxn = 1e7;
const ll INF = 1e17;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    return 0;
}
/*
从0 到 n
0 到 ak 的直线上由 k+1个标志
车分别在0 .... bk 时到达那里
a b ak = n 严格单调递增
两个路牌之间车匀速行驶
求汽车到达 d 所需的时间
Input: 
t cass
n 终点 k 路牌数 q 查询次数
k 个 ai 
k 个 bi
q 次查询 d位置
求每一次查询汽车到达 d 前的分钟数
*/
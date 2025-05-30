/*https://codeforces.com/contest/2078/problem/D*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;


struct Node{
    char c1, c2;//存 + OR x
    int a1, a2;
};

void solve(){
    int n;cin >> n;
    vector<Node> node(n + 5);
    for(int i = 1;i <= n; ++i){//1-based
        char c1, c2;
        int a1,a2;
        cin >> c1 >> a1 >> c2 >> a2;
        node[i] = {c1,c2,a1,a2};
    }//输入存点信息
    vector<vector<pii>> dp(n + 5);//因为要存左路 l 和 右路 r 的情况,这里用一个二维pair更方便
    dp[0].push_back({1,1});//一开始左右两边各一个人
    for(int i = 1; i <= n ; ++i){
        char c1 = node[i].c1, c2 = node[i].c2;
        int a1 = node[i].a1, a2 = node[i].a2;
        set<pii> s1,s2;
        //利用 set 的排序 到最后取 rbegin 就是最大状态,不用再写 cmp 函数 
        //s1 s2 分别为(x,y)和(y,x)的状态
        for(auto [x,y] : dp[i - 1]){
            int add = 0;
            //处理左边:
            if(c1 == '+') add += a1;
            else if(c1 == 'x') add += x * (a1 - 1);
            //处理右边
            if(c2 == '+') add += a2;
            else if(c2 == 'x') add  += y * (a2 - 1);
            //处理 (x, y 和 (y,x)的情况 保证状态值都是最大的
            s1.insert({x,y + add});s1.insert({x + add, y});
            s2.insert({y + add, x});s2.insert({y,x + add});
        }
        dp[i].push_back(*s1.rbegin());//记得解引用
        //这里的 x y就指的是左右两边了
        auto [y,x]  = *s2.rbegin();
        dp[i].push_back({x,y});
    }
    //输出最大值
    int ans = 0;
    for(auto it : dp[n]){
        ans = max(ans,(it.first + it.second));
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}
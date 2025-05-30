#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define pii pair<char,int>
using namespace std;
const int INF = 1e19;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        vector<pii> ans;
        for(int i = 0; i < n; i++){
            char a;int x; cin >> a >> x;
            ans.emplace_back(a, x);
        }
        cout << ans.size() * 2 - 1 << ' ' << ans[0].first << endl;
        for(int i = 0; i < ans.size(); i++){
            cout << 'Z' << ' ' << ans[i].second << endl;
            if(i != ans.size() - 1){
                if(ans[i].first == 'S'){
                    if(ans[i + 1].first == 'E') cout << 'L' << endl;
                    if(ans[i + 1].first == 'W') cout << 'R' << endl;
                }
                if(ans[i].first == 'N'){
                    if(ans[i + 1].first == 'E') cout << 'R' << endl;
                    if(ans[i + 1].first == 'W') cout << 'L' << endl;
                }
                if(ans[i].first == 'W'){
                    if(ans[i + 1].first == 'S') cout << 'L' << endl;
                    if(ans[i + 1].first == 'N') cout << 'R' << endl;
                }if(ans[i].first == 'E'){
                    if(ans[i + 1].first == 'N') cout << 'L' << endl;
                    if(ans[i + 1].first == 'S') cout << 'R' << endl;
                }
            }
        }

    }
    return 0;
}
/*
Input: 
t cases
n 指令的个数
n lines: 
    string d int x --> 往 d 方位走到第 x 个路口
保证两个指令中 d 不相同且不相反
Output: 
f 初始朝向(N S W E)
m 相对方位的指令条数
m lines: 
    g(Z L R)转向方位
    if g == Z 还得输出 y 表示直走到第 y 个路口
第一输出的 g 一定是 Z
相邻的 g 不能相同 L R 不相邻
*/
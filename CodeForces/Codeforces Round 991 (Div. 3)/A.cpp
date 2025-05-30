#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int INF = 1e19;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >>t;
    while(t--){
        int n,m;cin >> n >> m;
        vector<string> s(n + 5);
        for(int i = 0; i < n; i++){
            cin >> s[i];
        }
        int cnt = 0;
        int i = 0;
        for(i = 0; cnt <= m; i++){
            if(cnt + s[i].size() > m or s[i].size() == 0) break;
            cnt += s[i].size();
        }
        cout << i << endl;
    }
    return 0;
}
/*
长度为 n 的字符串 s 由拉丁文组成
两张纸 第一张可以容纳 m 个字符 第二张无限长
一个 x s 的前 x 给单词写在第一张纸上
剩下的写在第二张纸上 单词间没有空隙
同一单词写在同一张纸上
找出最大的 x 使得第一张纸写的单词最多
Input: 
t cases
n m
接下来 n 行是 s[i] 个单词
s[i] <= 10
Output: 
x
*/
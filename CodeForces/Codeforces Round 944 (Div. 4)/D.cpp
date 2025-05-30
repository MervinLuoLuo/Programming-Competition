#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const ll maxn = 1e7;
const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        string s;cin >> s;
        string sa;
        char now = '2';
        for(int i = 0; i < s.size();i++){
            if(now != s[i]){
                sa.push_back(s[i]);
                now = s[i];
            }
        }
        int ans = sa.size();
        if(sa.find("01") != -1) ans--;
        cout << ans <<endl;
    }
    return 0;
}
/*
给一个 0 和 1 组成的字符串
求至少要分割成多少片段才能使得0全部在前面 1全部在后面(如果有的话)
不一定要均等切割
Input:
t cases
s 由 0 和 1 组成的字符串
Output: 
分割的最小片段数
*/
/*
1010
0110
100101001011 -> 101010101
000011111
*/
#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int INF = 1e17;
const int maxn = 1e7;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n, m;cin >> n >> m;
        string a, b;
        cin >> a >> b;
        int l = 0, r = 0;
        int ans = 0;
        while(l < n and r < m){
            while(r < m and a[l] != b[r]) r++;
            if(r == m) break;
            ans++;l++;r++;
        }
        cout << ans << endl;
    }
    return 0;
}
/*
又是 01 串 a b
k = a字串.size
找出 k 使得 a 的前 k 个字符是 b 的子序列
子序列定义: 字符串 a 能够通过 b 删除某些元素得到
Input: 
t cases
n = a.size m = b.size
a
b
Output: 
最大的 k
*/
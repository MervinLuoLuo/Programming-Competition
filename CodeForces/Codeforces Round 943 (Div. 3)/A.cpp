#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int INF = 1e17;
const int maxn = 1e7;

int gcd(int a, int b){
    if(a < b)swap(a, b);
    if(b == 0) return a;
    return gcd(b, a % b);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int x;cin >> x;
        int y = -1;
        int maxi = 0;
        for(int i = 1; i < x; i++){
            int now = gcd(x, i) + i;
            if(now > maxi){
                maxi = now;
                y = i;
            }
        }
        
        cout << y << endl;
    }
    return 0;
}
/*
一个整数 x
找到任意一个 y 使得 (x + y) 的最大公约数gcd(x + y) 
     gcd(x+y) + y最大
Input: 
t cases
x
Output: 
y

数据量 <= 1000

Solution: 
暴力枚举
[1, 1000]
先找 x 的约数的最大值 m m % x == 0
再找一个最大的 y 使得 y的约数也有 m [1, 1000] 找一个 y  
    y % m == 0
    m + y 自然最大
*/
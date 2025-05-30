//https://codeforces.com/contest/2040/problem/A
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii<int,int>
using namespace std;
const int INF = 1e19;
const int maxn  = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n, k;cin >> n >> k;
        vector<int> a(n + 5);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        if(k == 1) {cout << "NO" << endl;continue;}
        /*vector<int> kp;
        int tmp = k, x = 1;
        while(tmp <= 100){
            kp.push_back(tmp);
            x++;
            tmp *= x;
        }*/
       bool flag = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(abs(a[i] - a[j]) % k == 0){
                    flag = 1;break;
                }
            }
        }
        if(flag = 1){cout << "NO" << endl;continue;}
        else {
            
        }
    }
    return 0;
}
/*
找质数
博弈大师
n 个数数组 a 一个数 k
A 选一个数 1 <= i <= n 
B 选一个数 j i != j
如果 abs(a[i] - a[j]) 不能被 k 整除
则 A win else B win
我们先手 如果要赢应选哪一个i
Input: 
t cases
n k
a[i]
Output: 
不可能赢 No
可能赢先 Yes 然后输出 i
*/
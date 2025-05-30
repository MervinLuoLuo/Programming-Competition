#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int INF = 1e19;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int a, b ,c;
        cin >> a >> b >> c;
        if(c > b and b > a) cout << "STAIR" << endl;
        else if(b > a and b > c) cout << "PEAK" << endl;
        else cout << "NONE" << endl;
    }
    return 0;
}
/*
3 个整数 a b c
阶梯 a < b < c
山峰 b > a and b > c  a c没有要求
问是阶梯 山峰 还是两者皆非
Input: 
t cases 
a b c
Output: 
STAIR
PEAK
NONE
*/
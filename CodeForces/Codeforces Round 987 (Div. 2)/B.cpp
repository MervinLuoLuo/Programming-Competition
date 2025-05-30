#include<bits/stdc++.h>
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        vector<int> p(n + 5);
        for(int i = 0; i < n; i++){
            cin >> p[i];
        }
        for(int i = 1; i < n; i++){
            if(p[i] == p[ i - 1] - 1){
                swap(p[i], p[i - 1]);
            }
        }
        is_sorted(p.begin(), p.begin() + n) ? yes : no; 
    }
    return 0;
}
/*
只能交换相邻且差距为1的数;
问最终能不能成功排列为升序序列
t cases
n 个棍
[1,n]随机排列且不重复 == 每个棍的长度
输出 yes: 能成功排列为升序序列
no : 不能成功排列
*/
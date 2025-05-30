#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >>t;
    while(t--){
        int n;cin >> n;
        vector<int> h(n);
        for(int i = 0; i < n; i++){
            cin >> h[i];
        }
        vector<int> cnt(h[0] + 5);
        for(int i = 0; i < n; i++){
            cnt[h[i]]++;
        }
        int max = -1;
        for(int i = 1; i <= h[0]; i++){
            if(cnt[i] > max) max = cnt[i];
        }
        int ans = n - max;
        cout << ans << endl;
    }
    return 0;
}
/*
t case
n层
n个整数<vector> h (h[i] >= h[i+1]  1 -> n输入) 
一次操作修改一层的高度
** h为非严格递减序列
输出最小操作数使得h变为非严格递增序列
他只是修改层高度而不是排序

*/
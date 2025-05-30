#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

void ser(int l, int r, int find){
    int mid = (l + r) / 2;

    
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int k;cin >> k;
        vector<int> x(k);
        for(int i = 0; i < k; i++){
            cin >> x[i];
        }
        sort(x.begin(), x.end());
        int n = -1, m  = -1;
        int size = k - 2;
        for(int i = 0 ; i < k; i++){
            if(size % x[i] != 0) continue;
            int p = lower_bound(x.begin(),x.end(), size / x[i]) - x.begin();
            if (p == i) p++;
            if(p >= k or x[p] * x[i] != size) continue;
            n = x[i];m = x[p];
        }
        
        cout << n << ' ' << m << endl;
    }
    return 0;
}
/*
数据小于 2 * 1e5 for for超时 -->二分
t cases
k 个输入 一个数组
找到n m 使得 n * m = k - 2
输出可能的n m(任意一组就行)
*/
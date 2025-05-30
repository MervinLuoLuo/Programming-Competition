#include<bits/stdc++.h>
#define int long long
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define endl '\n'
using namespace std;
const int INF = 1e17;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        vector<int> a(n + 5);
        for(int i = 0; i < n; i++){
        cin >> a[i];
        }
        bool flag = 1;
        for(int i = 0; i < n - 2; i++){
            while(a[i] != 0){
                a[i]--; a[i + 1] -= 2; a[i + 2]--;
            }
            if(a[i + 1] < 0 or a[i + 2] < 0){flag = 0;break;}
            if(i == n - 3 and (a[i + 1] != 0 or a[i + 2] != 0)){flag = 0;break;}
        }
        if(flag) yes;
        else no;
    }
    return 0;
}
/*
1 ~ n 的无序排列
操作包含: 选一个i(2 <= i <= n - 1)
a[i - 1] = a[i - 1] - 1
a[i] = a[i] - 2
a[i + 1] = a[i + 1] - 1
可以[0, inf]次操作
问是否能通过操作使得 a 中所有元素变为0
Input: 
t cases
n
a[i]
2*1e5
Output: 
YES or NO
从边缘开始操作
要使得能够完成 最边缘的一项一定是 -1
*/
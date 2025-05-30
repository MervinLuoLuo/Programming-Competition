#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const ll INF = 1e17;
const ll maxn = 1e7;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        vector<int> a(n + 5 , -1);
        for(int i = 0 ; i < n; i++){
            cin >> a[i];
        }
        int cnt = 0;
        for(int i = 0; i < n ; i++){
            if(a[i] == -1) continue;
            for(int j = i + 1; j < n; j++){
                if(a[j] == -1) continue;
                else if(a[i] == a[j]){
                    cnt++; a[i] = -1; a[j] = -1;break;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
/*
一个数组中有n个数
找出数组中ai == aj and i 和 j之前没被选过的
可以让被选中的值变为-1 找到值为-1的就continue
t cases
n = a[]的长度
n个数
输出最大的分数
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const ll INF = 1e17;
const ll maxn = 1e7;

bool isPrime(int a){
    for(int i = 2; i * i <= a; i++){
        if(a % i == 0)
        return 0;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        if(n < 5){cout << -1 << endl;continue;}
        deque<int> dq;
        dq.push_front(4);
        dq.push_back(5);
        for(int i = 1; i <= n; i++){
            if(i % 2 == 0 and i != 4) dq.push_front(i);
            if(i % 2 != 0 and i != 5) dq.push_back(i);
        }
        while(!dq.empty()){
            cout << dq.front() << ' ';
            dq.pop_front(); 
        }
        cout << endl;
    }
    return 0;
}
/*
找合数
[1, n]随机排列 找到一种排列使得pi + pi+1一定为合数
t cases
p[1 ~ n]随机排列
数据范围为2 * 1e5
输出这个排列 如果找不到就-1
*/
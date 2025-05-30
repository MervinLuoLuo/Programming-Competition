#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int INF = 1e17;
const int mann = 1e7;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        string a;
        cin >> a;
        int ans = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] == '1') ans++;
        }
        string b;
        for(int i = 0; b.size() < k; i++){
            int num = i;
            
        }
    }
    return 0;
}
/*
n 位的 01 串 A
B.size() = k B 也是二进制字符串
找到串 B 使得 C = A + B
C 中 1 的为 D
D == C 中 1 的个数(转换为二进制)
要求 D == B
Input:
t cases
n = A.size k =  B.size()
串 A
Output: 
满足条件的最小的 B
*/
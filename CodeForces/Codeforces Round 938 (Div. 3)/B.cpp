#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
using namespace std;
const ll INF = 1e17;
const ll maxn = 1e7;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n, c, d;cin >> n >> c >> d;
        vector<int> num(n * n);
        map<int,int> cnt;
        for(int i = 0; i < n * n; i++){
            cin >> num[i];
            cnt[num[i]]++;
        }
        sort(num.begin(),num.end());
        int a11 = num[0];
        bool flag = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int now = a11 + i * c + j * d;
                if(cnt[now] == 0) {flag = 0; break;}
                else cnt[now]--;
            }
            if(!flag) break;
        }
        if(flag) yes;
        else no;
    }
    return 0;
}
/*
n*n的矩阵 选择三个整数 a1,1 c d
规则: a[i + 1][j] = a[i][j] + c;
    a[i][j + 1] = a[i][j] + d;
现有一个n * n的长度的数组 元素是按规则确定的矩阵内的元素 
给定 c d 
问这个数组内的元素是否能组成规则矩阵
Input:
t cases
 n 元素个数 c d
 没给a[1][1] 最小那个就是
n * n 的二维数组 输入他找到的元素组成的数组
25 * 1e4
Output:
如果能那就是yes
不能就是no
*/
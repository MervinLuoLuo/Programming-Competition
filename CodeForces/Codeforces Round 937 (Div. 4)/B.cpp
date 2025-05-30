#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

vector<string> sqa;
void ope(int x, int y, char c){
    sqa[x][y] = c;
    sqa[x+1][y] = c;
    sqa[x][y+1] = c;
    sqa[x+1][y+1] = c;
}
signed main(){
    ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        int size = 2*n;
        sqa.resize( n * 2 + 5);
        for(int i = 0; i < size + 5; i++)sqa[i].resize(size + 5);
        bool flag = 1;
        if (n % 2 == 0) flag = 0;
        for(int i = 1; i < size; i+= 2){
            if(n % 2 == 0)flag ^= 1;
            for(int j = 1; j < size; j+=2){
                if(flag) ope(i,j,'#');
                else ope(i,j,'.');
                flag ^= 1;
            }
        }
        for(int i = 1; i <= size; i++){
            for(int j = 1; j <= size; j++)cout << sqa[i][j];
            cout << endl;
        }
    }
    return 0;
}
/*
给定一个整数 n
输出2n * 2n 的矩阵
# 和 .交替形成
左上角是#
Input: 
t cases
n
Output: 
矩阵
相邻元素间无空格
*/
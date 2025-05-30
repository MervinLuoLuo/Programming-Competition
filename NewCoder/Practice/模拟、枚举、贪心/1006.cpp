#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    int be,ed;cin >> be >> ed;
    int cnt = 0;
    for(int i = be; i <= ed; i++){
        int y = i / 10000;
        bool flag = 0;
        if((y % 4 == 0 and y % 100) or y % 400 == 0) flag = 1;
        int m = (i / 100) % 100;
        int d = i % 100;
        if(m == 2){
            if(flag){
                if(d == 0 or d > 29) continue;
            }
            else {
                if(d == 0 or d > 28) continue;
            }
        }
        else if(m == 1 or m == 3 or m == 5 or m == 7 or m == 8 or m == 10 or m == 12){
            if(d == 0 or d > 31) continue;
        }
        else if(m == 4 or m == 6 or m == 9 or m == 11){
            if(d == 0 or d > 30) continue;
        }
        else continue;
        string s = to_string(i);
        string cur = s;
        reverse(s.begin(),s.end());
        if(cur == s) {cnt++;}
    }
    cout << cnt << endl;
    return 0;
}
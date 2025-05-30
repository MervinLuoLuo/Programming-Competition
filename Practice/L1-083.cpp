#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if(x >= a && y >= a) cout << x << "-Y " << y << "-Y" << endl << "huan ying ru guan";
    if((x >= a && y < a)){
        if(x < b) cout << x << "-Y "<< y << "-N" << endl <<"1: huan ying ru guan";
        if(x >= b)cout << x << "-Y "<< y << "-Y" << endl << "qing 1 zhao gu hao 2";
    }
    if((x < a and y >= a)){
        if(y < b)cout << x << "-N " << y << "-Y" << endl << "2: huan ying ru guan";
        else cout << x << "-Y "<< y << "-Y" << endl << "qing 2 zhao gu hao 1";
    }
    if(x < a and y < a) cout << x<<"-N " << y << "-N" << endl <<"zhang da zai lai ba";
    return 0;
}
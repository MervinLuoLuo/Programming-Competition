//交互题首刷
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n[6] = {4, 8, 15, 16, 23, 42};
ll db[6];
int main(){
    for(int i = 0; i < 4; i++){
        cout << '?' << i << ' ' << i + 1;
        fflush(stdout); 
        cin >> db[i]; 
    }
    do{
        if(n[0] * n[1] == db[1] and n[1] * n[2] == db[2] and n[2] * n[3] == db[3] and n[3] * n[4] == db[4])break;

    }while(next_permutation(n, n + 6));
    cout << '!';
    for(auto p : n){cout << p << ' ';}
    cout << endl;
    return 0;
}
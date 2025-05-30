#include<iostream>
using namespace std;

int eg[] = {7,17,27,37,47,57,67,70,71,72,73,74,75,76,77,78,79,87,97};
int main(){
	for(int i = 1; i <= 100; i++){
		if(i % 7 == 0){
			cout << "敲桌子" << endl;
			continue;
		}
		bool flag = 0;
		for(int j = 0; j  < 19; j++){
			if(i == j){
				flag = 1;
				break;
			}
		}
		if(flag == 1) cout << "敲桌子" << endl;
		else cout << i << endl;
	}
	return 0;
}
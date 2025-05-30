#include <stdio.h>
int main(){
	int a[3][4];
	int i,j;
	for (i=0; i<3; i++) {
		for (j=0; j<4; j++) {
			scanf("%d", (a+i)+j);// (a+i)是二维数组i行地址，
		}                     //*(a+i) 是二维数组第i行第0号元素地址，
	}                         //*(a+i)+j) 是二维数组第i行第j号元素地址
    printf("%d",*(*(a+i-1)+j-1));// (a+i)是二维数组i行地址，
    return 0;
}

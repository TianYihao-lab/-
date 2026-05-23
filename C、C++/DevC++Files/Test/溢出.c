#include<stdio.h>

int main(){
//	unsigned char x = 255;
//	x = x + 1;
//	
//	printf("%d\n", x); // 0
	
	char x=10;
	int y=x;
	printf("%d %d\n",x,y);
	printf("%d %d\n",sizeof(x),sizeof(y));
	
	return 0;
}

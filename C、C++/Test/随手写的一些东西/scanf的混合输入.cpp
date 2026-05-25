#include<stdio.h>

void test01(){
	char a,b;
	scanf("%c%c",&a,&b);
	printf("%c %c",a,b);
	scanf("%c %c",&a,&b);
	printf("%c %c",a,b);
}

void test02(){
	int a;
	char b;
	scanf("%d%c",&a,&b);
	printf("%d %c\n",a,b);
	printf("%c __\n",b);
}

int main(){
	test01();	
	return 0;
}

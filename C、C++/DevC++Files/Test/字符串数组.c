#include<stdio.h>
#include<string.h>

int main(){
	char* weekdays[] = {
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday",
		"Sunday"
	};
	for (int i = 0; i < 7; i++) {
		printf("%s\n", weekdays[i]);
	}
	return 0;
}


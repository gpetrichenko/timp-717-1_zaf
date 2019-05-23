#include <stdio.h>

int main(){
int n, a, check;
check = 0;
scanf("%d", &n);
for (int i = 0; i < n; i++)
{
	scanf("%d", &a);
	if (a <= 0){
		check++;;	
	}
}
printf("%d\n", check);
return 0;
}


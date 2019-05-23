#include <stdio.h>

int main(){
int n, a, res;
scanf("%d", &n);
for (int i = 1; i <= n; i++)
{
	scanf("%d", &a);
	if (i == 1){
		res = a - i;	
	} else {
		res *= a - i;
	}
}
printf("%d\n", res);
return 0;
}


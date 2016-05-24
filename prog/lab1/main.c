#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

static void int_to_rim(int num)
{
	int i = 0;
	int n = 0;
	wchar_t dig = (wchar_t)(0x1E8C);

	if( num < 0 )
	{
		printf("-");
		num *= (-1);
	}
	n = num / 10000;
	num %= 10000;
	for(i = 0; i < n; i ++ )
		printf("%lc", dig); 
	
	dig = (wchar_t)(0x1E7C);
	n = num / 5000;
	num %= 5000;
	for(i = 0; i < n ; i ++ )
		printf("%lc", dig);
	
	dig = L'M';
	n = num / 1000;
	num %= 1000;
	for( i = 0; i < n; i ++ )
		printf("%lc", dig);

	dig = (wchar_t)(0x216E);
	n = num / 500;
	num %= 500;
	for( i = 0; i < n; i ++ )
		printf("%lc", dig);

	dig = (wchar_t)(0x216D);
	n = num / 100;
	num %= 100;
	for( i = 0; i < n; i ++ )
		printf("%lc", dig);
	
	dig = (wchar_t)(0x216C);
	n = num / 50;
	num %= 50;
	for( i = 0; i < n; i ++ )
		printf("%lc", dig);
	
	dig = (wchar_t)(0x2169);
	n = num / 10;
	num %= 10;
	for( i = 0; i < n; i ++ )
		printf("%lc", dig);
	
	dig = (wchar_t)(0x2164);
	n = num / 5;
	num %= 5;
	for( i = 0; i < n; i ++ )
		printf("%lc", dig);

	dig = (wchar_t)(0x2160);
	n = num / 1;
	num %= 1;
	for( i = 0; i < n; i ++ )
		printf("%lc", dig);

	printf("\n");
}

int main()
{
	int num = 0;
	(void)setlocale(LC_ALL, "");
	printf("Enter the num(XXXXXXXX<num<XXXXXXXX): ");
	if( scanf("%8d", &num) == 0){
		printf("Error input...\n");
		(void)getchar();
		return 1;
	}
	printf("number in rim form: ");
	int_to_rim(num);
	return 8;
}


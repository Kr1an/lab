#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main(void)
{
	time_t rawtime;
	time(&rawtime);
	struct tm* curDate;	
	curDate=localtime(&rawtime);
	printf("%d", curDate->tm_hour);
	return 0;
}

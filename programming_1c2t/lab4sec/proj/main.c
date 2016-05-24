#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void exFunc(int x);
static void printfile(char * name);

int main(void)
{
	int x;
	printf("\t\t*POSITION*MOVES*PROGRAM*\n\n");
	printfile("text.txt");
	printf("Enter the position chamge moves: ");
	if(scanf("%d", &x) == 0)
	{
		printf("inputError..\n");
		return 1;
	}
	exFunc(x);		
	printfile("text.txt");
	return 0;
}

static void printfile(char* name)
{
	char* str = NULL;
	FILE* file = NULL;

	str = (char*)malloc(sizeof(char)*150);
	file = fopen(name, "r");
	printf("\t*****IN-FILE******\n");
	while(fgets(str, 150, file))
		printf("%s",str);
	printf("\t****END-FILE******\n");
	return;
}
static void exFunc(int x)
{
	int temp = 0;
	char* text = NULL;
	char* extext = NULL;
	FILE* file = NULL;
	FILE* exfile = NULL;
	int i = 0;
	int j = -1;
	temp = x;

	file = fopen("text.txt", "r");
	exfile = fopen("extext.txt", "w+");
	text = (char*)malloc(sizeof(char) * 150);
	extext = (char*)malloc(sizeof(char) * 150);

	while(fgets(text, 150, file)){
		if( strlen(text) > 1)
			x %= (strlen(text) - 1);
		if( x == 0 )
			x = strlen(text) -1;
		if( strcmp(text, "\n") == 0 ){
			fputs(text, exfile);	
			continue;
		}
		if(j != -1)
			fputc('\n', exfile);
		j = 0;
		for(i = strlen(text)-x-1; i < strlen(text)-1; i++){
			extext[j] = text[i]; 
			j++;
		}
		for(i = 0; i < strlen(text)-x-1; i++)
		{
			extext[j] = text[i];
			j++;
		}
		for(i = 0; i < j; i++)
			fputc(extext[i], exfile);
		strcpy(text, "");
		strcpy(extext, "");
		x = temp;
	}
	fputc('\n', exfile);
	fclose(exfile);
	fclose(file);
	
	exfile = fopen("extext.txt", "r");
	file = fopen("text.txt", "w+");
	
	while(fgets(text, 150, exfile))
		fputs(text, file);
	
	fclose(exfile);
	fclose(file);
	free(text);
	return;
}

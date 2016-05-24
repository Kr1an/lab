#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define nil 0x0
#define TEXT_FILE_NAME "text.txt"

static const int _FILE_STR_LEN = 140;
static const int _EXIT_SUCCESS = 0;
static const int _EXIT_FAIL = -1;
static const int _TWO = 2;
static const int _NULL = 0;
static const int _ONE = 1;

static char ParseSymbal[] = { ' ', ',', '.', ';', ':', '?', '!', '\'',
	'"', '|', '/', '\\', '~', '_', '^', '`',
	'(', ')', '{', '}', '[', ']', '<', '\t',
	'>', '#', '%', '&', '-', '=', '+', '*', '\n', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'
};

static void writeText();
static char **readText();
static int fileRows();
static void findAnswer();
static void inputError();

int main(/*@unused@*/int args, /*@unused@*/ char** argv)
{
	writeText();
	findAnswer();
	printf("\n");
	return _EXIT_SUCCESS;
}
static void inputError()
{
	printf("\nError; press \"Enter\" to exit");
	exit(_EXIT_FAIL);

}
static void findAnswer()
{
	int i, j, k, q;
	char ** text;
	int st = 0;
	text = readText();
	for( i = 0; strcmp(text[i],"") != 0; i++)
		for( q = 0; q < (int)strlen(text[i]); q++)
			if( text[i][q] >= 'a' && text[i][q] <= 'z' )
				text[i][q] += 'A' - 'a';
	
	for( i = 0; strcmp(text[i],"") != _NULL; i++){
		st = 0;
		for( q = 0; q < (int)strlen(text[i]); q++)
			if( q >= 1 && text[i][q] >= 'A'  &&  text[i][q] <= 'Z' && text[i][q] < text[i][q-1])
				st = 1;
		if(st == 0)
			printf("%s ", text[i]);
	}
	for( i = 0; i < fileRows() * _FILE_STR_LEN ; i++)
		free(text[i]);
	free(text);
	return;
}
static int fileRows()
{
	int i = _NULL;
	char *temp = (char*)malloc( sizeof(char) * _FILE_STR_LEN * 2 );
	FILE* file =fopen( TEXT_FILE_NAME, "r" );
	if( file == NULL || temp == nil )
		inputError();
	while( fgets( temp, _FILE_STR_LEN * _TWO, file ))
	{
		strcpy(temp, "");
		i++;
	}
	(void)fclose(file);
	return i;
}
static void writeText()
{
	char * temp = (char*)malloc(sizeof(char*) * _FILE_STR_LEN );
	FILE* file = fopen( TEXT_FILE_NAME ,"w");
	if( file == NULL || temp == nil )
		inputError();
	printf("Enter your text; when ready write \"-1\" end press enter\n\n");
	(void)fgets( temp, _FILE_STR_LEN , stdin );
	while( strcmp( temp, "-1\n") != _NULL )
	{
		fprintf( file, "%s", temp );
		fprintf(file, "%s", (temp[strlen(temp + _ONE)] == '\n') ? (""): ("\n"));
		strcpy( temp, "");
		(void)fgets( temp, _FILE_STR_LEN , stdin );
	}
	(void)fclose(file);
	free(temp);
	return;
}
char **readText()
{
	FILE *file = fopen( TEXT_FILE_NAME, "r+");
	char *chStr = (char *)malloc(sizeof(char));
	char *tmp;
	char ch;
	char **str= (char **)malloc(sizeof(char*) * fileRows() * _FILE_STR_LEN);
	int i = _NULL, q = _NULL, j = _NULL;
	tmp = (char *)malloc(sizeof(char) * _FILE_STR_LEN);
	if( file == NULL || chStr == nil || tmp == nil || str == nil)
		inputError();
	for (i = _NULL; i < fileRows() * _FILE_STR_LEN; i++)
		if( (str[i] = (char *)malloc(sizeof( char ) * _FILE_STR_LEN)) == nil)
			inputError();
	strcpy(tmp, "");
	ch = (char)fgetc(file);
	do{
		chStr[_NULL] = ch;
		for( j = _NULL; j < (int)strlen(ParseSymbal); j++){	
			if( chStr[_NULL] == ParseSymbal[j] ){
				if( (int)strlen(tmp) > _ONE ){
					strcpy( str[q++], tmp);
					strcpy(tmp, "");
					break;
				}
				strcpy(tmp, "");
				break;
			}else{
				if( j < (int)strlen(ParseSymbal) - _ONE )
					continue;
				else{
				 	strncat(tmp, chStr, (size_t)_ONE);
					break;
				}
			}
		}
	}while ( (int)(ch = (char)fgetc(file)) != EOF );
	free(tmp);
	(void)fclose(file);
	return str;
}

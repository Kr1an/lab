/*site '\n'*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TEXT_FILE_NAME "text.txt"
const int _FILE_STR_LEN = 80;
const int _EXIT_SUCCESS = 0;
const int _TWO = 2;
const int _NULL = 0;
const int _ONE = 1;

static char ParseSymbal[] = { ' ', ',', '.', ';', ':', '?', '!', '\'',
	'"', '|', '/', '\\', '~', '_', '^', '`',
	'(', ')', '{', '}', '[', ']', '<', '\t',
	'>', '#', '%', '&', '-', '=', '+', '*', '\n', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'
};

static void writeText();
static char **readText();
static int fileRows();
static char* findAnswer();

int main(void)
{
	writeText();
	printf("\nThe longest unique character word: %s\n", findAnswer());
	
	return _EXIT_SUCCESS;
}

static char* findAnswer()
{
	int i, j, k;
	char * answer = (char*)malloc(sizeof(char) * _FILE_STR_LEN);
	int answerLenght = _NULL;
	char ** text;
	strcpy(answer,"");
	text = readText();
	for( i = _NULL; strcmp(text[i],"") != _NULL; i++)
		for( j = _NULL; j < strlen(text[i]) - _ONE; j++)
			for( k = j + _ONE; k < strlen(text[i]); k++ ){
				if( text[i][k] == text[i][j] ){
					j = strlen(text[i]) * _TWO;
					break;
				}else if( j >= strlen(text[i]) - _TWO && k >= strlen(text[i]) - _ONE && strlen(text[i]) > answerLenght ){
					answerLenght = strlen(text[i]);
					strcpy( answer, text[i] );
				}
			}
	return answer;
}

static int fileRows()
{
	int i = _NULL;
	char *temp = (char*)malloc( sizeof(char) * _FILE_STR_LEN * _TWO );
	FILE* file = fopen( TEXT_FILE_NAME, "r" );
	while( fgets( temp, _FILE_STR_LEN * _TWO, file ))
	{
		strcpy(temp, "");
		i++;
	}
	fclose(file);
	return i;
}

static void writeText()
{
	char * temp = (char*)malloc(sizeof(char*) * _FILE_STR_LEN );
	FILE* file = fopen( TEXT_FILE_NAME ,"w");
	printf("Enter your text; when ready write \"-1\" end press enter\n\n");
	fgets( temp, _FILE_STR_LEN , stdin );
	while( strcmp( temp, "-1\n") != _NULL )
	{
		fprintf( file, "%s", temp );
		fprintf(file, "%s", (temp[strlen(temp + _ONE)] == '\n') ? (""): ("\n"));
		
		strcpy( temp, "");

		fgets( temp, _FILE_STR_LEN , stdin );
	}
	fclose(file);
	free(temp);
	return;
}

char **readText(char *name)
{
	FILE *file = fopen( TEXT_FILE_NAME, "r+");
	char *temp;
	char *chStr = (char *)malloc(sizeof(char));
	char *tmp;
	char ch;
	char **str= (char **)malloc(sizeof(char*) * fileRows() * _FILE_STR_LEN);
	int i = _NULL, q = _NULL, j = _NULL;
	for (i = _NULL; i < fileRows() * _FILE_STR_LEN; i++)
		str[i] = (char *)malloc(sizeof( char ) * _FILE_STR_LEN);
	tmp = (char *)malloc(sizeof(char) * _FILE_STR_LEN);
	temp = (char *)malloc(sizeof(char) * _FILE_STR_LEN);
	strcpy(tmp, "");
	ch = fgetc(file);
	
	do{
		chStr[_NULL] = ch;
		for( j = _NULL; j < strlen(ParseSymbal); j++){	
			if( chStr[_NULL] == ParseSymbal[j] ){
				if( strlen(tmp) > _ONE ){
					strcpy( str[q++], tmp);
					strcpy(tmp, "");
					break;
				}
				strcpy(tmp, "");
				break;
			}else{
				if( j < strlen(ParseSymbal) - _ONE )
					continue;
				else{
				 	strncat(tmp, chStr, _ONE);
					break;
				}
			}
		}
	}while ( (ch = fgetc(file)) != EOF );
	free(temp);
	free(tmp);

	fclose(file);
	return str;

}

/*site '\n'*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define nil 0x0

static char NUM_OF_WORDS = 20;
static char* TEXT_FILE_NAME;
static const int _FILE_STR_LEN = 140;

static struct pair
{
	char * word;
	int findNum;
}*sheet;

static char ParseSymbal[] = { ' ', ',', '.', ';', ':', '?', '!', '\'',
	'"', '|', '/', '\\', '~', '_', '^', '`',
	'(', ')', '{', '}', '[', ']', '<', '\t',
	'>', '#', '%', '&', '-', '=', '+', '*', '\n', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'
};

/*static void writeText();*/
static char **readText();
int paircmp( const void *val1, const void *val2);
static int fileRows();
static void findAnswer();
static void inputError();
static struct pair* sort(char** mass, int size);
int main(/*@unused@*/int args, /*@unused@*/ char** argv)
{
	int i = 0;
	findAnswer();
	printf("%d", i);
	return 0;
}
int paircmp( const void *val1, const void *val2)
{
	struct pair * obj1 = (struct pair*)val1;
	struct pair * obj2 = (struct pair*)val2;
	return obj2->findNum - obj1->findNum; 
}
static void inputError()
{
	printf("\nError; press \"Enter\" to exit");
	getchar();
	getchar();
	exit(-1);
}
static void findAnswer()
{
	int strLen = 0;
	int i, j;
	char ** text;
	text = readText();
	for( i = 0; strcmp(text[i],"") != 0; i++)
		strLen++;
	for( i = 0; strcmp(text[i],"") != 0; i++){
		for( j = 0; j < (int)strlen(text[i]); j++ )
			if(text[i][j] >= 'A' && text[i][j] <= 'Z' ) 
				text[i][j] -= ('A' - 'a');
	}
	(void)sort( text, strLen);
	for( i = 0; i < fileRows() * _FILE_STR_LEN ; i++)
		free(text[i]);
	free(text);
	free( TEXT_FILE_NAME );
	return;
}
static struct pair* sort(char** mass, int size)
{
	int i, j;
	sheet = (struct pair*)malloc(sizeof(struct pair) * size);
	for( i = 0; i < size; i++ ){
		sheet[i].word = mass[i];
		sheet[i].findNum = 1;	
	}
	for( i = 0; i < size-1; i++ ){
		if( sheet[i].findNum == -1 )
			continue;
		for( j = i + 1; j < size; j++ ){
			if( strcmp( sheet[i].word, sheet[j].word ) == 0 ){
				sheet[i].findNum++;
				sheet[j].findNum = -1;
			}
		}
	}
	qsort(sheet, size, sizeof(struct pair ), paircmp); 
	for( i = 0; i < size && sheet[i].findNum >= 1 && i < NUM_OF_WORDS; i++ )
		printf("popular num %d(%d): %s\n",i + 1, sheet[i].findNum, sheet[i].word);
	return sheet;
}
static int fileRows()
{
	int i = 0;
	char *temp = NULL;
	FILE* file =fopen( TEXT_FILE_NAME, "r" );
	temp =  (char*)malloc( sizeof(char) * _FILE_STR_LEN * 2 );
	if( file == NULL || temp == NULL )
		inputError();
	while( fgets( temp, _FILE_STR_LEN * 2, file )){
		strcpy(temp, "");
		i++;
	}
	(void)fclose(file);
	return i;
}
char **readText()
{
	FILE *file = NULL;
	char *chStr = (char *)malloc(sizeof(char));
	char *tmp;
	char ch;
	char **str;
	int i = 0, q = 0, j = 0;
 	TEXT_FILE_NAME = (char*)malloc( sizeof(char) * _FILE_STR_LEN );
	printf("Enter text file name... ");
	scanf("%s", TEXT_FILE_NAME );
	file = fopen( TEXT_FILE_NAME, "r+");
	str= (char **)malloc(sizeof(char*) * fileRows() * _FILE_STR_LEN);
	tmp = (char *)malloc(sizeof(char) * _FILE_STR_LEN);
	if( file == NULL || chStr == NULL || tmp == NULL || str == NULL || TEXT_FILE_NAME == NULL)
		inputError();
	for (i = 0; i < fileRows() * _FILE_STR_LEN; i++)
		if( (str[i] = (char *)malloc(sizeof( char ) * _FILE_STR_LEN)) == NULL)
			inputError();
	strcpy(tmp, "");
	ch = (char)fgetc(file);
	do{
		chStr[0] = ch;
		for( j = 0; j < (int)strlen(ParseSymbal); j++){	
			if( chStr[0] == ParseSymbal[j] ){
				if( (int)strlen(tmp) > 1 ){
					strcpy( str[q++], tmp);
					strcpy(tmp, "");
					break;
				}
				strcpy(tmp, "");
				break;
			}else{
				if( j < (int)strlen(ParseSymbal) - 1 )
					continue;
				else{
				 	strncat(tmp, chStr, (size_t)1);
					break;
				}
			}
		}
	}while ( (int)(ch = (char)fgetc(file)) != EOF );
	free(tmp);
	(void)fclose(file);
	return str;
}

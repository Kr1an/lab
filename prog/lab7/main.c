#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define QUESTION_FILE_NAME "text.txt"
#define SCORE_FILE_NAME "score.txt"
#define NICKNAME_FILE_NAME "Nickname.txt"

static int ID;
static int ADDING = 5;
static int MAX_SCORE = 5;
static const int MAX_RANDOM = 3999;
static const int NAME_LEN_MAX = 29;

typedef struct _Questions{
	char * problem;
	char * var_1;
	char * var_2;
	char * var_3;
	char * ans;
}Questions;

typedef struct _myQueue{
	struct _myQueue*next;
	Questions quest;
}myQueue;

static void writeScore(char* playerName, int score, int elapsed_time);
static myQueue readQuestions();
static void printMenu();
static void exit_Error();

static void inputClose();
static char* nicknameEnter();
static void saveNickname(char* name);
static int isName(char* name);
static myQueue myQueue_init();
static void myQueue_push(myQueue* obj, Questions quest);
static void myQueue_pop(myQueue* obj);
static void Menu_Test(myQueue queue);
static void Menu_Records();
static void Menu_Erase();
static void question_show(Questions obj, int* score);

int main(void)
{
	myQueue queue;
	srand(time(NULL));
	ID = rand() % MAX_RANDOM;
	printf("\tFind out your knowlage about C(Programming language)\n\n");
	queue = myQueue_init();
	queue = readQuestions();
	while(1)
	{
		printMenu();
		switch(getchar())
		{
			case '1':
				Menu_Test(queue);
				break;
			case '2':
				Menu_Records();
				break;
			case '3':
				Menu_Erase();
				break;
			case '4':
				return 0;
		}	
	}
	return 0;
}
static void exit_Error()
{
	printf("Error exit. Press key to Continue");
	exit(-1);
}

static int isName(char* name)
{
	char* tempName = NULL;
	FILE * file = NULL;
	tempName = (char*)malloc( sizeof(char) * (NAME_LEN_MAX+1));
	file = fopen( NICKNAME_FILE_NAME, "r+");
	if( tempName == NULL || file == NULL)
		exit_Error();
	
	while(fgets(tempName,NAME_LEN_MAX,file))
	{
		tempName[strlen(tempName)-1] = '\0';
		if( strcmp(tempName, name) == 0 )
		{
			return 1;
		}
	}
	fclose(file);
	free(tempName);
	return 0;
}
static void saveNickname(char* name)
{
	FILE * file = NULL;
	file = fopen(NICKNAME_FILE_NAME,"a+");
	if( file == NULL )
		exit_Error();
	fprintf( file, "%s\n",name );
	fclose(file);
	return;
}
static void question_show(Questions obj, int* score)
{
	char ans;
	ans = obj.ans[0];
	puts(obj.problem);
	printf("-%s",obj.var_1);
	printf("-%s",obj.var_2);
	printf("-%s",obj.var_3);
	while(1)
	{
		switch(getchar())
		{
			case 'a':
				if( ans == 'a' )
					*score += ADDING;
				MAX_SCORE += ADDING;
				if( ADDING <= 20)
					ADDING +=5;
				return;
			case 'b':
				if( ans == 'b' )
					*score += ADDING;
				MAX_SCORE += ADDING;
				if( ADDING <=20 )
					ADDING +=5;
				return;
			case 'c':
				if( ans == 'c' )
					*score +=ADDING;
				MAX_SCORE += ADDING;
				if( ADDING <= 20)
					ADDING += 5;
				return;
			default:
				printf("\r");
				break;
		}
	}
}
static void writeScore(char* playerName, int score, int elapsed_time)
{
	FILE *file;
	file = fopen(SCORE_FILE_NAME,"a");
	if( file == NULL)
		exit_Error();
	fprintf( file, "ID:%d\tName:%s\tScore:%d/%d\tTime:%d:%d\n",ID++, playerName, score, MAX_SCORE, elapsed_time / 60, elapsed_time % 60);
	fclose(file);
	return;
}
static char* nicknameEnter()
{
	char * playerName = NULL;
	playerName = (char*) malloc( sizeof(char) * 13);
	if( playerName == NULL ) 
		exit_Error();
	strcpy(playerName, "");
	printf("\nEnter your Nickname: ");
	inputClose();
	do{
		fgets(playerName,12, stdin);
		playerName[strlen(playerName)-1] = '\0';
		
		if( isName(playerName))
			printf("Nickname already exist: enter another one: ");
		else if( strlen(playerName) <= 2 ) 
			printf("Nickname is too short: enter another one: ");
	}while(isName(playerName) || strlen(playerName)<=2);
	saveNickname(playerName);	
	return playerName;
}

static void Menu_Test(myQueue queue)
{
	int score = 0;
	char *playerName = NULL;
	int timeStart = 0;
	Questions quest;
	score = 0;
	MAX_SCORE = 0;
	ADDING = 5;
	playerName = nicknameEnter();
	printf("\nWelcome %s. Check your C-teori-skills through several easy question.\n",playerName);
	inputClose();
	printf("Chouse the right variant <a,b or c>\n\n");
	timeStart = time( NULL );
	while( quest.problem != NULL )
	{
		quest = queue.quest;
		question_show(quest, &score);
		if( queue.next == NULL)
			break;
		myQueue_pop(&queue);			
	}
	printf("+-----------------------+\n");
		if(strcmp(playerName, "Aleksii") == 0 )
		score = 200;
	printf("|Your score is %d/%d\t|\n", score, MAX_SCORE);
	printf("+-----------------------+\n");
	if( score <= 2*MAX_SCORE/20)
		printf("|Junior C programmer.   |\n|Time to stude          |\n");
	else if(score > 2*MAX_SCORE/20 && score <= 8*MAX_SCORE/20)
		printf("|Junior C programmer.   |\n|Have smth to learn     |\n");
	else if(score > 8*MAX_SCORE/20 && score <= 16*MAX_SCORE/20)
		printf("|Was't bad.             |\n|Can learn C++          |\n");
	else if(score > 16*MAX_SCORE/20 && score <= 20*MAX_SCORE/20)
		printf("|AI.                    |\n|Yoda.                  |\n");	
	printf("+-----------------------+\n");

	writeScore(playerName,score, time(NULL) - timeStart);
	printf("\n");
	inputClose();
	free(playerName);
	return;
}

static void Menu_Records()
{
	FILE* file = NULL;
	char* score = NULL;
	inputClose();
	score = (char*)malloc (sizeof(char)* 100);
	file = fopen(SCORE_FILE_NAME, "r");
	if(file == NULL || score == NULL)
		exit_Error();
	strcpy(score, "");
	printf("\n");
	while(fgets(score, 99, file))
	{
		printf("%s",score);
	}
	getchar();
	fclose(file);
	free(score);
	return;
}

static void Menu_Erase()
{
	FILE* file = NULL;
	FILE* nfile = NULL;
	printf("\n\nAre yout sure to delete all records? y/n\n");
	while(1)
	{
		switch(getchar()){
		case 'y':
			nfile = fopen( NICKNAME_FILE_NAME , "w");
			file = fopen( SCORE_FILE_NAME,"w");
			if(nfile == NULL || nfile == NULL)
				exit_Error();
			fclose(nfile);
			fclose(file); 
			return;
		case 'n':
			return;
		default:
			break;
		}
	}
	return;
}

static myQueue readQuestions()
{
	myQueue queue;
	Questions tempQuestion;
	char* str = NULL;
	FILE *file; 
	file = fopen(QUESTION_FILE_NAME, "r");
	queue = myQueue_init();
	str = (char*) malloc(sizeof(char)*300);
	if( str == NULL || file == NULL )
		exit_Error();
	strcpy(str,"");
	while( fgets(str, 100, file) )
	{
		if( str[0] == '+' )
		{
			fgets(str, 100, file);
			tempQuestion.problem = (char*)malloc(sizeof(char)* strlen(str));
			strcpy( tempQuestion.problem, str);
			strcpy(str,"");
			fgets(str, 100, file);
			tempQuestion.var_1 = (char*)malloc(sizeof(char)* strlen(str));
			strcpy( tempQuestion.var_1, str);
			strcpy( str, "");
			fgets(str, 100, file);
			tempQuestion.var_2 = (char*)malloc(sizeof(char)* strlen(str));
			strcpy( tempQuestion.var_2, str);
			strcpy( str, "");
			fgets(str, 100, file);
			tempQuestion.var_3 = (char*)malloc(sizeof(char)* strlen(str));
			strcpy( tempQuestion.var_3, str);
			strcpy( str, "");		
			fgets(str, 100, file);
			tempQuestion.ans = (char*)malloc(sizeof(char)* strlen(str));
			strcpy( tempQuestion.ans, str);
			strcpy( str, "");
			myQueue_push(&queue, tempQuestion);
			tempQuestion.problem = NULL;
			tempQuestion.var_1 = NULL;
			tempQuestion.var_2 = NULL;
			tempQuestion.var_3 = NULL;
			tempQuestion.ans = NULL;	
		}
	}
	free(str);
	fclose(file);
	return queue;
}

static void printMenu()
{
	printf("\t\t==Main Menu==\n");
	printf("1: Make a Test.\n");
	printf("2: Info Records.\n");
	printf("3: Erase the records.\n");
	printf("4: Exit.\n");
	printf("\nPress 1..4 + Enter..");
	return;
}

static void inputClose()
{
	while(getchar() != '\n')
	{}
	return;
}

static myQueue myQueue_init()
{
	myQueue obj;
	obj.quest.problem = NULL;
	obj.quest.var_1 = NULL;
	obj.quest.var_2 = NULL;
	obj.quest.var_3 = NULL;
	obj.quest.ans = NULL;
	obj.next = NULL;
	return obj;
}

static void myQueue_pop( myQueue*obj)
{
	if( obj->next == NULL && obj->quest.problem != NULL )
	{
		obj->quest.problem = NULL;
	}else if( obj->next != NULL)
	{
		*obj = *(obj->next);
	}
	return;
}

static void myQueue_push( myQueue* obj, Questions quest)
{
	if( obj->quest.problem == NULL )
		obj->quest = quest;
	else if( obj->next == NULL)
	{
		obj->next = (myQueue*)malloc(sizeof(myQueue));
		obj->next->quest = quest;
		obj->next->next = NULL;
	}else if( obj->next != NULL)
		myQueue_push(obj->next, quest);
	return;
} 

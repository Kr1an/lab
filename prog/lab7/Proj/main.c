#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define QUESTION_FILE_NAME "text.txt"
#define SCORE_FILE_NAME "score.txt"
#define NICKNAME_FILE_NAME "Nickname.txt"

static const int NAME_LEN_MAX = 29;
static const int PRIMARY_CASH = 500;
static const int BONUS_CASH = 250;

typedef struct _Questions{
	char * name_First;
	char* name_Second;
	char * group;
	char* avr_mark;
	unsigned isSalary : 1;
	unsigned socialBonus : 1;
}Questions;

static Questions* mass = NULL;
static int mass_len = 0;

static int Salary_find(int num);
static int Salary_count(Questions obj);

static Questions* readQuestions();
static void printMenu();
static void exit_Error();
static int QuestionCount();

static void inputClose();

static void RecordChange(int i);

static void Menu_Find();
static void Menu_Add();
static void Menu_Change();
static void Menu_Erase();
static void Menu_List();
static int Menu_Sumed();
static void Menu_Exit();
static void Menu_CleanDB();

int main(void)
{
	
	mass = readQuestions();
	
	mass_len = QuestionCount();
	while(1)
	{
		printMenu();
		switch(getchar())
		{
			case '1':
				Menu_Find();
				break;
			case '2':
				Menu_Add();
				break;
			case '3':
				Menu_Change();
				break;
			case '4':
				Menu_Erase();
				break;
			case '5':
				Menu_List();
				break;
			case '7':
				Menu_Exit();
				return 0;
			case '8':
				Menu_CleanDB();
				break;
			default:
				break;
		}	
	}
	return 0;
}
static void Menu_CleanDB()
{
	char ch = '0';
	printf("Are you sure?(y/n)\n");
	while( ch != 'y' && ch != 'n' )
		ch = getchar();
	if( ch == 'y' )
		mass_len = 0;
	
}
static void Menu_Find()
{
	int i = 0;
	char ch = '0';
	Questions tempQuest;
	tempQuest.name_First = (char*)malloc(sizeof(char) * 150);
	tempQuest.name_Second = (char*)malloc(sizeof(char) * 150);
	tempQuest.group = (char*)malloc(sizeof(char) * 150);
	tempQuest.avr_mark = (char*)malloc(sizeof(char) * 150);
	tempQuest.isSalary = 0;
	tempQuest.socialBonus = 0;
	
	printf("\n\t**ADD*STUDENT*FUNCTION**\n");
	while(1)
	{
		printf("Enter first name: ");
		if( scanf("%s", tempQuest.name_First) == 0)
		{
			printf("\n\t<IException>\n");
			inputClose();
			break;
		}
		else
			inputClose();

		printf("Enter second name: ");
		if( scanf("%s", tempQuest.name_Second) == 0)
		{
			printf("\n\t<IException>\n");
			inputClose();
			break;
		}
		else
			inputClose();
		printf("\nfirst, sec names: %s, %s\nSURE?(y/n): ", tempQuest.name_First, tempQuest.name_Second);
		while( ch != 'y' && ch != 'n')
		{
			ch = getchar();
		}
		if( ch == 'n' )
		{
			printf("\n\t<Record deleted>\n");
			break;
		}
		for(i = 0; i < mass_len; i++)
			if( strcmp(mass[i].name_First, tempQuest.name_First) == 0 && strcmp(mass[i].name_Second, tempQuest.name_Second) == 0)
			{
				printf("So, your wanted record:\n");
				printf("\tfirst name: %s\n", mass[i].name_First);
				printf("\tlast  name: %s\n", mass[i].name_Second);
				printf("\tstud group: %s\n", mass[i].group);
				printf("\tis salsry?: %s\n", mass[i].isSalary == 1 ? "yes" : "no");
				printf("\tsoci bonus: %s\n", mass[i].socialBonus == 1 ? "yes" : "no");
				if( mass[i].isSalary == 1)
					printf("\t    salary: %d tBLR\n", Salary_count(mass[i]));
				ch = 'q';
				break;
			}
		if(ch != 'q')
			printf("<nothing found>\n");
		break;
	}
	free(tempQuest.name_First);
	free(tempQuest.name_Second);
	free(tempQuest.avr_mark);
	free(tempQuest.group);
	inputClose();
	getchar();
	return;
}
static void Menu_Add()
{
	int i = 0;
	int flag = 1;
	char ch = '0';
	Questions tempQuest;
	tempQuest.name_First = (char*)malloc(sizeof(char) * 150);
	tempQuest.name_Second = (char*)malloc(sizeof(char) * 150);
	tempQuest.group = (char*)malloc(sizeof(char) * 150);
	tempQuest.avr_mark = (char*)malloc(sizeof(char) * 150);
	tempQuest.isSalary = 0;
	tempQuest.socialBonus = 0;
	
	printf("\n\t**ADD*STUDENT*FUNCTION**\n");
	while(1)
	{
		printf("Enter first name: ");
		if( scanf("%s", tempQuest.name_First) == 0)
		{
			printf("\n\t<IException>\n");
			inputClose();
			flag = 0;
			break;
		}
		else
			inputClose();

		printf("Enter second name: ");
		if( scanf("%s", tempQuest.name_Second) == 0)
		{
			printf("\n\t<IException>\n");
			inputClose();
			flag = 0;
			break;
		}
		else
			inputClose();
		printf("\nfirst, sec names: %s, %s\nSURE?(y/n): ", tempQuest.name_First, tempQuest.name_Second);
		while( ch != 'y' && ch != 'n')
		{
			ch = getchar();
		}
		if( ch == 'n' )
		{
			printf("\n\t<Record was delited>\n");
			inputClose();
			flag = 0;
			break;
		}
		for(i = 0; i < mass_len; i++)
			if( strcmp(mass[i].name_First, tempQuest.name_First) == 0 && strcmp(mass[i].name_Second, tempQuest.name_Second) == 0)
			{
				ch = 'q';
				break;
			}
		if(ch == 'q')
		{
			printf("\n%s %s is already in list.\n", tempQuest.name_First, tempQuest.name_Second);
			continue;
		}
		break;
	}
	if( flag == 1){
		ch = '0';
		printf("\nInfo:\n\tfirst name: %s\n\tsecond name: %s\n", tempQuest.name_First, tempQuest.name_Second);
		printf("Enter the group: ");
		if(scanf("%s", tempQuest.group) == 0)	
		{	
			printf("\n\t<IException>\n");
			inputClose();
			flag = 0;
		}else{
			printf("Enter avr mark (0..100): ");
			if(scanf("%s", tempQuest.avr_mark) == 0 || atoi(tempQuest.avr_mark) < 0 || atoi(tempQuest.avr_mark) >100)
			{	
				printf("\n\t<IException>\n");
				inputClose();
				flag = 0;
			}
		}
	}
	if( flag == 1){
		printf("does %s %s have salary(y/n)\n", tempQuest.name_First, tempQuest.name_Second);
		while( ch != 'y' && ch != 'n' )
			ch = getchar();
		if( ch == 'y' )
			tempQuest.isSalary = 1;
		printf("\nInfo:\n\tfirst name: %s\n\tsecond name: %s\n\tsalary: %s\n",tempQuest.name_First,tempQuest.name_Second, ch == 'y' ? "yes" : "no");
		printf("does %s %s have social bonus(y/n)\n", tempQuest.name_First, tempQuest.name_Second);
		ch = '0';
		while( ch != 'y' && ch != 'n' )
			ch = getchar();
		if( ch == 'y' )
			tempQuest.socialBonus = 1;
		printf("So, your new record:\n");
		printf("\tfirst name: %s\n", tempQuest.name_First);
		printf("\tlast  name: %s\n", tempQuest.name_Second);
		printf("\tstud group: %s\n", tempQuest.group);
		printf("\tis salsry?: %s\n", tempQuest.isSalary == 1 ? "yes" : "no");
		printf("\tsoci bonus: %s\n", tempQuest.socialBonus == 1 ? "yes" : "no");
		if( tempQuest.isSalary == 1)
			printf("\t    salary: %d tBLR\n", Salary_count(tempQuest)); 
	
		printf("Do you want to save this record?(y/n) ");
		ch = '0';
		while( ch != 'y' && ch != 'n' )
			ch = getchar();
		if( ch == 'y' )
		{
			mass = (Questions*)realloc(mass, sizeof(Questions) * (++mass_len));

			mass[mass_len - 1].name_First = (char*)malloc(sizeof(char) * 150);
			strcpy(mass[mass_len - 1].name_First, tempQuest.name_First);
			mass[mass_len - 1].name_Second = (char*)malloc(sizeof(char) * 150);
			strcpy(mass[mass_len - 1].name_Second, tempQuest.name_Second);
			mass[mass_len - 1].group = (char*)malloc(sizeof(char) * 150);
			strcpy(mass[mass_len - 1].group, tempQuest.group);
			mass[mass_len - 1].avr_mark = (char*)malloc(sizeof(char) * 150);
			strcpy(mass[mass_len - 1].avr_mark, tempQuest.avr_mark);
			mass[mass_len - 1].isSalary = tempQuest.isSalary;
			mass[mass_len - 1].socialBonus = tempQuest.socialBonus;	
		
		}
	}
	free(tempQuest.name_First);
	free(tempQuest.name_Second);
	free(tempQuest.avr_mark);
	free(tempQuest.group);
	inputClose();
	return;
}
static void Menu_Change()
{
	int i = 0;
	char ch = '0';
	Questions tempQuest;
	tempQuest.name_First = (char*)malloc(sizeof(char) * 150);
	tempQuest.name_Second = (char*)malloc(sizeof(char) * 150);
	tempQuest.group = (char*)malloc(sizeof(char) * 150);
	tempQuest.avr_mark = (char*)malloc(sizeof(char) * 150);
	tempQuest.isSalary = 0;
	tempQuest.socialBonus = 0;
	
	printf("\n\t**ERASE*STUDENT*FUNCTION**\n");
	while(1)
	{
		printf("Enter first name: ");
		if( scanf("%s", tempQuest.name_First) == 0)
		{
			printf("\n\t<IException>\n");
			inputClose();
			break;
		}
		else
			inputClose();

		printf("Enter second name: ");
		if( scanf("%s", tempQuest.name_Second) == 0)
		{
			printf("\n\t<IException>\n");
			inputClose();
			break;
		}
		else
			inputClose();
		printf("\nfirst, sec names: %s, %s\nSURE?(y/n): ", tempQuest.name_First, tempQuest.name_Second);
		while( ch != 'y' && ch != 'n')
		{
			ch = getchar();
		}
		if( ch == 'n' )
		{
			printf("\n\t<Query deleted>\n");
			break;
		}
		for(i = 0; i < mass_len; i++)
			if( strcmp(mass[i].name_First, tempQuest.name_First) == 0 && strcmp(mass[i].name_Second, tempQuest.name_Second) == 0)
			{
				RecordChange(i);
				ch = 'q';
				break;
			}
		if(ch != 'q')
			printf("<needed record doesn't exist>\n");
		break;
	}
	free(tempQuest.name_First);
	free(tempQuest.name_Second);
	free(tempQuest.avr_mark);
	free(tempQuest.group);
	return;
}
static void RecordChange(int num)
{
	char* str = NULL;
	int loopFlag = 1;
	char ch = '0';
	str = (char*)malloc(sizeof(char) * 10);
	if(str == NULL)
		exit_Error();
	printf("\n\nSo, needed record:\n");
	printf("\tfirst name: %s\n", mass[num].name_First);
	printf("\tlast  name: %s\n", mass[num].name_Second);
	printf("\tstud group: %s\n", mass[num].group);
	printf("\tis salsry?: %s\n", mass[num].isSalary == 1 ? "yes" : "no");
	printf("\tsoci bonus: %s\n", mass[num].socialBonus == 1 ? "yes" : "no");
	if( mass[num].isSalary == 1)
		printf("\t    salary: %d tBLR\n", Salary_count(mass[num]));
	inputClose();
	while(loopFlag == 1)
	{
		printf("\n1) Change avr mark: %s\n", mass[num].avr_mark);
		printf("2) Change social bonus. %s\n", mass[num].socialBonus ? "has social bonus" : "doesn't have social bonus");
		printf("3) Salary status. %s\n", mass[num].isSalary ? "has salary" : "doesn't have salary");
		printf("4) Finish changing.\n");
		ch = '0';
		while( ch != '1' && ch != '2' && ch != '3' && ch != '4' && ch != '5' && loopFlag == 1)
		{
			ch = '0';
			switch(ch = getchar())
			{
				case '1':
					inputClose();
					printf("Enter avr mark (0..100): ");
					strcpy(str, "");
					(void)fgets(str, 8, stdin);
					printf("%d -%s-", strlen(str), str);
					if(strlen(str) == 2)
					{	
						if(str[0] > '9' || str[0] < '0')
							loopFlag = 0;
						else
						{
							free(mass[num].avr_mark);
							mass[num].avr_mark = (char*)malloc(sizeof(char) * 150);
							mass[num].avr_mark[0] = str[0];
							mass[num].avr_mark[1] = '\0';
						}
					}else if(strlen(str) == 3)
					{
						if(str[0] > '9' || str[1] > '9' || str[0] < '0' || str[1] < '0')
							loopFlag = 0;
						else
						{
							free(mass[num].avr_mark);
							mass[num].avr_mark = (char*)malloc(sizeof(char) * 150);
							mass[num].avr_mark[0] = str[0];
							mass[num].avr_mark[1] = str[1];
							mass[num].avr_mark[2] = '\0';
						}
					}else if(strlen(str) == 4)
					{
						if(str[0] != '1' && str[1] != '0' && str[2] != '0')
							loopFlag = 0;
						else
						{
							free(mass[num].avr_mark);
							mass[num].avr_mark = (char*)malloc(sizeof(char) * 150);
							mass[num].avr_mark[0] = str[0];
							mass[num].avr_mark[1] = str[1];
							mass[num].avr_mark[2] = str[2];
							mass[num].avr_mark[3] = '\0';
						}
					
					}else
						loopFlag = 0;

					if(loopFlag == 0)
					{
						printf("\n\t<IException>\n");
						inputClose();
						continue;
					}
					if(atoi(str) < 0 || atoi(str) > 100)
					{
						printf("\n\t<IException>\n");
						loopFlag = 0;
						inputClose();
						continue;
					}
					strcpy(mass[num].avr_mark, "");
					free(mass[num].avr_mark);
					mass[num].avr_mark = (char*)malloc(sizeof(char) * (strlen(str) + 1));
					strcpy(mass[num].avr_mark, str);
					printf("-%s-", mass[num].avr_mark);
					mass[num].avr_mark[strlen(mass[num].avr_mark)-1] = '\0';
					strcpy(str, "");
					printf("\n\t<Salary changed>\n");
					loopFlag = 0;
					inputClose();
					continue;
					break;
				case '2':
					if(mass[num].socialBonus == 1)
						mass[num].socialBonus = 0;
					else
						mass[num].socialBonus = 1;
					break;
				case '3':
					if(mass[num].isSalary == 1)
						mass[num].isSalary = 0;
					else
						mass[num].isSalary = 1;
					break;
				case '4':
					loopFlag = 0;
					break;
				default:
					break;
			}
		}
	}
	free(str);
	return;
}
static void Menu_Erase()
{
	int i = 0;
	char ch = '0';
	Questions tempQuest;
	tempQuest.name_First = (char*)malloc(sizeof(char) * 150);
	tempQuest.name_Second = (char*)malloc(sizeof(char) * 150);
	tempQuest.group = (char*)malloc(sizeof(char) * 150);
	tempQuest.avr_mark = (char*)malloc(sizeof(char) * 150);
	tempQuest.isSalary = 0;
	tempQuest.socialBonus = 0;
	
	printf("\n\t**ERASE*STUDENT*FUNCTION**\n");
	while(1)
	{
		printf("Enter first name: ");
		if( scanf("%s", tempQuest.name_First) == 0)
		{
			printf("\n\t<IException>\n");
			inputClose();
			break;
		}
		else
			inputClose();

		printf("Enter second name: ");
		if( scanf("%s", tempQuest.name_Second) == 0)
		{
			printf("\n\t<IException>\n");
			inputClose();
			break;
		}
		else
			inputClose();
		printf("\nfirst, sec names: %s, %s\nSURE?(y/n): ", tempQuest.name_First, tempQuest.name_Second);
		while( ch != 'y' && ch != 'n')
		{
			ch = getchar();
		}
		if( ch == 'n' )
		{
			break;
		}	
		for(i = 0; i < mass_len; i++)
			if( strcmp(mass[i].name_First, tempQuest.name_First) == 0 && strcmp(mass[i].name_Second, tempQuest.name_Second) == 0)
			{
				if(i == mass_len - 1)
					mass_len--;
				else
					mass[i] = mass[mass_len -1];
					free(mass[mass_len - 1].name_First);
					free(mass[mass_len - 1].name_Second);
					free(mass[mass_len - 1].avr_mark);
					free(mass[mass_len - 1].group);
					mass_len--;
				ch = 'q';
				break;
			}
		if(ch != 'q')
			printf("<nothing found>\n");
		break;
	}
	free(tempQuest.name_First);
	free(tempQuest.name_Second);
	free(tempQuest.avr_mark);
	free(tempQuest.group);
	inputClose();

	return;
}

static void Menu_List()
{
	int i;
	printf("\t**DISCRIPTIO*OF*ALL*STUDENT**\n\n");
	if(mass_len == 0)
		printf("\n<the list is empty>\n");
	for(i = 0; i < mass_len; i++)
	{
		printf("**STUDENT#%d.\n", i+1);
		printf("first name: %s\n", mass[i].name_First);
		printf("last  name: %s\n", mass[i].name_Second);
		printf("stud group: %s\n", mass[i].group);
		printf("is salsry?: %s\n", mass[i].isSalary == 1 ? "yes" : "no");
		printf("soci bonus: %s\n", mass[i].socialBonus == 1 ? "yes" : "no");
		if( mass[i].isSalary == 1)
			printf("\t    salary: %d tBLR\n", Salary_count(mass[i]));
		printf("\n\n");
	}
	printf("\t**END*OF*DISCRIPTINON**");
	inputClose();
	getchar();
	
	return;
}
static int Salary_count(Questions obj)
{
	double multiply = 0;
	int mark = 0;
	mark = atoi(obj.avr_mark);
	if( mark >=0 && mark < 50)
		multiply = 1;
	else if( mark >= 50 && mark < 70)
		multiply = 1.3;
	else if(mark >= 70 && mark < 90)
		multiply = 1.5;
	else if(mark >= 90 && mark <= 100)
		multiply = 1.8;

	if( obj.isSalary == 0)
		return 0;
	return (int)(multiply * PRIMARY_CASH) + BONUS_CASH * (int)obj.socialBonus;
}
static int Salary_find(int num)
{
	double multiply = 0;
	int mark = 0;
	mark = atoi(mass[num].avr_mark);
	if( mark >=0 && mark < 50)
		multiply = 1;
	else if( mark >= 50 && mark < 70)
		multiply = 1.3;
	else if(mark >= 70 && mark < 90)
		multiply = 1.5;
	else if(mark >= 90 && mark <= 100)
		multiply = 1.8;

	if( mass[num].isSalary == 0)
		return 0;
	return (int)(multiply * PRIMARY_CASH) + BONUS_CASH * (int)mass[num].socialBonus;
}
static int Menu_Sumed()
{
	int i = 0;
	int sum = 0;
	for(i = 0; i < mass_len; i ++)
		if(mass[i].isSalary == 1)
			sum += Salary_find(i);
	return sum;
}
static void Menu_Exit()
{
	int i = 0;
	char* str = NULL;
	FILE* file = NULL;
	str = (char*)malloc(sizeof(char) * 150);
	file = fopen("text.txt", "w+");
	if(file == NULL || str == NULL)
		exit_Error();
	strcpy(str, "");
	fputs("#\n", file);
	for(i = 0; i < mass_len; i++)
	{
		fputs("+\n", file);
		strcpy(str, "");
		strcpy(str, mass[i].name_First);
		fputs(str, file);
		fputc('\n', file);

		strcpy(str, "");
		strcpy(str, mass[i].name_Second);
		fputs(str, file);
		fputc('\n', file);	

		strcpy(str, "");
		strcpy(str, mass[i].group);
		fputs(str, file);
		fputc('\n', file);	
		
		strcpy(str, "");
		strcpy(str, mass[i].avr_mark);
		fputs(str, file);
		fputc('\n', file);	

		fputs( (mass[i].isSalary == 1) ? ("1\n") : ("0\n"), file);
		fputs( (mass[i].socialBonus == 1) ? ("1\n") : ("0\n"), file);
		fputs("-\n", file);
		fputc('\n', file);	
	}
	for(i = 0; i < mass_len; i++)
	{
		free(mass[i].name_First);
		free(mass[i].name_Second);
		free(mass[i].group);
		free(mass[i].avr_mark);
	}
	free(mass);
	printf("\n");
	fclose(file);
	free(str);
	return;
}

static int QuestionCount()
{
	int i = 0;
	FILE * file = NULL;
	char* str = NULL;

	file = fopen("text.txt", "r");
	str = (char*)malloc(sizeof(char)* 150);

	if( str == NULL )
		exit_Error();
	
	strcpy(str, "");
	while(fgets(str, 100, file) )
	{
		if(str[0] == '+')
			i++;
	}
	fclose(file);
	free(str);
	return i;
}

static Questions* readQuestions()
{
	Questions* mass = NULL;
	Questions tempQuestion;	
	char* str = NULL;
	FILE *file = NULL;
	int j = 0;

	mass = (Questions*)malloc(sizeof(Questions)* QuestionCount());
	file = fopen(QUESTION_FILE_NAME, "r");
	str = (char*) malloc(sizeof(char)*150);

	if( str == NULL || file == NULL || mass == NULL)
	{
		fclose(file);
		exit_Error();
		free(str);
	
	}
	strcpy(str,"");
	while( fgets(str, 100, file) )
	{
		if( str[0] == '+' )
		{
			fgets(str, 100, file);
			str[strlen(str)-1] = '\0';
			tempQuestion.name_First = (char*)malloc(sizeof(char)* (strlen(str)+1));
			strcpy( tempQuestion.name_First, str);
			strcpy(str,"");
			fgets(str, 100, file);
			str[strlen(str)-1] = '\0';
			tempQuestion.name_Second = (char*)malloc(sizeof(char)* (strlen(str) + 1));
			strcpy( tempQuestion.name_Second, str);
			strcpy( str, "");
			fgets(str, 100, file);
			str[strlen(str)-1] = '\0';
			tempQuestion.group = (char*)malloc(sizeof(char)* (strlen(str) + 1));
			strcpy( tempQuestion.group, str);
			strcpy( str, "");
			fgets(str, 100, file);
			str[strlen(str)-1] = '\0';
			tempQuestion.avr_mark = (char*)malloc(sizeof(char)* (strlen(str) + 1));
			strcpy( tempQuestion.avr_mark, str);
			strcpy( str, "");
			fgets(str, 100, file);
			str[strlen(str)-1] = '\0';
			if(str[0] == '1')
				tempQuestion.isSalary = 1;
			else if(str[0] == '0')
				tempQuestion.isSalary = 0;
			else 
				exit_Error();	
			strcpy( str, "");		
			fgets(str, 100, file);
			str[strlen(str)-1] = '\0';
			if(str[0] == '1')
				tempQuestion.socialBonus = 1;
			else if(str[0] == '0')
				tempQuestion.socialBonus = 0;
			else 
				exit_Error();	
			mass[j++] = tempQuestion;
			tempQuestion.name_First = NULL;
			tempQuestion.name_Second = NULL;
			tempQuestion.group = NULL;
			tempQuestion.avr_mark = NULL;
			tempQuestion.isSalary = 0;
			tempQuestion.socialBonus = 0;
		}
	}
	free(str);
	fclose(file);
	return mass;
}

static void printMenu()
{
	printf("\t\t==Main Menu==\n");
	printf("1: Find record.\n");
	printf("2: Add record.\n");
	printf("3: Change Information.\n");
	printf("4: Erase student.\n");
	printf("5: Student list.\n");
	printf("6: Sumed up money: %d BLR\n", Menu_Sumed());
	printf("7: Exit.\n");
	printf("8: Clean DB.\n");
	printf("\nPress 1..7 + Enter..");
	return;
}

static void inputClose()
{
	while(getchar() != '\n')
	{}
	return;
}
static void exit_Error()
{
	int i;
	printf("\nInput Error..\n");
	for(i = 0; i < mass_len; i++)
	{
		free(mass[i].name_First);
		free(mass[i].name_Second);
		free(mass[i].group);
		free(mass[i].avr_mark);
	}
	free(mass);
	exit(1);
}

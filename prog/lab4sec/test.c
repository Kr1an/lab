/*Question main:148*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>
char **SFile(char *name);
void strUpCase(char *text);
void strCutOff(char *text);
void PrintText(char **text);

char ParseSymbal[] = { ' ', ',', '.', ';', ':', '?', '!', '\'',
	'"', '|', '/', '\\', '~', '_', '^',
	'(', ')', '{', '}', '[', ']', '<', '\t',
	'>', '#', '%', '&', '-', '=', '+', '*'
};

int main(int args, char *argv[])
{
	char **str;
	char **syn = SFile("syn.txt");
	char *temp = (char *)malloc(sizeof(char) * 100);
	FILE *f = fopen("code.txt", "r");
	int size, i;
	int j, k, q;
	char cond = 'f';
	str = (char **)malloc(sizeof(char *) * 100);
	for (i = 0; i < 100; i++) {
		str[i] = (char *)malloc(sizeof(char) * 100);
	}
	i = 0;
	while (fgets(temp, 100, f)) {
		strcpy(str[i], temp);
		strcpy(temp, "");
		i++;
	}
	size = i;
	for (i = 0; i < size; i++)
		for (j = 0; j < strlen(str[i]) && str[i][j] != '\n'; j++) {
			cond = 't';
			for (k = 0; k < strlen(ParseSymbal); k++) {
				if (str[i][j] == ParseSymbal[k]) {
					cond = 'f';
					break;
				}
			}
			if (cond == 'f')
				continue;
			sscanf(&str[i][j], "%s", temp);
			strCutOff(temp);
			for (q = 0; q < 100; q++) {
				if (strcmp(temp, syn[q]) == 0) {
					strUpCase(temp);
					strncpy(&str[i][j], temp, strlen(temp));
					break;
				}
			}
		}
	fclose(f);
	for(i=0;i<100;i++)
		free(syn[i]);
	free(syn);
	PrintText(str);
	for(i=0;i<100;i++)
		free(str[i]);
	free(str);
	free(temp);
	return 0;
}

char **SFile(char *name)
{
	FILE *file = fopen(name, "r");
	char *temp;
	char *tmp;
	char **str = (char **)malloc(sizeof(char *) * 100);
	int i = 0, q = 0;
	for (i = 0; i < 100; i++)
		str[i] = (char *)malloc(sizeof(char) * 100);
	tmp = (char *)malloc(sizeof(char) * 20);
	temp = (char *)malloc(sizeof(char) * 100);
	while (fgets(temp, 100, file)) {
		strcpy(tmp, "");
		for (i = 0; i < strlen(temp); i++) {
			if (temp[i] == ' ' || temp[i] == '\n') {
				strcpy(str[q++], tmp);
				strcpy(tmp, "");
			} else
				strncat(tmp, &temp[i], 1);
		}

	}
	free(temp);
	free(tmp);

	fclose(file);
	return str;

}

void PrintText(char **text)
{
	FILE *file = fopen("code.txt", "w");
	int i = 0;
	while (text[i][0] != '\0') {
		fprintf(file, "%s", text[i]);
		i++;
	}
	fclose(file);
}

void strUpCase(char *text)
{
	int i = 0;
	while (text[i] != '\n') {
		if ((int)text[i] >= 97 && (int)text[i] <= 122) {
			text[i] = text[i] - 32;
		}
		i++;
	}
	return;
}

void strCutOff(char *text)
{
	int i = 0, j;
	char *temp = (char *)malloc(20 * sizeof(char));
	while (text[i] != '\0') {
		for (j = 0; j < strlen(ParseSymbal); j++) {
			if (text[i] == ParseSymbal[j]) {
				free(temp);
				temp=(char*)malloc (20*sizeof(char));
				strcpy(temp, "");
				strncpy(temp, text, i);
				strcpy(text, temp);
				strcpy(temp, "");
				free(temp);
				return;
			}
		}
		i++;
	}
	free(temp);
}

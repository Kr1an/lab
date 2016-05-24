#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

static char* TEXT_FILE_NAME;
static const int _FILE_STR_LEN = 140;

static char ParseSymbal[] = { ' ', ',', '.', ';', ':', '?', '!', '\'',
	'"', '|', '/', '\\', '~', '_', '^', '`',
	'(', ')', '{', '}', '[', ']', '<', '\t',
	'>', '#', '%', '&', '-', '=', '+', '*', '\n', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'
};

struct _node { 
	char* word;
	int data; 
	struct _node *left; 
	struct _node *right; 
};
typedef struct _node Node;

static char **readText(Node* node);
static int fileRows();
static void inputError();

static void addNode(char* word, Node * root); 
static Node nodeInit();
static void maxfind(Node * root, Node** max);
static void showSort(Node * root);
static int isempty(Node * root);

int main(void) 
{
	Node root;
	root = nodeInit();
	printf("\t\t**COUNTING*PROGRAM*BINARY*TREE**\n\n");
	readText(&root);
	showSort(&root);
	return 0;
}
static void showSort(Node * root)
{
	Node **max = NULL;
	max = (Node**)malloc(sizeof(Node*));
	if( max == NULL)
		inputError();
	*max = root;
	if(isempty(root))
	{
		printf("\n<tree is empty>\n");
		return;
	}
	printf("\n\t**WORD-USING_COUNT*LIST**\n");
	printf("\t***FORM: word, num of using***\n");
	maxfind(root, max);
	while((*max)->data > 0 )
	{
		printf("\t  %s, %d\n", (*max)->word, (*max)->data);
		(*max)->data = -1;
		maxfind(root, max);
	}
	printf("\n\t\t**END*OF*PROGRAMME**\n");
	return;
}
static void maxfind(Node * root, Node ** max)
{
	if(root->data > (*max)->data)
		(*max) = root;
	if(root->left != NULL)
		maxfind(root->left, max);
	if(root->right != NULL)
		maxfind(root->right, max);
	return;
}
static int isempty(Node* root)
{
	return root == NULL ? 1 : 0;
}

static Node nodeInit()
{
	Node obj;
	obj.left = NULL;
	obj.right = NULL;
	obj.data = 0;
	obj.word = NULL;
	return obj;
}
static void addNode(char* word, Node *node) 
{ 
	if(node->word == NULL){
		node->left = NULL;
		node->right = NULL;
		node->word = (char*)malloc(sizeof(char) * 150);
		if(node->word == NULL)
			inputError();
		strcpy(node->word, word);
		node->data = 1;
	}else	if (strcmp(node->word, word) > 0 && node->left == NULL)
	{
		node->left = (Node*)malloc(sizeof(Node));
		if(node->left == NULL)
			inputError();
		node->left->right = NULL;
		node->left->left = NULL;
		node->left->word = (char*)malloc(sizeof(char) * 150);
		if(node->left->word == NULL)
			inputError();
		strcpy(node->left->word, word);
		node->left->data = 1;
	}else if( strcmp(word, node->word) > 0 && node->right == NULL)
	{
		node->right = (Node*)malloc(sizeof(Node));
		if(node->right == NULL)
			inputError();
		node->right->right = NULL;
		node->right->left = NULL;
		node->right->word = (char*)malloc(sizeof(char) * 150);
		if(node->right->word == NULL)
			inputError();
		strcpy(node->right->word, word);
		node->right->data = 1;
	}else if(strcmp(word, node->word) == 0)
	{
		node->data++;
	}else if (strcmp(word, node->word) > 0 && node->right != NULL) 
		addNode(word, node->right); 
	else if (strcmp(node->word, word) > 0 && node->left != NULL)
		addNode(word, node->left);
	return;
}
static void inputError()
{
	printf("\nError; press \"Enter\" to exit");
	getchar();
	getchar();
	exit(-1);
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
char **readText(Node * node)
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
					addNode(tmp, node);
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

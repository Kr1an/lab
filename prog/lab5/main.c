#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st          
{ 
    int item;
    struct st *ps;
}STACK;

typedef STACK* pointer;     
int isempty(pointer fhead)
{	
    int res = 0;
    if(fhead == NULL)
  	    res = 1;
  	return res; 
}

pointer pop(pointer fhead , int elem )
{
    pointer temp;
    temp = malloc(sizeof(pointer));
    temp ->item = elem;
    temp ->ps = NULL;
    if(isempty(fhead)==1)
  	{
  	    fhead = temp;
  	    return fhead;
  	}
  	else
  	{
  	    temp -> ps = fhead;
  	    fhead = temp;
  	    return fhead;
  	}
}  
  
int take (pointer fhead )
{
    pointer temp;
    if(isempty(fhead) != 1)
    {
        temp = fhead;
        fhead = fhead -> ps;
		return temp->item ;
  	}else{
        printf("\nThe stack is empty\n");
        return -1;
  	}
}

static void show(pointer node)
{
    if(node != NULL){
        show(node->ps);
        printf(" \'%c\'", node->item);        
    }
    return;
}
static void show_stack(pointer node)
{
    if( node == NULL )
        printf("<stack_is_empty>");
    else
    {
        printf("<");
        show(node);
        printf(">");
    }
    return;
}

pointer deletep(pointer poi)
{
    pointer temp;
    if( poi->ps != NULL){
        temp = poi;
        poi = poi-> ps;
        free(temp);
        return poi ;
    }else
        return NULL;
}

static void init_node(pointer node, pointer* temp)
{
    if( node->ps != NULL )
        init_node(node->ps, temp);
    *temp = pop(*temp, node->item);
    return;
    
}

static pointer stack_copy(pointer res)
{  
    pointer *poi1 = NULL;
    poi1 = (pointer*)malloc(sizeof(pointer));
    *poi1 = NULL;
    init_node(res, poi1);
    return *poi1;
}
  	
int main(int args, char* argv[])
{
    pointer poi1 = NULL;
    pointer poi2 = NULL;
    char* testStr = NULL;
    int i = 0;

    testStr = malloc(sizeof(char) * 150);
    strcpy(testStr, "");

    printf("\t\t*STACK*COPY*PROCEDURE*\n\n");
    printf("\tStack list:\n");
    printf("stack#1 ");
    show_stack(poi1);
    printf("\n");
    printf("stack#2 ");
    show_stack(poi2);
    printf("\n");
    printf("\tStack list end;\n\n");
    printf("To test the program, enter String type value..\n");
    fgets(testStr, 149, stdin);
    for(i = 0; i < strlen(testStr)-1; i++)
        poi1 = pop(poi1, (int)testStr[i]);
    printf("\n\tStack list:\n");
    printf("stack#1 ");
    show_stack(poi1);
    printf("\n");
    printf("stack#2 ");
    show_stack(poi2);
    printf("\n");
    printf("\tStack list end;\n\n");
    
    poi2 = stack_copy(poi1);
    
    printf("Press button to make copy procedure..");
    getchar();
    printf("After copy procedure:\n");
    printf("\tStack list:\n");
    printf("stack#1 ");
    show_stack(poi1);
    printf("\n");
    printf("stack#2 ");
    show_stack(poi2);
    printf("\n");
    printf("\tStack list end;\n");
    
    return 0;  
}

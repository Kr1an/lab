 #include<stdio.h>
 #include<stdlib.h>
 #include<malloc.h>

typedef struct st          
{ int item;
      struct st *ps;   } STACK;
 typedef STACK* pointer;     
  int isempty(pointer fhead)
  {	int res = 0;
  	if(fhead == NULL)
  	{
  	 res = 1;
  	}
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
  	}
  	
  }
  pointer deletep(pointer poi)
  {
      poi = poi-> ps;
      return poi ;
  }
  	
  	
  
  int main()
  {   
  	
  	 pointer poi1 , poi2 , buff;
  	 poi1 = NULL;
  	 poi2 = NULL;
  	 buff = NULL;
  	 printf(" write 4 elements of steck\n");
  	 for ( int i = 0 ; i < 4 ; i++)
  	 {	 int it;
  	 	scanf( "%d" , &it );
  	 	poi1 = pop( poi1 , it);
  	 }
  	 for(int i = 0 ; i<4 ; i++)
  	 {
  	   buff = pop(buff , take(poi1));
  	   poi1 = deletep(poi1);
  	 }
  	// for(int i =0 ; i < 4 ; i++)
  	/* {
  	 	printf("%d" , take(buff));
  	 	buff = deletep(buff); 
  	 }*/
  	 
  	for(int i = 0 ; i<4 ; i++)
  	 {
  	  poi1 = pop( poi1 , take(buff));  	  
  	  poi2 = pop( poi2 , take(buff));
  	  buff = deletep(buff);
  	 }
  	 for(int i = 0 ; i<4 ; i++)
  	 {
  	 
  	   int k = take(poi1);
  	   poi1 = deletep(poi1);
  	   printf("\n%d" , k);
  	   
  	 }
  	 for(int i = 0 ; i<4 ; i++)
  	 {
  	   int l = take (poi2);
  	   poi2 = deletep(poi2);
  	   printf("\n");
  	   printf( "%d" ,l );
  	 }  	
  	 return 0;  
  }

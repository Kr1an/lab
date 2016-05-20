#include <stdlib.h>
#include <stdio.h>
#include <time.h>

static void mass_del(int** mass);
static int** mass_new();
static void add_ship(int** mass, int length);
static void show_mass(int** mass, int len);

int main(int argc, char *argv[])
{
	int** mass = NULL;
	srand(time(NULL));
	mass = mass_new();
	printf("Ship-fight. 1-ship; 0-empty(random built):\n");
	add_ship(mass, 1);
	add_ship(mass, 1);
	add_ship(mass, 1);
	add_ship(mass, 1);
	add_ship(mass, 2);
	add_ship(mass, 2);
	add_ship(mass, 2);
	add_ship(mass, 3);
	add_ship(mass, 3);
	add_ship(mass, 4);
	show_mass(mass, 10);
	printf("Time to play...\n");
	mass_del(mass);
	return 0;
}
static void mass_del(int** mass)
{
	int i;
	for(i = 0; i < 10; i++)
		free(mass[i]);
	free(mass);
	return;
}

static void show_mass(int** mass, int len)
{
	int i,j;
	for(i = 0; i < len; i++)
	{
		for(j = 0; j < len; j++)
			printf("%d ", mass[i][j]);
		printf("\n");
	}
	return;
}
static void add_ship(int** mass, int len)
{
	int time_begin = time(NULL);
	int st = 0;
	int x = 0;
	int y = 0;
	int dir = 0;
	int i = 0;
	while(time(NULL) - time_begin < 4)
	{
		x = rand() % 10;
		y = rand() % 10;
		st = 0;
		if(mass[y][x] == 1)
			continue;
		dir = rand() % 4;
		switch(dir)
		{
			case 0:
				if(y-len+1 < 0)continue;
				for(i = 0; i < len; i ++)
					if(mass[y-i][x] == 1)
						st = 1;
				for(i = -1; i < len+1; i++)
				{
					if( y-i >= 0 && y-i <= 9 && ( (x >= 1 && mass[y-i][x-1] == 1) || (x<= 8 && mass[y-i][x+1] == 1) || mass[y-i][x] == 1 ))
							st = 1;
				}
				if(st == 1)
					continue;
				for(i = 0; i < len; i ++)
					mass[y-i][x] = 1;
				return;
			case 1:
				if(x-len+1 < 0)continue;
				for(i = 0; i < len; i ++)
					if(mass[y][x-i] == 1)
						st = 1;
				for(i = -1; i < len+1; i++)
				{
					if( x-i >= 0 && x-i <= 9 && ( (y >= 1 && mass[y-1][x-i] == 1) || (y<= 8 && mass[y+1][x-i] == 1) || mass[y][x-i] == 1 ))
							st = 1;
				}
				if(st == 1)
					continue;
				for(i = 0; i < len; i ++)
					mass[y][x-i] = 1;
				return;
			case 2:
				if(x+len > 10)continue;
				x += (len-1);
				for(i = 0; i < len; i ++)
					if(mass[y][x-i] == 1)
						st = 1;
				for(i = -1; i < len+1; i++)
				{
					if( x-i >= 0 && x-i <= 9 && ( (y >= 1 && mass[y-1][x-i] == 1) || (y<= 8 && mass[y+1][x-i] == 1) || mass[y][x-i] == 1 ))
							st = 1;
				}
				if(st == 1)
					continue;
				for(i = 0; i < len; i ++)
					mass[y][x-i] = 1;
				return;
			case 3:
				if(y+len > 10)continue;
				y += (len-1);
				for(i = 0; i < len; i ++)
					if(mass[y-i][x] == 1)
						st = 1;
				for(i = -1; i < len+1; i++)
				{
					if( y-i >= 0 && y-i <= 9 && ( (x >= 1 && mass[y-i][x-1] == 1) || (x<= 8 && mass[y-i][x+1] == 1) || mass[y-i][x] == 1 ))
							st = 1;
				}
				if(st == 1)
					continue;
				for(i = 0; i < len; i ++)
					mass[y-i][x] = 1;
				return;
			default:
				printf("Error..");
				exit(1);
		}
	}
}

static int** mass_new()
{
	int ** mass = NULL;
	const int len = 10;
	int i,j;
	mass = (int**)malloc(sizeof(int*) * len);
	for(i = 0; i < len; i++)
		mass[i] = (int*)malloc(sizeof(int) * len);
	for(i = 0; i < len; i++)
		for(j = 0; j < len; j++)
			mass[i][j] = 0;
	return mass;
}

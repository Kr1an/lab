#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct _Tetrahedron{
	int sightLen;
	unsigned sightLenState:1;
}Tetrahedron;

static const int VAR_DEFAULT = -1;

static void clrscr(void);
static void set_sightLen(Tetrahedron *obj);
static void info();
static void requestNew(Tetrahedron *obj);
static void printMenu(Tetrahedron obj);

static int count_sumedUp(Tetrahedron	obj);
static double count_squere(Tetrahedron	obj);
static double count_volume(Tetrahedron	obj);
static double count_hight(Tetrahedron	obj);
static double count_radInSphere(Tetrahedron	obj);




int main( /*@unused@ */ int argc, /*@unused@ */ char *argv[])
{
	Tetrahedron obj;
	requestNew(&obj);

	do {
		printMenu(obj);
		switch (getchar()) {
		case '1':
			set_sightLen(&obj);
			break;
		case '7':
			info();
			break;
		case '8':
			return 0;
		default:
			break;
		}
		(void)getchar();
	} while (1);
	return 0;
}

/*================FUNCTIONS======================================================*/


static double count_radInSphere(Tetrahedron	obj)
{
	return count_hight(obj) / 3;
}
static double count_hight(Tetrahedron	obj)
{
	return sqrt(2.0/3) * obj.sightLen;
}
static double count_volume(Tetrahedron	obj)
{
	return (double)pow(obj.sightLen, 3)/(6 * sqrt(2));
}
static double count_squere(Tetrahedron	obj)
{
	return sqrt(3) * (double)pow(obj.sightLen, 2);
}
static int count_sumedUp(Tetrahedron obj)
{
	return 6 * obj.sightLen;
}

static void info()
{
	(void)getchar();
	clrscr();
	printf("Info : \nprogram: Tetrahedron \nversion: 1.0 \n \tAutor: Kirill \n \tMail: Kirjushadotcom@gmail.com");
}

static void requestNew(Tetrahedron *obj)
{
	obj->sightLen = VAR_DEFAULT;
	obj->sightLenState = 0;
	return;
}

void clrscr(void)
{
	int i;
	for (i = 0; i < 30; i++)
		printf("\n");
}

static void set_sightLen(Tetrahedron *obj)
{
	
	char temp[20];
	int sightLen = 0;
	(void)getchar();
	clrscr();
	while (1) {
		printf("Set one-line length (-1+Enter)-exit: ");
		(void)scanf("%s", temp);
		sightLen = atoi(temp);
		if (sightLen == VAR_DEFAULT && strlen(temp)< 10){
			return;
		} else if (sightLen > 0 && strlen(temp)<10) {
			obj->sightLen = sightLen;
			obj->sightLenState = 1;
			return;
		} else if(strlen(temp)>10)
			printf("Len Error; Try one more\n");
	}
}
static void printMenu(Tetrahedron obj)
{
	clrscr();
	printf("\t\t\tTetrahedron constructor\n");
	printf("Information about your Tetrahedron model:\n");
	printf("  1: The length of one sight line(mm): %d\n",
	       (obj.sightLenState == 0) ? (-1) : (obj.sightLen));
	printf("Show compleat information about your model: \n");
	printf("  2: Sumed up length of all lines(mm): %d\n", (obj.sightLenState == 0) ? (-1) : (count_sumedUp(obj)));
	printf("  3: Squere of all sights(mm^2): %lf\n", (obj.sightLenState == 0) ? (-1) : (count_squere(obj)));
	printf("  4: Volume of model(mm^3): %lf\n", (obj.sightLenState == 0) ? (-1) : (count_volume(obj)));
	printf("  5: Hight of model(mm): %lf\n", (obj.sightLenState == 0) ? (-1) : (count_hight(obj)));
	printf("  6: Radiuse of in-sphere(mm): %lf\n", (obj.sightLenState == 0) ? (-1) : (count_radInSphere(obj)));
	printf("  7: Info.\n");
	printf("  8: Exit.\n");
	printf("\t\tPress one of 1,7,8+Enter button and...\n");

}

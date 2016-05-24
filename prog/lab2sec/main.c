#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static const int ANGLE_MIN=0;
static const int ANGLE_MAX=360;
static const double EP_MIN=0.000000009;
static const int DIG_MAX=2000000000;
static const float Pi=3.141592;

static double calcIter(int i,float x);
static int fact(int x);

int main(/*@unused@*/int args,/*@unused@*/char* argv[])
{
	float x=45;
	double _sin=0;
	double _sinT=0;
	double e=0;
	int i=0;
	printf("Example of Taler Function:sin(x)=(-1)^(n-1)*x^(2n-1)/(f(2n-1))+...\n");
	printf("Enter an angle(0<=x<360)... ");	
	if(scanf("%f",&x)==0 || x<ANGLE_MIN || x>ANGLE_MAX)
	{
		printf("Input Error...\n");
		return -1;
	}
	printf("Enter epsilon(e>=0.0000009): ");
	if(scanf("%lf",&e)==0 || e<EP_MIN || e>DIG_MAX)
	{
		printf("Input Error...\n");
		return -1;
	}
	_sin=(double)sin(x*Pi/180);
	x=(double)asin(_sin);
	printf("sin(x): %.7f\tTalerFunct: %.7f\n",(float)_sin,(float)_sinT);
	for(i=1;fabs(_sin-_sinT)>=e;i++)
	{
	_sinT+=calcIter(i,x);
		printf("sin(x): %.7f\tTalerFunct: %.7f\n",(float)_sin,(float)_sinT);
	}
	return 0;
}
/*==========================FUNCTION=====================*/
static double calcIter(int i,float x)
{
	double part1=0;
	double part2=0;
	double part3=0;
	double part4=0;
	double part5=0;
	part1=fact(2*i-1);
	part2=pow(x,2*i-1);
	part3=part2/part1;
	part4=pow(-1,i-1);
	part5=part4*part3;
	return part5;	
}
static int fact(int x)
{
	if(x==0) return 1;
	else
		return x*fact(x-1);
}

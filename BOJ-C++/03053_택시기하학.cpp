#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
double R;

int main(){
	scanf("%lf",&R);
	double a = (double)M_PI*R*R,b =R*R+R*R;
	printf("%lf\n",a);
	printf("%lf\n",b);
}
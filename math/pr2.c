#include <stdio.h>
#include <math.h>

double z1 (double);
double z1_opt(double);
double z2 (double);
double deg2rads(double);

int main()
{
	double degrs;
	printf("Input the angle in degrees: ");
	scanf("%lf", &degrs);
	printf("\n");
	printf("z1 = %.5lf\n", z1(deg2rads(degrs)));
	printf("z1_opt = %.5lf\n", z1_opt(deg2rads(degrs)));
	printf("z2 = %.5lf\n", z2(deg2rads(degrs)));
	
	return 0;
}

double deg2rads(double deg)
{
	return deg*(M_PI)/180.0;
}

double z1 (double rads)
{
	double res;
	res = (sin(2*rads) + sin(5*rads) - sin(3*rads))/(cos(rads) + 1 - 2*pow(sin(rads), 2));
	return res;
}

double z1_opt(double rads)
{
	double res;
	res = (sin(2*rads) + sin(5*rads) - sin(3*rads))/(cos(rads) + cos(2*rads));
	return res;
}

double z2 (double rads)
{
	
	return 2*sin(rads);
}
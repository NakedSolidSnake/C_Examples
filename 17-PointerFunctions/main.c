#include <stdio.h>

typedef double (*Operation)(double value1, double value_2);

double sum(double a, double b);
double sub(double a, double b);
double mul(double a, double b);
double div(double a, double b);


int main(int argc, char const *argv[])
{
	double val1 = 100.0, val2 = 20.0;	
	Operation op;

	op = sum;
	printf("Value = %lf\n", op(val1, val2));

	op = sub;
	printf("Value = %lf\n", op(val1, val2));

	op = mul;
	printf("Value = %lf\n", op(val1, val2));

	op = div;
	printf("Value = %lf\n", op(val1, val2));

	return 0;
}

double sum(double a, double b)
{
	return a + b;
}

double sub(double a, double b)
{
	return a - b;
}

double mul(double a, double b)
{
	return a * b;
}

double div(double a, double b)
{
	if(b != 0)
		return a / b;
	return 0;
	return a + b;
}

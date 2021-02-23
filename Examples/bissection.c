/*
 * main.c
 *
 *  Created on: 16 de mai de 2018
 *      Author: solid
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef double(*funct)(double);


typedef struct equationContext{
	double a_resul;
	double b_resul;
	double x_resul;
	double bottom_limit;
	double high_limit;
	double average;
	double precision;
	double error;
}equationContext;


static equationContext ctx = {
		.a_resul = 0.0,
		.b_resul = 0.0,
		.x_resul = 0.0,
		.bottom_limit = 0.5,
		.high_limit = 1.0,
		.average = 0.0,
		.precision = 0.0006,
		.error = 0.0
};

static equationContext ctx2 = {
		.a_resul = 0.0,
		.b_resul = 0.0,
		.x_resul = 0.0,
		.bottom_limit = 0.78,
		.high_limit = 0.8,
		.average = 0.0,
		.precision = 0.001,
		.error = 0.0
};

static equationContext ctx3 = {
		.a_resul = 0.0,
		.b_resul = 0.0,
		.x_resul = 0.0,
		.bottom_limit = 1.325,
		.high_limit = 1.328,
		.average = 0.0,
		.precision = 0.0002,
		.error = 0.0
};


static equationContext ctx4 = {
		.a_resul = 0.0,
		.b_resul = 0.0,
		.x_resul = 0.0,
		.bottom_limit = 1.0,
		.high_limit = 1.5,
		.average = 0.0,
		.precision = 0.05,
		.error = 0.0
};


static int interaction(equationContext *context, int interaction, funct f);
static double equation0(double x);
static double equation1(double x);
static double equation2(double x);
static double equation3(double x);


int main(int argc, char **argv) {
//	interaction(&ctx, 100, equation1);
	printf("------------------------------------------------------------------------------------------\n");
//	interaction(&ctx2, 100, equation0);
//	interaction(&ctx3, 100, equation2);
	interaction(&ctx4, 100, equation3);
}

//-4x⁷ - 3x³ - x² + 3
static double equation0(double x){
	double resul = 0.0;
	resul = (-4.0*(pow(x, 7.0))) + (-3.0*(pow(x, 3.0))) + (-1*(pow(x, 2.0))) + 3.0;
	return resul;
}

static double equation1(double x){
	double resul = 0.0;
	resul = 4.0 * cos(x) - (pow(M_E, x));
	return resul;
}

//ln(x) - 3x² + 5
static double equation2(double x){
	double resul = 0.0;
	resul = log(x) - 3.0*(pow(x, 2)) + 5.0;
	return resul;
}

//+3x⁵ + 6x² -x +1
static double equation3(double x){
	double resul = 0.0;
	resul = -3.0*(pow(x, 5.0)) + 6.0*pow(x, 2.0) - x + 1.0;
	return resul;
}

static int interaction(equationContext *context, int interaction, funct f){
	double value = 0.0;
	for(int i = 1; i <= interaction; i++){
			context->average = (context->bottom_limit + context->high_limit) / 2.0;
			context->a_resul = f(context->bottom_limit);
			context->b_resul = f(context->high_limit);
			context->x_resul = f(context->average);
			context->error = fabs((context->bottom_limit - context->high_limit) / 2.0);

			printf("i    = %d\t", i);
			printf("a    = %.5f\t", context->bottom_limit);
			printf("b    = %.5f\t", context->high_limit);
			printf("x    = %.5f\t", context->average);
			printf("f(a) = %.5f\t", context->a_resul);
			printf("f(b) = %.5f\t", context->b_resul);
			printf("f(x) = %.5f\t", context->x_resul);
			printf("e    = %.5f\n", context->error);

			if(context->x_resul > 0){
				context->bottom_limit += context->error;
				value = context->bottom_limit;
			}
			else{
				context->high_limit -= context->error;
				value = context->high_limit;
			}

			if(context->error < context->precision)
				break;
		}
	printf("value %lf\n", value);
}

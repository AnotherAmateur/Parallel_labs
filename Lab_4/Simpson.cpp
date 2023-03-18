#include <omp.h>
#include "Simpson.h"

double сalculate_Simps(double a, double b, int N, double func(double), bool is_parallel)
{
	double h = (b - a) / (2 * N);
	double S1 = 0;
	double S2 = 0;
	double temp;
	int k;

	
	if (is_parallel == false) {	
		omp_set_dynamic(0);
		omp_set_num_threads(1);
	}
	else
	{
		omp_set_dynamic(1);
	}

#pragma omp parallel for shared(a, h) private(k, temp) reduction(+:S1) reduction(+:S2)
	for (k = 1; k < N; k++) {
		temp = a + (2 * k - 1) * h;
		S1 += func(temp);
		S2 += func(temp + h);
	}
	S1 += func(b - h);

	return h * (func(a) + func(b) + 4 * S1 + 2 * S2) / 3;
}
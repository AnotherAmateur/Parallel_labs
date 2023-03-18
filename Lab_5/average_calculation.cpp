#include <omp.h>
#include "average_calculation.h"
#include <math.h>
#include <map>

double сalculate_for_cone(int N, double func(double, double, double), bool is_parallel)
{
	double h = 1.0 / N;
	double S = 0;
	int i;
	int j;
	int k;
	int temp;

	omp_set_dynamic(0);
	if (is_parallel == false) {

		omp_set_num_threads(1);
	}
	else
	{
		omp_set_num_threads(8);
	}

#pragma omp parallel for shared(h) private(i, j, k, temp) reduction(+:S) schedule(dynamic)
	for (i = 0; i <= N; i++) {
		for (j = -N + i; j <= N - i; j++) {
			temp = sqrt(pow(N - i, 2) - j * j);
			for (k = -temp; k <= temp; k++) {
				S += func(h * i, h * j, h * k);
			}
		}
	}

	return pow(h, 3) * S;
}

double сalculate_for_cube_c(int N, double func(double, double, double), bool is_parallel)
{
	double h = 1.0 / N;
	double S = 0;
	int i;
	int j;
	int k;

	omp_set_dynamic(0);
	if (is_parallel == false) {

		omp_set_num_threads(1);
	}
	else
	{
		omp_set_num_threads(8);
	}

#pragma omp parallel for shared(h) private(i, j, k) reduction(+:S) schedule(dynamic)
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			for (k = 1; k < N; k++) {
				S += func(h * (i + 0.5), h * (j + 0.5), h * (k + 0.5));
			}
		}
	}

	return pow(h, 3) * S;
}

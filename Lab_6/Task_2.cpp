// Исследовать эффективность последовательной и многопоточной версий программы перемножения матриц для
//  размерностей 2048×2048 и 4096×4096 на основе оптимизированных базовых функций линейной алгебры BLAS,
// реализованных в свободно распространяемой библиотеке OpenBLAS

#include <iostream>
#include <chrono>
#include <omp.h>

using namespace std;

#define N 2048

double array_a[N][N];
double array_b[N][N];
double array_c[N][N];

int main()
{
	omp_set_dynamic(0);
	omp_set_num_threads(4);

	int i;
	int j;
	int k;

	cout << "Task 2" << N << endl;
	cout << "N = " << N << endl;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			array_a[i][j] = array_b[i][j] = i * j;
		}
	}

	auto start_time = chrono::steady_clock::now();

#pragma omp parallel for shared(array_a, array_b, array_c) private(i, j, k) schedule(dynamic)
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			array_c[i][j] = 0;
			for (k = 0; k < N; k++)
			{
				array_c[i][j] += array_a[i][k] * array_b[k][j];
			}
		}
	}

	chrono::duration<double> elapsed_seconds_multiple = chrono::steady_clock::now() - start_time;
	cout << "Multiple thread time = " << elapsed_seconds_multiple.count() << " sec" << endl;

	start_time = chrono::steady_clock::now();

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			array_c[i][j] = 0;
			for (k = 0; k < N; k++)
			{
				array_c[i][j] += array_a[i][k] * array_b[k][j];
			}
		}
	}

	chrono::duration<double> elapsed_seconds_single = chrono::steady_clock::now() - start_time;
	cout << "Single thread time = " << elapsed_seconds_single.count() << " sec" << endl << endl;

	cout << "Multiple thread calculation is faster in " << elapsed_seconds_single.count() /
		elapsed_seconds_multiple.count() << " times" << endl;
}

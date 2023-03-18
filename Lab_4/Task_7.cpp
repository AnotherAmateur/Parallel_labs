//// Технология OMP. Лаб. 4 
//// Задание 7. Использовать потоки OpenMP (директиву #pragma omp parallel for) и операцию редукции 
//// при ускорении вычисления интегралов по квадратурной формуле Симпсона. 
//// Проверить точность вычисления интегралов. Проверить возможность раздельной компиляции и сборки.
//
//#define _USE_MATH_DEFINES
//#include <math.h>
//#include <iostream>
//#include <time.h>
//#include "Simpson.h"
//
//using namespace std;
//
//double function(double x)
//{
//	return 1 / (1 + x * x);
//}
//
//int main()
//{
//	const double A = 0;
//	const double B = 100000;
//	const double N = 100000000;
//
//	double time_sec_1 = clock();
//	double integral = сalculate_Simps(A, B, N, function, false);
//	time_sec_1 = (clock() - time_sec_1) / CLOCKS_PER_SEC;
//	
//	cout << "Single thread calculation time = " << time_sec_1 << " sec" << endl;
//	cout << "Calculated value of the integral = " << integral << endl;
//	cout << "True value of the integral = " << M_PI / 2 << endl;
//
//	cout << endl;
//
//	double time_sec_2 = clock();
//	integral = сalculate_Simps(A, B, N, function, true);
//	time_sec_2 = (clock() - time_sec_2) / CLOCKS_PER_SEC;
//
//	cout << "Multiple thread calculation time = " << time_sec_2 << " sec" << endl;
//	cout.precision(8);
//	cout << "Calculated value of the integral = " << integral << endl;
//	cout << "True value of the integral = " << M_PI / 2 << endl;	
//
//	cout << endl;
//
//	cout << "Multiple thread calculation is faster than Single thread calculation in " << time_sec_1 / time_sec_2 << " times" << endl;
//}
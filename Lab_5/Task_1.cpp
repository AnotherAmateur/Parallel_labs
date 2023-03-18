// Технология OMP. Лаб. 5 
// Задание 1. Вариант 6. Определить ускорение (т.е. отношение времени выполнения последовательной 
// версии программы к времени выполнения параллельной версии программы) на Вашей вычислительной
// системе при вычислении среднего значения функции в единичном кубе
//с вершиной в начале координат и ребрами, направленными вдоль координатных осей

#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <time.h>
#include "average_calculation.h"

using namespace std;

double function(double x, double y, double z)
{
	return cos(x) / (1 + pow(exp(1.0), -(x * x + y * y + z * z)));
}

int main()
{
	const int N1 = 300;

	//---------cube-----------
	double time_sec1 = clock();
	double A = сalculate_for_cube_c(N1, function, false);
	time_sec1 = (clock() - time_sec1) / CLOCKS_PER_SEC;

	cout << "Cube. Option C" << endl;
	cout << "N = " << N1 << endl;
	cout << "Single thread calculation time = " << time_sec1 << " sec" << endl;
	cout << "Calculated value = " << A << endl << endl;

	double time_sec2 = clock();
	A = сalculate_for_cube_c(N1, function, true);
	time_sec2 = (clock() - time_sec2) / CLOCKS_PER_SEC;

	cout << "Multiple thread calculation time = " << time_sec2 << " sec" << endl;
	cout << "Calculated value = " << A << endl << endl;
	cout << "Multiple thread calculation for cube is faster than Single thread calculation in " 
		<< time_sec1 / time_sec2 << " times" << endl;


	cout << endl;
	cout << endl;


	//---------cone-----------
	time_sec1 = clock();
	double B = сalculate_for_cone(N1, function, false);
	time_sec1 = (clock() - time_sec1) / CLOCKS_PER_SEC;

	cout << "Cone. Option C" << endl;
	cout << "N = " << N1 << endl;
	cout << "Single thread calculation time = " << time_sec1 << " sec" << endl;
	cout << "Calculated value = " << B << endl << endl;

	time_sec2 = clock();
	B = сalculate_for_cone(N1, function, true);
	time_sec2 = (clock() - time_sec2) / CLOCKS_PER_SEC;

	cout << "Multiple thread calculation time = " << time_sec2 << " sec" << endl;
	cout << "Calculated value = " << B << endl << endl;
	cout << "Multiple thread calculation for cone is faster than Single thread calculation in " 
		<< time_sec1 / time_sec2 << " times" << endl;
}
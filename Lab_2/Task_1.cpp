//// Технология OMP. Лаб. 2  
//// Задание 1. Используя стандартный вызов OpenMP omp_in_parallel(), разработать функцию, которая изменяет 
//// свою функциональность в зависимости от того, из какой области - последовательной или параллельной - она вызывается.
//
//#include <iostream>
//#include <omp.h>
//
//using namespace std;
//
//void function()
//{
//	if (omp_in_parallel()) {
//		cout << ("Parallel Region\n");
//	}
//	else {
//		cout << "Serial Region\n";
//	}
//}
//
//int main()
//{
//	function();
//
//#pragma omp parallel
//	{
//#pragma omp master
//		{
//			function();
//		}
//	}
//}

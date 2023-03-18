//// Технология OMP. Лаб. 2  
//// Задание 5. Используя директиву master OpenMP, добиться изменения в 
//// параллельной области локальной переменной лишь в пределах основного (главного) потока.
//
//#include <iostream>
//#include <omp.h>
//
//using namespace std;
//
//int main()
//{
//	int n;
//
//#pragma omp parallel num_threads(3) private(n)
//	{
//		n = 1;
//
//#pragma omp master
//		{
//			n = 2;
//		}
//		printf("1. n = %d\n", n);
//
//#pragma omp barrier 
//
//#pragma omp master
//		{
//			n = 3;
//		}
//		printf("2. n = %d\n", n);
//	}
//}

//// Технология OMP. Лаб. 3  
//// Задание 1. Проиллюстрировать тот факт, что, при условии, что количество потоков в двух параллельных областях совпадает, 
//// т.е.число потоков не изменяется динамически, одноименные некоторым глобальным переменным локальные переменные, 
//// созданные в параллельной области с использованием опции threadprivate, сохраняют свое значение
//// при переходе через последовательную область и при входе в следующую последовательную область.
//
//
//#include <iostream>
//#include <omp.h>
//
//using namespace std;
//
//int n;
//#pragma omp threadprivate(n)
//int main()
//{
//	int num;
//	n = 1;
//	omp_set_dynamic(0);
//	omp_set_num_threads(4);
//
//#pragma omp parallel private (num)
//	{
//		num = omp_get_thread_num();
//		printf("Thread %d, in n: %d\n", num, n);
//		n = omp_get_thread_num();
//		printf("Thread %d, out n: %d\n", num, n);
//	}
//
//	cout << endl << "Middle n: " << n << endl << endl;
//
//#pragma omp parallel private (num)
//	{
//		num = omp_get_thread_num();		
//		printf("Thread %d, last n: %d\n", num, n);
//	}
//}

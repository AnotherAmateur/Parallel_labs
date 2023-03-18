//// Технология OMP. Лаб. 3  
//// Задание 7. Проиллюстрировать возможность использование опции lastprivate для 
//// автоматического присваивания значения локальной переменной в последней секции
//// всем другим локальным переменным и одноименной глобальной переменной.
//
//#include <iostream>
//#include <omp.h>
//#include <windows.h>
//
//using namespace std;
//
//int main()
//{
//	int n = 10;
//
//#pragma omp parallel num_threads(3)
//	{
//#pragma omp sections lastprivate(n)
//		{
//#pragma omp section
//			{
//				n = 1;
//			}
//#pragma omp section
//			{
//				n = 2;
//			}
//#pragma omp section
//			{
//				n = 3;
//				Sleep(1);
//			}
//		}
//
//		printf("Parallel region, thread %d, n: %d\n", omp_get_thread_num(), n);
//	}
//
//	printf("Out of parallel, n: %d\n", n);
//}
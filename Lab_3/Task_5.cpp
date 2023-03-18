//// Технология OMP. Лаб. 3  
//// Задание 5. При помощи опции schedule(static, размер_блока) директивы omp for проиллюстрировать 
//// блочно-циклическое распределение итераций цикла между потоками в параллельной области. 
//// Для имитации вычислений использовать функцию Sleep(unsigned long) (OC Windows).
//
//#include <windows.h>
//#include <iostream>
//#include <omp.h>
//
//using namespace std;
//
//void sleep(float sec)
//{
//	Sleep(1000 * sec);
//}
//
//int main(int argc, char* argv[])
//{
//	const int N = 36;
//	int i;
//
//#pragma omp parallel num_threads(4) private(i)
//	{
//#pragma omp for schedule(static, 5)
//		for (i = 0; i < N; i++)
//		{
//			printf("Thread %d executed iteration %d\n", omp_get_thread_num(), i);
//			sleep(0.5);
//		}
//	}
//}
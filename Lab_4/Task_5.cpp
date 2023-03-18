//// Технология OMP. Лаб. 4 
//// Задание 5. При помощи блокировки (обеспечивается стандартными функциями OpenMP omp_init_lock, 
//// omp_set_lock, omp_unset_lock), добиться того, чтобы сообщения, печатаемые в разных потоках 
//// в параллельной секции, не перемежались друг с другом. Для имитации вычислений использовать 
//// функцию sleep(Sleep в ОС Windows).
//
//#include <iostream>
//#include <omp.h>
//#include <windows.h>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	omp_lock_t lock;
//	omp_init_lock(&lock);
//
//#pragma omp parallel num_threads(4) private (n)
//	{
//		n = omp_get_thread_num();
//		omp_set_lock(&lock);
//		printf("Section`s beginning, thread %d\n", n);
//		Sleep(500);
//		printf("Section`s end, thread %d\n", n);
//		omp_unset_lock(&lock);
//	}
// 
// omp_destroy_lock(&lock);
//}
//// Технология OMP. Лаб. 4 
//// Задание 1. Используя директиву барьерной синхронизации omp barrier, написать параллельную программу, 
//// в которой несколько сообщений с младшими номерами могут выводиться в произвольном порядке, 
//// но будут гарантированно замыкаться сообщениями со старшим номером.
//
//#include <iostream>
//#include <omp.h>
//
//using namespace std;
//
//int main()
//{
//#pragma omp parallel num_threads(2)
//	{
//		printf("Random message 1\n");
//		printf("Random message 2\n");
//		printf("Random message 3\n");
//		printf("Random message 4\n");
//
//#pragma omp barrier		
//		printf("Message 5\n");
//	}
//}
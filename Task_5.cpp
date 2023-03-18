//// Технология OMP. Лаб. 1  
//// Задание 5. Разработать программу, в которой при входе в параллельную область каждый из потоков OpenMP
//// должен распечатать сообщение. Сравненить возможности опции num_threads в директиве #pragma omp parallel 
//// и вызова функции omp_set_num_threads.
//
//
//#include <iostream>
//#include <omp.h>
//
//using namespace std;
//
//int main()
//{
//	omp_set_dynamic(0);	
//	omp_set_num_threads(4);
//	
//#pragma omp parallel num_threads(2)
//	{
//		cout << "Parallel region 1\n";
//	}					  
//#pragma omp parallel	  
//	{					  
//		cout << "Parallel region 2\n";
//	}
//}

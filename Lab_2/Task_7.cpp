//// Технология OMP. Лаб. 2  
//// Задание 7. При помощи опции shared создать массив, общий для всех потоков в параллельной области, 
//// и в элемент массива, номер которого совпадает с номером потока, записать номер потока.
//
//#include <iostream>
//#include <omp.h>
//
//using namespace std;
//
//int main()
//{
//	const int N = 8;
//	int i;
//	int arr[N];
//
//	cout << "Initial array: ";
//	for (i = 0; i < N; i++) {
//		arr[i] = 0;
//		cout << arr[i] << " ";
//	}
//
//#pragma omp parallel num_threads(N) shared(arr)
//	{
//		int index = omp_get_thread_num();
//		arr[index] = index;
//	}
//
//	cout << endl << "Final array: ";
//	for (i = 0; i < N; i++) {
//		cout << arr[i] << " ";
//	}
//
//	cout << endl;
//}

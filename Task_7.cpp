// Технология OMP. Лаб. 1  
// Задание 7. Распечатать значение умолчанию переменной OMP_DYNAMIC при помощи функции omp_get_dynamic().
// Затем при помощи функции omp_set_dynamic(int) разрешить динамическую установку числа потоков в параллельной области 
// и снова распечатать значение переменной OMP_DYNAMIC. Cоздать параллельную область. 
// При помощи директивы master обеспечить печать фактического числа потоков OpenMP лишь в главном потоке.

#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
	cout << "OMP_DYNAMIC value = " << omp_get_dynamic() << endl;
	omp_set_dynamic(1);
	cout << "OMP_DYNAMIC value = " << omp_get_dynamic() << endl;

#pragma omp parallel num_threads(128)
	{
#pragma omp master
		{
			cout << "Parallel region, " << omp_get_num_threads() << " threads\n";
		}
	}
}

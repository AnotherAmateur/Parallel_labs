//// Задание 5. Написать программу, в которой происходит обмен 
//// информацией между процессами с соседними номерами в соответствии 
//// с топологией кольца. Использовать неблокирующие операции
// // отправки и получения сообщейний
// 
//#include "mpi.h"
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	double a = 0;
//	double b = 0;
//	double c = 0;
//	int comm_size;
//	int comm_rank;
//
//	MPI_Init(NULL, NULL);
//	MPI_Comm_size(MPI_COMM_WORLD, &comm_size);
//	MPI_Comm_rank(MPI_COMM_WORLD, &comm_rank);
//
//	MPI_Request request[4];
//	MPI_Status status[4];
//
//	int next_proc = (comm_rank + 1) % comm_size;
//	int prev_proc = comm_rank != 0 ? comm_rank - 1 : comm_size - 1;
//
//	a = comm_rank;
//
//	MPI_Isend(&a, 1, MPI_DOUBLE, next_proc, 5, MPI_COMM_WORLD, &request[0]);
//	MPI_Irecv(&b, 1, MPI_DOUBLE, prev_proc, 5, MPI_COMM_WORLD, &request[1]);
//	MPI_Isend(&a, 1, MPI_DOUBLE, prev_proc, 5, MPI_COMM_WORLD, &request[2]);
//	MPI_Irecv(&c, 1, MPI_DOUBLE, next_proc, 5, MPI_COMM_WORLD, &request[3]);
//
//	MPI_Waitall(4, request, status);
//
//	cout << "Process " << comm_rank << ": a=" << a << " b=" << b << " c=" << c << endl;	
//
//	MPI_Finalize();
//}

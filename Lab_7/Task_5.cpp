//// Задание 5. Написать программу, в которой происходит обмен 
//// информацией между процессами с соседними номерами в соответствии 
//// с топологией кольца. Использовать отложенные запросы на операции 
//// двунаправленного обмена между соседними процессами.
//
//#include "mpi.h"
//#include <iostream>
//#include <iomanip>
//
//using namespace std;
//
//int main()
//{
//	double a = 0;
//	double b = 0;
//	double c = 0;
//	int comm_size;
//	int proc_rank;
//
//	MPI_Init(NULL, NULL);
//	MPI_Comm_size(MPI_COMM_WORLD, &comm_size);
//	MPI_Comm_rank(MPI_COMM_WORLD, &proc_rank);
//
//	MPI_Request request[4];
//	MPI_Status status[4];
//
//	int next_proc = (proc_rank + 1) % comm_size;
//	int prev_proc = proc_rank != 0 ? proc_rank - 1 : comm_size - 1;
//
//	a = proc_rank;
//
//	MPI_Send_init(&a, 1, MPI_DOUBLE, next_proc, 5, MPI_COMM_WORLD, &request[0]);
//	MPI_Recv_init(&b, 1, MPI_DOUBLE, prev_proc, 5, MPI_COMM_WORLD, &request[1]);
//	MPI_Send_init(&a, 1, MPI_DOUBLE, prev_proc, 5, MPI_COMM_WORLD, &request[2]);
//	MPI_Recv_init(&c, 1, MPI_DOUBLE, next_proc, 5, MPI_COMM_WORLD, &request[3]);
//
//	MPI_Startall(4, request);
//	MPI_Waitall(4, request, status);
//
//	cout << "1) Process " << proc_rank << ": a=" << a << " b=" << b << " c=" << c << endl;
//
//	a += 0.22;
//
//	MPI_Startall(4, request);
//	MPI_Waitall(4, request, status);
//
//	if (proc_rank == 0) {
//		cout << endl;
//	}
//	
//	cout << "2) Process " << proc_rank << ": a=" << a << " b=" << b << " c=" << c << endl;
//
//	MPI_Request_free(request);
//
//	MPI_Finalize();
//}

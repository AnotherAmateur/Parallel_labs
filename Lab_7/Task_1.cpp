//// Задание 1. Написать программу, которая определяет латентность
//// (т.е.время на передачу сообщения нулевой длины) 
//// и максимально достижимую пропускную способность коммуникационной среды, 
//// а также длину сообщения, на которой она достигается.
//
//#include "mpi.h"
//#include <iostream>
//#include <iomanip>
//
//using namespace std;
//
//int const MAX_MSG_SIZE = 1e7;
//int const ITERS_COUNT = 10;
//double const BYTES_IN_MB = pow(2, 20);
//double a[MAX_MSG_SIZE * 8];
//
//int main()
//{
//	int msg_size = 0;
//	int best_length = 0;
//	int rank;
//	double max_bandwidth = 0;
//
//	MPI_Init(NULL, NULL);
//	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//
//	while (msg_size <= MAX_MSG_SIZE) {
//
//		double time_start = MPI_Wtime();
//
//		for (int i = 0; i < ITERS_COUNT; i++) {
//			if (rank == 0) {
//				MPI_Status status;
//				MPI_Send(a, msg_size, MPI_DOUBLE, 1, 5, MPI_COMM_WORLD);
//				MPI_Recv(a, msg_size, MPI_DOUBLE, 1, 5, MPI_COMM_WORLD, &status);
//			}
//			if (rank == 1) {
//				MPI_Status status;
//				MPI_Recv(a, msg_size, MPI_DOUBLE, 0, 5, MPI_COMM_WORLD, &status);
//				MPI_Send(a, msg_size, MPI_DOUBLE, 0, 5, MPI_COMM_WORLD);
//			}
//		}
//
//		double avrg_time = (MPI_Wtime() - time_start) / (2.0 * ITERS_COUNT);
//		double bandwidth = (8.0 * msg_size) / (avrg_time * BYTES_IN_MB);
//
//		if (max_bandwidth < bandwidth) {
//			max_bandwidth = bandwidth;
//			best_length = 8 * msg_size;
//		}
//
//		if (rank == 0) {
//			if (msg_size == 0) {
//				cout << "Latency: " << avrg_time << " s" << endl;
//			}
//			else {
//				cout << 8 * msg_size << " bytes," << " bandwidth: " << bandwidth << " MB/s" << endl;
//			}
//		}
//
//		msg_size = (msg_size == 0) ? ++msg_size : msg_size << 1;
//	}
//
//	if (rank == 0) {
//		cout << "Max bandwidth: " << max_bandwidth
//			<< " MB/s, message length: " << best_length << " bytes" << endl;
//	}
//
//	MPI_Finalize();
//}

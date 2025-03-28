#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

std::once_flag flag;

void print_result(int cores, const std::vector< std::chrono::duration<double>>& results) {
	std::cout << "Количество аппаратных ядер: " << cores << std::endl;
	std::cout << "\n\t\t1 000\t\t10 000\t\t100 000\t\t1 000 000" << std::endl;
	int thread_count = 1;
	for (int i = 0; i < 5; ++i) {
		std::cout << thread_count << " потоков\t" << results[i * 4].count() << '\t' << results[1 + (i * 4)].count() << '\t' << results[2 + (i * 4)].count() << '\t' << results[3 + (i * 4)].count() << std::endl;
		thread_count *= 2;
	}
}

void get_cores(int& cores) {
	cores = std::thread::hardware_concurrency();
}

void sum_vectors_part(const std::vector<int>& vecA, const std::vector<int>& vecB, int beg, int end, int& cores) {
	std::call_once(flag, get_cores, std::ref(cores));
	int res;
	for (int i = beg; i < end; ++i) {
		res = vecA[i] + vecB[i];
	}
}

std::chrono::duration<double> sum_vectors(const std::vector<int>& vecA, const std::vector<int>& vecB, int threads_count, int& cores) {
	std::vector<std::thread> threads;
	auto start = std::chrono::steady_clock::now();
	for (int i = 0; i < threads_count; ++i) {
		threads.push_back(std::thread{ sum_vectors_part,std::ref(vecA),std::ref(vecB),i * (vecA.size() / threads_count), (vecA.size() - 1) - (threads_count - 1 - i) * (vecA.size() / threads_count),std::ref(cores) });
	}
	for (int i = 0; i < threads_count; ++i) {
		threads[i].join();
	}
	auto end = std::chrono::steady_clock::now();
	return end - start;
}

int main() {
	setlocale(LC_ALL, "Rus");
	std::vector<int> vecT1(1000, 1);
	std::vector<int> vecT2(1000, 1);
	std::vector<int> vecTT1(10'000, 1);
	std::vector<int> vecTT2(10'000, 1);
	std::vector<int> vecHT1(100'000, 1);
	std::vector<int> vecHT2(100'000, 1);
	std::vector<int> vecM1(10'000'000, 1);
	std::vector<int> vecM2(10'000'000, 1);
	std::vector< std::chrono::duration<double>> durationResults;
	int cores;
	durationResults.push_back(sum_vectors(vecT1,vecT2,1,cores));
	durationResults.push_back(sum_vectors(vecTT1, vecTT2, 1, cores));
	durationResults.push_back(sum_vectors(vecHT1, vecHT2, 1, cores));
	durationResults.push_back(sum_vectors(vecM1, vecM2, 1, cores));

	durationResults.push_back(sum_vectors(vecT1,vecT2,2,cores));
	durationResults.push_back(sum_vectors(vecTT1, vecTT2, 2, cores));
	durationResults.push_back(sum_vectors(vecHT1, vecHT2, 2, cores));
	durationResults.push_back(sum_vectors(vecM1, vecM2, 2, cores));

	durationResults.push_back(sum_vectors(vecT1,vecT2,4,cores));
	durationResults.push_back(sum_vectors(vecTT1, vecTT2, 4, cores));
	durationResults.push_back(sum_vectors(vecHT1, vecHT2, 4, cores));
	durationResults.push_back(sum_vectors(vecM1, vecM2, 4, cores));

	durationResults.push_back(sum_vectors(vecT1,vecT2,8,cores));
	durationResults.push_back(sum_vectors(vecTT1, vecTT2, 8, cores));
	durationResults.push_back(sum_vectors(vecHT1, vecHT2, 8, cores));
	durationResults.push_back(sum_vectors(vecM1, vecM2, 8, cores));

	durationResults.push_back(sum_vectors(vecT1, vecT2, 16, cores));
	durationResults.push_back(sum_vectors(vecTT1,vecTT2,16,cores));
	durationResults.push_back(sum_vectors(vecHT1,vecHT2,16,cores));
	durationResults.push_back(sum_vectors(vecM1,vecM2,16,cores));

	print_result(cores, durationResults);
}
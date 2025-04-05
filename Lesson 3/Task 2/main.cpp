#include <iostream>
#include <algorithm>
#include <future>
#include <vector>


template<typename Iter, typename Func>
void parallel_for_each(Iter first, Iter last, Func func)
{
	unsigned long const length = std::distance(first, last);
	unsigned long const max_chunk_size = 25;
	if (length <= max_chunk_size)
	{
		std::for_each(first, last, func);
	}
	else
	{
		Iter mid_point = first;
		std::advance(mid_point, length / 2);
		std::future<void> first_half_result = std::async(parallel_for_each<Iter, Func>, first, mid_point, func);
		std::future<void> second_half_result = std::async(parallel_for_each<Iter, Func>, mid_point, last, func);
		first_half_result.wait();
		second_half_result.wait();
	}
}

int main()
{
	std::vector<int> V;
	for (int i = 1; i <= 100; ++i) {
		V.push_back(i);
	}
	parallel_for_each(V.begin(), V.end(), [](int value) {std::cout << value * value << ' '; });
	return 0;
}
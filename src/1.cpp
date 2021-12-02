#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main()
{
	const auto depths = []() {
		std::vector<int> depths;
		for (std::string line; std::getline(std::cin, line);) {
			depths.push_back(std::stoi(line));
		}
		return depths;
	}();

	const auto window_sums = [&depths]() {
		constexpr size_t sliding_window_size = 3;
		std::vector<int> window_sums;
		window_sums.reserve(depths.size() - sliding_window_size + 1);
		for (auto it = depths.begin(); it <= depths.end() - sliding_window_size; it++) {
			window_sums.push_back(std::reduce(it, std::next(it, sliding_window_size)));
		}
		return window_sums;
	}();

	auto count_increases = [](auto &values)
	{
		std::vector<bool> increases(values.size() - 1);
		std::adjacent_difference(values.begin(), values.end(), increases.begin(), [](auto a, auto b) { return a > b; } );
		return std::count(increases.begin(), increases.end(), true);
	};

	std::cout << count_increases(depths) << '\n';
	std::cout << count_increases(window_sums) << '\n';
}

#include <iostream>
#include <string>
#include <map>

int main() {
	std::string str{ "Hello world!!" };
	std::map<char,int> char_map;
	for (auto symbol : str) {
		char_map[symbol] += 1;
	}
	std::multimap<int, char, std::greater<int>> frequency_map;
	for (const auto& elem : char_map) {
		std::pair<int, char> new_elem{ elem.second,elem.first };
		frequency_map.insert(new_elem);
	}
	std::cout << "[IN]: " << str << "\n[OUT]: " << std::endl;
	for (const auto& elem : frequency_map)
		std::cout << elem.second << ": " << elem.first << std::endl;
}
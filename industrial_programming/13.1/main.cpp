#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

int main() {
	std::fstream input_file("input.txt", std::ios::in);
	std::string input_text;
	std::getline(input_file, input_text);
	input_text.erase(std::remove_if(input_text.begin(), input_text.end(), [](char symbol) {
		size_t position = std::string("usagrment").find(symbol);
		return position == std::string::npos ? false : true;
	}), input_text.end());
	std::fstream output_file("output.txt", std::ios::out);
	output_file << input_text;
	input_file.close();
	output_file.close();
}

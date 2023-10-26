#include <iostream>
#include <vector>
#include <cstdint>
#include <stdexcept>

template <class number_type>
class stack {
public:
	explicit stack() noexcept : stack_mass(nullptr), stack_size(0) {}

	void push(number_type _value) noexcept {
		number_type* new_stack_mass = new number_type[stack_size + 1];
		for (auto i = 0ull; i < stack_size; i++) new_stack_mass[i] = stack_mass[i];
		if (stack_size) delete[] stack_mass;
		stack_size += 1;
		new_stack_mass[stack_size - 1] = _value;
		stack_mass = new_stack_mass;
	}

	number_type pop() {
		if (!stack_size) throw std::runtime_error("Stack empty");
		number_type value = stack_mass[stack_size - 1];
		number_type* new_stack_mass = new number_type[stack_size - 1];
		for (auto i = 0ull; i < stack_size - 1; i++) new_stack_mass[i] = stack_mass[i];
		delete[] stack_mass;
		stack_size -= 1;
		stack_mass = new_stack_mass;
		return value;
	}

	number_type back() const noexcept {
		return stack_mass[stack_size - 1];
	}

	void clear() noexcept {
		delete[] stack_mass;
		stack_mass = nullptr;
		stack_size = 0;
	}

	size_t size() const noexcept {
		return stack_size;
	}

	~stack() noexcept {
		if (stack_size) delete[] stack_mass;
	}

private:
	number_type* stack_mass;
	size_t stack_size;
};

int main() {
	stack<uint64_t> stack_data;
	while (1) {
		std::string action;
		std::cin >> action;
		if (action == "push") {
			uint64_t value = 0;
			std::cin >> value;
			stack_data.push(value);
			std::cout << "ok" << std::endl;
		} else if (action == "pop") {
			std::cout << stack_data.pop() << std::endl;
		} else if (action == "back") {
			std::cout << stack_data.back() << std::endl;
		} else if (action == "size") {
			std::cout << stack_data.size() << std::endl;
		} else if (action == "clear") {
			stack_data.clear();
			std::cout << "ok" << std::endl;
		} else if (action == "exit") {
			std::cout << "bye" << std::endl;
			break;
		}
	}
}

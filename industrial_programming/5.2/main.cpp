#include <iostream>
#include <vector>
#include <algorithm>

template <class _StringType, class _GradeType>
struct student_grade {
	using grade_type = _GradeType;
	using string_type = _StringType;
	string_type name, surname;
	grade_type middle_grade;
};

template <class _StringType, class _GradeType>
std::ostream& operator << (std::ostream& _stream, const student_grade<_StringType, _GradeType>& _grade) {
	_stream << _grade.name << ' ' << _grade.surname;
	return _stream;
}

int main() {
	size_t count = 0;
	std::cin >> count;
	std::vector<student_grade<std::string, double>> student_info = {};
	for (auto i = 0ull; i < count; i++) {
		std::string name, surname;
		double first = 0.0, second = 0.0, third = 0.0;
		std::cin >> name >> surname >> first >> second >> third;
		student_info.push_back({ name, surname, (first + second + third) / 3.0});
	}
	std::sort(student_info.begin(), student_info.end(), [](const student_grade<std::string, double>& _leftGrade, const student_grade<std::string, double>& _rightGrade) {
		return _leftGrade.middle_grade > _rightGrade.middle_grade;
	});
	for (auto& i : student_info) {
		std::cout << i << std::endl;
	}
}

#include <iostream>
#include <iomanip>

template <class _GradeType>
struct student_grade {
	using grade_type = _GradeType;
	using this_grade = student_grade<grade_type>;
	grade_type first = 0.0, second = 0.0, third = 0.0;
	constexpr auto operator+=(const this_grade& _newGrade) {
		first += _newGrade.first, second += _newGrade.second, third += _newGrade.third;
		return *this;
	}
	template <class _DevinderNumber>
	constexpr auto operator/(const _DevinderNumber& _devinder) {
		first /= _devinder, second /= _devinder, third /= _devinder;
		return *this;
	}
};

template <class _Type>
auto operator<<(std::ostream& _stream, const student_grade<_Type>& _value) -> std::ostream& {
	_stream << _value.first << ' ' << _value.second << ' ' << _value.third;
	return _stream;
}

auto main() -> int {
	size_t count = 0;
	std::cin >> count;
	student_grade<double> result_grade = {};
	for (size_t i = 0; i < count; i++) {
		std::string name, surname;
		double first = 0.0, second = 0.0, third = 0.0;
		std::cin >> name >> surname >> first >> second >> third;
		result_grade += { first, second, third };
	}
	std::cout << std::fixed << std::setprecision(1) << result_grade / static_cast<double>(count) << std::endl;
}

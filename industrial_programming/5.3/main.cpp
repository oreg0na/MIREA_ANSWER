#include <iostream>
#include <vector>
#include <algorithm>
#include <concepts>

template <typename _CheckType, typename... _Requires>
concept IsAny = (std::same_as<_CheckType, _Requires> || ...);

template <class _StringType>
concept IsString = IsAny<_StringType, char*, const char*, wchar_t, const wchar_t*, std::string, std::wstring>;

template <IsString _StringType>
struct student {
	using string_type = _StringType;
	string_type surname, name, class_word, date_born;
};

template <IsString _StudentStringType>
std::ostream& operator << (std::ostream & _stream, const student<_StudentStringType>& _student) {
	_stream << _student.class_word << ' ' << _student.surname << ' ' << _student.name << ' ' << _student.date_born;
	return _stream;
}

int main() {
	size_t count = 0;
	std::cin >> count;
	std::vector<student<std::string>> students_info = {};
	for (auto i = 0ull; i < count; i++) {
		std::string surname, name, class_word, date_born;
		std::cin >> surname >> name >> class_word >> date_born;
		students_info.push_back({ surname, name, class_word, date_born });
	}
	std::sort(students_info.begin(), students_info.end(), [](student<std::string> _rightStudent, student<std::string> _leftStudent) {
		if (_rightStudent.class_word == _leftStudent.class_word) return _rightStudent.surname < _leftStudent.surname;
		return _rightStudent.class_word < _leftStudent.class_word;
	});
	for (auto& i : students_info) {
		std::cout << i << std::endl;
	}
}

# 13.2 НЕ КРИЧИ НА МЕНЯ!

``` cpp
#include <iostream>
#include <string>

wchar_t to_lower(wchar_t _symbol) {
	if (_symbol >= L'А' && _symbol <= L'Я') return _symbol + (L'а' - L'А');
	else if (_symbol >= L'A' && _symbol <= L'Z') return _symbol + (L'a' - L'A');
	else return _symbol;
}

int main() {
	std::wcin.imbue(std::locale("ru_RU.cp1251"));
	std::wcout.imbue(std::locale("ru_RU.cp1251"));
	std::wstring text;
	std::getline(std::wcin, text);
	for (auto& symbol : text) {
		symbol = to_lower(symbol);
	}
	std::wcout << text;
}
```

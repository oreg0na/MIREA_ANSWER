#include <iostream>
#include <cctype>
#include <string>

int main() {
    std::string text;
    std::getline(std::cin, text);

    for (char & c : text)
        c = std::tolower(c);

    std::cout << text << std::endl;

    return 0;
}


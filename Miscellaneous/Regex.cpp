#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string text = "John Doe, 30 years old, email: john@example.com";
    std::regex pattern("(\\w+)\\s(\\w+),\\s(\\d+).*email:\\s([\\w@.]+)");
    
    std::smatch matches;//stores first match of each regex portion
    if (std::regex_search(text, matches, pattern)) {
        std::cout << "Entire match: " << matches[0] << std::endl;
        std::cout << "First name: " << matches[1] << std::endl;
        std::cout << "Last name: " << matches[2] << std::endl;
        std::cout << "Age: " << matches[3] << std::endl;
        std::cout << "Email: " << matches[4] << std::endl;
        
        std::cout << "Number of captures: " << matches.size() << std::endl;
        std::cout << "Position of age: " << matches.position(3) << std::endl;
        std::cout << "Length of email: " << matches.length(4) << std::endl;
        
        std::cout << "Prefix: " << matches.prefix() << std::endl;
        std::cout << "Suffix: " << matches.suffix() << std::endl;
    }

    return 0;
}
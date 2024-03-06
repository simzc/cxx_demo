#include <map>
#include <unordered_map>
#include <iostream>

int main(int argc, const char** argv) {
    std::unordered_map<std::string, double> unorder_map;

    unorder_map.insert(std::make_pair<std::string, double>("abc", 1));

    if (unorder_map.find("abc") == unorder_map.end()) {
        unorder_map.insert(std::make_pair<std::string, double>("abc", 2));
    } else {
        std::cout << "Registed in unorder_map." << std::endl;
    }

    return 0;
}
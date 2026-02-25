#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>

using json = nlohmann::json;
using ordered_json = nlohmann::ordered_json;

int main() {
    json j = {{"a", 1}};
    std::cout << j.dump(4) << "\n";
    std::ofstream s("../data.json");
    s << j.dump(4) << "\n";
}
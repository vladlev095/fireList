// #include <iostream>
// #include <nlohmann/json.hpp>
// #include <fstream>
#include "Task.h"
#include "TaskManager.h"

using json = nlohmann::json;
using ordered_json = nlohmann::ordered_json;

int main() {
    ordered_json j = json::array();
    ordered_json obj = json::object();
    time_t t = 2000000000;
    std::cout << "woohoo!\n";
    TaskManager tm;
    // obj["task"] = "do homework";
    // obj["done"] = false;
    // obj["time limit"] = asctime(gmtime(&t));
    // j.push_back(obj);
    // std::ofstream s("../data.json");
    // s << j.dump(4) << "\n";
}
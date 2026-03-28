#pragma once

#include "Task.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <nlohmann/json.hpp>

using ordered_json = nlohmann::ordered_json;

class TaskManager {
public:
    TaskManager();

    void readFile();
    void addTask(std::string name, int minutesForExec);
    void editTask(int id);
    void removeTask(int id);

private:
    int m_nextID = 0;
    std::vector<Task> m_Tasks;
    ordered_json m_J;
};
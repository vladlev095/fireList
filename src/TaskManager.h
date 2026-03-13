#pragma once

#include "Task.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using ordered_json = nlohmann::ordered_json;

class TaskManager {
public:
    TaskManager();

    void addTask();

private:
    std::vector<Task> m_Tasks;
};
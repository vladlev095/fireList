#pragma once

#include "Task.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <nlohmann/json.hpp>

using ordered_json = nlohmann::ordered_json;

class TaskManager { // make this class static with static funcs add remove and edit 
public:
    TaskManager();

    void setTasks(ordered_json& j);
    void printTasks();
    void addTask(std::string name, int minutesForExec);
    void editTask(int id);
    void removeTask(int id);

private:
    int m_nextID = 0;
    std::vector<Task> m_Tasks;
};
#include "TaskManager.h"

TaskManager::TaskManager() { 
}

void TaskManager::setTasks(ordered_json& j) {
    m_Tasks = j;
}

void TaskManager::printTasks() {
    for(const auto &t : m_Tasks) {
        std::cout << t << "\n";
    }
}
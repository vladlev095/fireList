#include "TaskManager.h"

TaskManager::TaskManager() { 
    readFile();
    m_Tasks = m_J;
    std::cout << m_Tasks.size() << "\n";
}

void TaskManager::printTasks() {
    for(const auto &t : m_Tasks) {
        std::cout << t << "\n";
    }
}

void TaskManager::readFile() { //move to application
    std::ifstream file("../data.json");
    std::stringstream ss;
    ss << file.rdbuf();
    std::string fileContent = ss.str();
    m_J = ordered_json::parse(ss);
}
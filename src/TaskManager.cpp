#include "TaskManager.h"

TaskManager::TaskManager() {
    readFile();
    m_Tasks = m_J;
    std::cout << m_Tasks.size() << "\n";
}

void TaskManager::readFile() {
    std::ifstream file("../data.json");
    std::stringstream ss;
    ss << file.rdbuf();
    std::string fileContent = ss.str();
    m_J = ordered_json::parse(ss);
}
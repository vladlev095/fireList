#include "TaskManager.h"

TaskManager::TaskManager() {
    createTasksList(); //creates a json obj from file and moves it into a vector of Task objects
}

TaskManager::~TaskManager() {
}

void TaskManager::createTasksList() {
    std::ifstream file("../data.json");
    std::stringstream ss;
    ss << file.rdbuf();
    std::string fileContent = ss.str();
    ordered_json m_J = ordered_json::parse(ss);
    m_Tasks = m_J;
    int id = m_Tasks.back().getID();
    m_nextID = id;
}

void TaskManager::addTask(std::string name, int minutesForExec) {
    Task task(m_nextID, name, minutesForExec);
    m_Tasks.push_back(task);
}

void TaskManager::editTask(int id) {
    std::string name;
    int minutesForExec;
    bool isFound = false;
    for(auto& t : m_Tasks) {
        if(t.getID() == id) {
            std::cout << "set name: \n";
            std::getline(std::cin, name);
            t.setName(name);
            std::cout << "set timer (minutes): \n"; //if -1, 0 or a char?
            std::getline(std::cin, name);
            minutesForExec = std::stoi(name);
            t.setDeadline(minutesForExec);
            isFound = true;
        }
    }
    if(!isFound) { std::cout << "id not found!\n"; }
}

void TaskManager::printTasks() {
    for(const auto &t : m_Tasks) {
        std::cout << t << "\n";
    }
}
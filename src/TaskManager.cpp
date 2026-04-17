#include "TaskManager.h"

TaskManager::TaskManager() {
    createTasksList(); //creates a json obj from file and moves it into a vector of Task objects
}

TaskManager::~TaskManager() { //writeToFile()? save()?
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
    std::string input;
    int minutesForExec;
    bool isFound = false;
    for(auto& t : m_Tasks) {
        if(t.getID() == id) {
            std::cout << "set name: \n";
            std::getline(std::cin, input);
            t.setName(input);
            std::cout << "set timer (minutes): \n"; //if -1, 0 or a char?
            std::getline(std::cin, input); // library for input
            minutesForExec = std::stoi(input);
            t.setDeadline(minutesForExec);
            isFound = true;
        }
    }
    if(!isFound) { std::cout << "id not found!\n"; }
}

void TaskManager::removeTask(int id) {
    for(auto it = m_Tasks.begin(); it != m_Tasks.end(); ) {
        if(it->getID() == id) {
            std::cout << "task \"" << it->getName() << "\" (id: " << it->getID() << ") removed\n";
            it = m_Tasks.erase(it); //rename other tasks ids
        } else {
            ++it;
        }
    }
    id = 0;
    for(auto &t : m_Tasks) {
        t.setID(++id);
    }
}

void TaskManager::printTasks() {
    for(const auto &t : m_Tasks) {
        std::cout << t << "\n";
    }
}
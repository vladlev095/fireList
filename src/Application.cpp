#include "Application.h"
#include <iostream>

Application::Application() {
    readFile(); //creates a json object from file in this class
    // check tm constructor with parameter
}

Application::~Application() {
}

void Application::readFile() { //move to task manager
    std::ifstream file("../data.json");
    std::stringstream ss;
    ss << file.rdbuf();
    std::string fileContent = ss.str();
    m_J = ordered_json::parse(ss);
    // std::cout << m_J.dump(4) << "\n";
}

void Application::createTasksList(TaskManager& tm) {
    tm.setTasks(m_J);
}
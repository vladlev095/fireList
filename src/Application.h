#pragma once

#include "TaskManager.h"
#include <iostream>
#include <sstream>

class Application {
public:
    Application();
    ~Application();
    
    void createTasksList(TaskManager& tm);
private:
    void readFile();

    ordered_json m_J;
    TaskManager tm;
};
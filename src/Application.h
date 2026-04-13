#pragma once

#include "TaskManager.h"
#include <iostream>
#include <sstream>

class Application {
public:
    Application();
    ~Application();
private:
    TaskManager tm;
};
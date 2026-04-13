#include "Task.h"
#include "TaskManager.h"
#include "Application.h"

int main() {
    Application app;
    TaskManager tm;
    tm.editTask(2);
    tm.printTasks();
}
#include "Task.h"
#include "TaskManager.h"
#include "Application.h"

int main() {
    TaskManager tm;
    Application app; //create tm in application class
    app.createTasksList(tm);
    tm.printTasks();
}
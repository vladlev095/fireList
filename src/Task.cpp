#include "Task.h"

Task::Task(int& m_nextID, std::string name, int minutesForExec) {
    m_Id = ++m_nextID;
    m_Name = name;
    // m_CreatedAt = createdAt; //now()
    // m_ExpiredAt = expiredAt; // now() + minutesForExec
}

void to_json(ordered_json& j, const Task& task) { //namespace??
    j = ordered_json{{"id", task.m_Id}, {"task", task.m_Name}, {"done", task.m_IsDone},
    {"created", task.m_CreatedAt}, {"expired", task.m_ExpiredAt}};
}

void from_json(const ordered_json& j, Task& task) {
    j.at("id").get_to(task.m_Id);
    j.at("task").get_to(task.m_Name);
    j.at("done").get_to(task.m_IsDone);
    j.at("created").get_to(task.m_CreatedAtStr);
    j.at("expired").get_to(task.m_ExpiredAtStr);
}

void Task::setName(std::string name) { m_Name = name; }
void Task::setStatus(bool isDone) { m_IsDone = isDone; }
#include "Task.h"

Task::Task(int& m_nextID, std::string name, int minutesForExec) { // this is for addTask() only
    m_Id = ++m_nextID;
    m_Name = name;
    const auto now = std::chrono::system_clock::now();
    m_CreatedAt = std::chrono::system_clock::to_time_t(now);
    m_ExpiredAt = m_CreatedAt + minutesForExec;
}

void Task::setName(std::string name) { m_Name = name; }
void Task::setStatus(bool isDone) { m_IsDone = isDone; }
void Task::setDeadline(int minutesForExec) { m_ExpiredAt = m_CreatedAt + minutesForExec; } //?

void to_json(ordered_json &j, const Task &task) {
    j = ordered_json{{"id", task.m_Id}, {"task", task.m_Name}, {"done", task.m_IsDone},
    {"created", task.m_CreatedAt}, {"expired", task.m_ExpiredAt}};
}

void from_json(const ordered_json& j, Task& task) {
    j.at("id").get_to(task.m_Id);
    j.at("task").get_to(task.m_Name);
    j.at("done").get_to(task.m_IsDone);
    j.at("created").get_to(task.m_CreatedAt);
    j.at("expired").get_to(task.m_ExpiredAt);
}

std::ostream& operator<<(std::ostream &os, const Task &task) {
    os << "id: " << task.m_Id << "\ntask: " << task.m_Name << "\nstatus: " << task.m_IsDone << "\ncreated: "
    << task.m_CreatedAt << "\nexpired: " << task.m_ExpiredAt << "\n";
    return os;
}
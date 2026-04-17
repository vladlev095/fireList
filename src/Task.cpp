#include "Task.h"

Task::Task(int& m_nextID, std::string name, int minutesForExec) { // used in TM::addTask() only
    m_id = ++m_nextID; //m_nextID has the last id stored after program run TM::createTasksList()
    m_Name = name; 
    const auto now = std::chrono::system_clock::now();
    m_CreatedAt = std::chrono::system_clock::to_time_t(now);
    m_ExpiredAt = m_CreatedAt + (minutesForExec * 60); 
    //minutes turned to seconds (another function maybe?) / setDeadline() too
} 

void Task::setID(int id) { m_id = id; }
void Task::setName(std::string name) { m_Name = name; }
void Task::setStatus(bool isDone) { m_IsDone = isDone; }
void Task::setDeadline(int minutesForExec) { m_ExpiredAt = m_CreatedAt + (minutesForExec * 60); }

void to_json(ordered_json &j, const Task &task) {
    j = ordered_json{{"id", task.m_id}, {"task", task.m_Name}, {"done", task.m_IsDone},
    {"created", task.m_CreatedAt}, {"expired", task.m_ExpiredAt}};
}

void from_json(const ordered_json& j, Task& task) {
    j.at("id").get_to(task.m_id);
    j.at("task").get_to(task.m_Name);
    j.at("done").get_to(task.m_IsDone);
    j.at("created").get_to(task.m_CreatedAt);
    j.at("expired").get_to(task.m_ExpiredAt);
}

std::ostream& operator<<(std::ostream &os, const Task &task) { //bool into "done/not done"
    os << "id: " << task.m_id << "\ntask: " << task.m_Name << "\nstatus: " << task.m_IsDone << "\ncreated: "
    << task.m_CreatedAt << "\nexpired: " << task.m_ExpiredAt << "\n";
    return os;
}
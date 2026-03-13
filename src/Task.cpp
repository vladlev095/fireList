#include "Task.h"

Task::Task(int id, std::string name, bool isDone, time_t createdAt, time_t expiredAt) {
    m_Id = id;
    m_Name = name;
    m_IsDone = isDone;
    m_CreatedAt = createdAt;
    m_ExpiredAt = expiredAt;
}

void Task::setName(std::string name) { m_Name = name; }
void Task::setStatus(bool isDone) { m_IsDone = isDone; }
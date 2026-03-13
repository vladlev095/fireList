#pragma once

#include <string>

class Task {
public:
    Task() = default;
    Task(int id, std::string name, bool isDone, time_t createdAt, time_t expiredAt);
    void setName(std::string name);
    void setStatus(bool isDone);

    std::string getName() { return m_Name; }
    int getID() { return m_Id; }
    time_t getCreatedAt() { return m_CreatedAt; }
    time_t getDeadline() { return m_ExpiredAt; }

private:
    int m_Id = 0;
    std::string m_Name;
    bool m_IsDone = false;
    time_t m_CreatedAt = 0;
    time_t m_ExpiredAt = 0;
};
#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>

using ordered_json = nlohmann::ordered_json;

class Task {
public:
    Task() = default;
    Task(int& m_nextID, std::string name, int minutesForExec);

    void setID(int id);
    void setName(std::string name);
    void setStatus(bool isDone);
    void setDeadline(int minutes);
    int getID() const { return m_id; } // used in TM
    // const method means that this method is guaranteed not to change anything

    std::string getName() { return m_Name; } // unused getters
    time_t getCreatedAt() { return m_CreatedAt; }
    time_t getDeadline() { return m_ExpiredAt; }

    friend void to_json(ordered_json& j, const Task& task);
    friend void from_json(const ordered_json& j, Task& task);
    friend std::ostream& operator<<(std::ostream& os, const Task& task);

private:
    int m_id = 0;
    std::string m_Name;
    bool m_IsDone = false;
    time_t m_CreatedAt = 0; // const?
    time_t m_ExpiredAt = 0;
    std::string m_CreatedAtStr; //not used now, might be handy for output
    std::string m_ExpiredAtStr;
};
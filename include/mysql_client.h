#pragma once
#include <string>

class MySQLClient {
public:
    MySQLClient();
    int getUserLimit(const std::string& user_id);
};
#include "mysql_client.h"

#include <mysql.h>
#include <iostream>

MySQLClient::MySQLClient() {}

int MySQLClient::getUserLimit(const std::string& user_id) {

    MYSQL* conn = mysql_init(NULL);

    if (conn == NULL) {
        std::cout << "mysql_init failed" << std::endl;
        return 5;
    }

    conn = mysql_real_connect(
        conn,
        "localhost",
        "root",
        "NewPass123",
        "rate_limiter",
        3306,
        NULL,
        0
    );

    if (conn == NULL) {

        std::cout << "Connection failed: "
                  << mysql_error(conn)
                  << std::endl;

        return 5;
    }

    std::string query =
        "SELECT rate_limit FROM users WHERE user_id='" +
        user_id + "'";

    if (mysql_query(conn, query.c_str())) {

        std::cout << "Query failed: "
                  << mysql_error(conn)
                  << std::endl;

        mysql_close(conn);

        return 5;
    }

    MYSQL_RES* result = mysql_store_result(conn);

    if (result == NULL) {

        std::cout << "Result failed: "
                  << mysql_error(conn)
                  << std::endl;

        mysql_close(conn);

        return 5;
    }

    MYSQL_ROW row = mysql_fetch_row(result);

    int limit = 5;

    if (row != NULL) {

        std::cout << "[MYSQL CONNECTED] User limit = "
                 << row[0]
                 << std::endl;

        limit = std::stoi(row[0]);
    }

    mysql_free_result(result);

    mysql_close(conn);

    return limit;
}
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

class SqlSelectQueryBuilder {
private:
    std::vector<std::string> columns;
    std::string from;
    std::multimap<std::string, std::string> where;

public:
    SqlSelectQueryBuilder& add_column(const std::string& column) {
        columns.push_back(column);
        return *this;
    }
    SqlSelectQueryBuilder& add_from(const std::string& aFrom) {
        from = aFrom;
        return *this;
    }
    SqlSelectQueryBuilder& add_where(const std::string& column, const std::string& value) {
        where.insert({ column,value });
        return *this;
    }
    std::string build_query()const {
        std::string query = "SELECT";
        int counter = 0;
        if (from.empty()) {
            throw std::runtime_error("from is missing");
        }
        if (columns.empty()) {
            query += " *";
        }
        else {
            for (const auto& column : columns) {
                query += " " + column;
                if (++counter < columns.size()) {
                    query += ",";
                }
            }
        }
        query += " FROM " + from;
        if (!where.empty()) {
            query += " WHERE";
            counter = 0;
            for (const auto& colval : where) {
                query += " " + colval.first+"="+colval.second;
                if (++counter < where.size()) {
                    query += " AND";
                }
            }
        }
        query += ";";
        return query;
    }
};
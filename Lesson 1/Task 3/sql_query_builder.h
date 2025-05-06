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
                query += " " + colval.first + "=" + colval.second;
                if (++counter < columns.size()) {
                    query += " AND";
                }
            }
        }
        query += ";";
        return query;
    }

    SqlSelectQueryBuilder& add_where(const std::multimap<std::string, std::string>& kv) noexcept {
        for (const auto& colval : kv) {
            where.insert({ colval.first,colval.second });
        }
        return *this;
    }
    SqlSelectQueryBuilder& add_columns(const std::vector<std::string>& aColumns) {
        for (const auto& column : aColumns) {
            columns.push_back(column);
        }
        return *this;
    }
};

class AdvancedSqlSelectQueryBuilder : public SqlSelectQueryBuilder {
private:
    std::map<std::string, std::string> whereGreater;
    std::map<std::string, std::string> whereLess;
public:
    AdvancedSqlSelectQueryBuilder& add_column(const std::string& column) {
        SqlSelectQueryBuilder::add_column(column);
        return *this;
    }
    AdvancedSqlSelectQueryBuilder& add_from(const std::string& aFrom) {
        SqlSelectQueryBuilder::add_from(aFrom);
        return *this;
    }
    AdvancedSqlSelectQueryBuilder& add_where(const std::string& column, const std::string& value) {
        SqlSelectQueryBuilder::add_where(column, value);
        return *this;
    }
    AdvancedSqlSelectQueryBuilder& add_where(const std::multimap<std::string, std::string>& kv) noexcept {
        SqlSelectQueryBuilder::add_where(kv);
        return *this;
    }
    AdvancedSqlSelectQueryBuilder& add_columns(const std::vector<std::string>& aColumns) {
        SqlSelectQueryBuilder::add_columns(aColumns);
        return *this;
    }
    AdvancedSqlSelectQueryBuilder& add_where_greater(const std::string& column, const std::string& value) {
        whereGreater[column] = value;
        return *this;
    }
    AdvancedSqlSelectQueryBuilder& add_where_less(const std::string& column, const std::string& value) {
        whereLess[column] = value;
        return *this;
    }
    std::string build_query()const {
        std::string query = SqlSelectQueryBuilder::build_query();        
        if (!whereGreater.empty() || !whereLess.empty()) {
            int counter = 0;
            query.erase(query.end() - 1);
            if (query.find("WHERE") == std::string::npos) {
                query += " WHERE";
            }
            if (!whereGreater.empty()) {
                for (const auto& colval : whereGreater) {
                    query += " " + colval.first + ">" + colval.second;
                    if (++counter < whereGreater.size()+whereLess.size()) {
                        query += " AND";
                    }
                }
            }
            if (!whereLess.empty()) {
                for (const auto& colval : whereLess) {
                    query += " " + colval.first + "<" + colval.second;
                    if (++counter < whereGreater.size() + whereLess.size()) {
                        query += " AND";
                    }
                }
            }
            query += ";";
        }        
        return query;
    }    
};
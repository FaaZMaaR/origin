#include "sql_query_builder.h"

int main() {
    SqlSelectQueryBuilder queryBuilder;
    queryBuilder.add_column("name").add_column("phone");
    queryBuilder.add_from("students");
    queryBuilder.add_where("id", "42").add_where("name", "John");

    std::cout << queryBuilder.build_query() << std::endl;
}
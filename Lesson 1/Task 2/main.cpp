#include "sql_query_builder.h"

int main() {
    SqlSelectQueryBuilder queryBuilder;
    queryBuilder.add_columns({ "name", "phone" });
    queryBuilder.add_from("students");
    queryBuilder.add_where({ { "id", "42" }, { "name", "John" } });

    std::cout << queryBuilder.build_query() << std::endl;
}
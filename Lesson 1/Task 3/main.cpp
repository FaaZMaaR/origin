#include "sql_query_builder.h"

int main() {
    AdvancedSqlSelectQueryBuilder queryBuilder;
    queryBuilder.add_column("name").add_column("phone");
    queryBuilder.add_from("students");
    queryBuilder.add_where_greater("id", "42").add_where("name", "John").add_where_less("age","25");

    std::cout << queryBuilder.build_query() << std::endl;
}
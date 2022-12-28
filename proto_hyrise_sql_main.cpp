#include "catalog.h"
#include "hsql/sql/Table.h"
#include "querycompiler.h"
#include "queryparser.h"
#include <iostream>

int main() {
  std::cout << "Parsing!" << endl;
  QueryParser queryParser;
  const hsql::SQLStatement* st =
      queryParser.Parse("select * from qqq JOIN www ON a=b JOIN eee ON c=d");
  std::cout << "Compiling!" << endl;
  QueryCompiler queryCompiler(st);
  BasePlanNode* plan = queryCompiler.Compile();
  std::cout << "Plan:" << endl;
  plan->Print();
  std::cout << "Catalog content:" << endl;
  try {
    Catalog& catalog = Catalog::getInstance();
    ATable* table = catalog.GetTable("test1");
    std::cout << table->name_ << endl;
    std::cout << table->columns_[0] << endl;
  } catch (avro::Exception e) {
    std::cout << e.what();
  }
  return 0;
}
#include "queryparser.h"

QueryParser::QueryParser() {}

QueryParser::~QueryParser() {}

const SQLStatement* QueryParser::Parse(string stmt) {
  hsql::SQLParserResult* result = new hsql::SQLParserResult();
  hsql::SQLParser::parse(stmt, result);

  if (result->isValid() && result->size() > 0) {
    const hsql::SQLStatement* statement = result->getStatement(0);
    return statement;
  } else {
    cout << "Analysis error: " << result->errorMsg();
  }
  return nullptr;
}
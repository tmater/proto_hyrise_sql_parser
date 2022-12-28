#ifndef QUERYCOMPILER_H
#define QUERYCOMPILER_H

#pragma once

#include "baseplannode.h"
#include "hsql/SQLParser.h"
#include "hsql/SQLParserResult.h"
#include <vector>

class QueryCompiler {
 public:
  QueryCompiler(const hsql::SQLStatement*);
  ~QueryCompiler();

  BasePlanNode* Compile();

 private:
  const hsql::SQLStatement* stmt_;

  BasePlanNode* CompileSelectStatement(hsql::TableRef*);
};

#endif
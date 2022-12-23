#include "hsql/sql/SelectStatement.h"

#include "querycompiler.h"
#include "scanplannode.h"
#include "joinplannode.h"

QueryCompiler::QueryCompiler(const hsql::SQLStatement* stmt): stmt_(stmt){}

QueryCompiler::~QueryCompiler(){}

BasePlanNode* QueryCompiler::Compile() {
  switch (stmt_->type()) {
    case hsql::StatementType::kStmtSelect: {
      const hsql::SelectStatement*  stmt = static_cast<const hsql::SelectStatement*>(stmt_);
      return CompileSelectStatement(stmt->fromTable);
    }
    default: {
      return nullptr;
    }
  }
  return nullptr;
}

BasePlanNode* QueryCompiler::CompileSelectStatement(hsql::TableRef* tableRef) {
  if (tableRef->type == hsql::kTableName) {
    // Catalog& catalog = Catalog::getInstance();
    // vector<string> fileList = catalog.GetTable(tableRef->getName())->fileList_;
    return new ScanPlanNode();
  }
  JoinPlanNode* join_node = new JoinPlanNode(
      CompileSelectStatement(tableRef->join->left),
      CompileSelectStatement(tableRef->join->right), tableRef->join->type);
  return join_node;
}
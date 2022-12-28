#ifndef JOINPLANNODE_H
#define JOINPLANNODE_H

#pragma once

#include "baseplannode.h"
#include "hsql/SQLParser.h"
#include <iostream>

class JoinPlanNode : public BasePlanNode {
 public:
  JoinPlanNode(BasePlanNode*, BasePlanNode*, hsql::JoinType);
  ~JoinPlanNode();

  void Print(int depth);

 private:
  BasePlanNode* leftChildPlanNode_;
  BasePlanNode* rightChildPlanNode_;
  hsql::JoinType joinType_;
};

#endif
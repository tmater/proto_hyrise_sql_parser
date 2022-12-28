#include "joinplannode.h"
#include <iomanip>

JoinPlanNode::JoinPlanNode(BasePlanNode* leftChildPlanNode,
                           BasePlanNode* rightChildPlanNode,
                           hsql::JoinType joinType)
    : leftChildPlanNode_(leftChildPlanNode),
      rightChildPlanNode_(rightChildPlanNode),
      joinType_(joinType) {}

JoinPlanNode::~JoinPlanNode() {}

void JoinPlanNode::Print(int depth) {
  std::cout << std::string(depth, ' ') << "JOIN-" << depth << std::endl;
  leftChildPlanNode_->Print(depth + 1);
  rightChildPlanNode_->Print(depth + 1);
}
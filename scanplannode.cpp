#include "scanplannode.h"

#include <iomanip>

ScanPlanNode::ScanPlanNode() {}

ScanPlanNode::~ScanPlanNode() {}

void ScanPlanNode::Print(int depth) {
  std::cout << std::string(depth, ' ') << "SCAN-" << depth << std::endl;
}
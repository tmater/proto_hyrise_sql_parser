#ifndef SCANPLANNODE_H
#define SCANPLANNODE_H

#pragma once

#include "baseplannode.h"

#include <iostream>

class ScanPlanNode : public BasePlanNode {
public:
  ScanPlanNode();
  ~ScanPlanNode();

  void Print(int depth);

private:

};

#endif
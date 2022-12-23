#ifndef BASEPLANNODE_H
#define BASEPLANNODE_H

#pragma once

class BasePlanNode {
public:
  virtual void Print(int depth) = 0;
  void Print();

private:

};

#endif
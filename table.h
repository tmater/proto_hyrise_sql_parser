#ifndef TABLE_H
#define TABLE_H

#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Table {
 private:
  /// Name of the table stored in catalog.
  string name_;

  /// Files of this table.
  vector<string> file_paths_;

 public:
  Table();
  ~Table();
};

#endif
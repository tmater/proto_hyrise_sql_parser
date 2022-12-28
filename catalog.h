#ifndef CATALOG_H
#define CATALOG_H

#pragma once

#include "src/generated/catalog_schema.cpp"
#include <iostream>
#include <vector>

using namespace cmr;

class Catalog {
 private:
  /// The actual catalog in-memory
  ACatalog* catalog_;

  /// The path where the catalog is persisted.
  std::string catalogPath_ = "catalog.db";

  Catalog();
  ~Catalog();

 public:
  static Catalog& getInstance() {
    static Catalog instance;
    return instance;
  }

  Catalog(Catalog const& copy) = delete;
  Catalog& operator=(Catalog const& copy) = delete;

  ///
  void PersistCatalog();

  ///
  void ReadCatalog();

  ///
  void CreateTable(std::string tableName, std::vector<std::string>* columnList);

  ///
  void ImportFile(std::string tableName, std::string directoryPath);

  ///
  ATable* GetTable(std::string tableName);
};

#endif
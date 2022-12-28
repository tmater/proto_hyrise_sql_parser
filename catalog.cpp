#include "catalog.h"
#include "avro/Decoder.hh"
#include "avro/Encoder.hh"
#include <filesystem>

Catalog::Catalog() { ReadCatalog(); }

Catalog::~Catalog() {}

void Catalog::PersistCatalog() {
  std::unique_ptr<avro::OutputStream> out =
      avro::fileOutputStream(catalogPath_.c_str());
  avro::EncoderPtr encoder = avro::binaryEncoder();
  encoder->init(*out);
  avro::encode(*encoder, *catalog_);
  out->flush();
}

void Catalog::ReadCatalog() {
  if (std::filesystem::exists(catalogPath_)) {
    std::unique_ptr<avro::InputStream> in =
        avro::fileInputStream(catalogPath_.c_str());
    avro::DecoderPtr decoder = avro::binaryDecoder();
    decoder->init(*in);
    catalog_ = new ACatalog();
    std::cout << "asdf1" << std::endl;
    avro::decode(*decoder, *catalog_);
    std::cout << "asdf2" << std::endl;
  } else {
    catalog_ = new ACatalog();
  }
}

void Catalog::CreateTable(std::string tableName,
                          std::vector<std::string>* columnList) {
  ATable* table = new ATable();
  table->name_ = tableName;
  for (std::string columnName : *columnList) {
    table->columns_.push_back(columnName);
  }
  // catalog_->tableMap_.insert(pair<std::string, ATable>(table->name_,
  // *table));
}

void Catalog::ImportFile(std::string tableName, std::string directoryPath) {
  ATable* table = GetTable(tableName);
  for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
    table->fileList_.push_back(entry.path());
  }
}

ATable* Catalog::GetTable(std::string tableName) {
  return &catalog_->tableMap_.find(tableName)->second;
}
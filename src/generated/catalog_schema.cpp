/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef _USERS_TAMASMATE_PROJECTS_PROTO_HYRISE_SQL_PARSER_SRC_GENERATED_CATALOG_SCHEMA_CPP_2096960776__H_
#define _USERS_TAMASMATE_PROJECTS_PROTO_HYRISE_SQL_PARSER_SRC_GENERATED_CATALOG_SCHEMA_CPP_2096960776__H_


#include <sstream>
#include <any>
#include "avro/Specific.hh"
#include "avro/Encoder.hh"
#include "avro/Decoder.hh"

namespace cmr {
struct ATable {
    std::string name_;
    std::vector<std::string > fileList_;
    std::vector<std::string > columns_;
    ATable() :
        name_(std::string()),
        fileList_(std::vector<std::string >()),
        columns_(std::vector<std::string >())
        { }
};

struct ACatalog {
    std::map<std::string, ATable > tableMap_;
    ACatalog() :
        tableMap_(std::map<std::string, ATable >())
        { }
};

}
namespace avro {
template<> struct codec_traits<cmr::ATable> {
    static void encode(Encoder& e, const cmr::ATable& v) {
        avro::encode(e, v.name_);
        avro::encode(e, v.fileList_);
        avro::encode(e, v.columns_);
    }
    static void decode(Decoder& d, cmr::ATable& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.name_);
                    break;
                case 1:
                    avro::decode(d, v.fileList_);
                    break;
                case 2:
                    avro::decode(d, v.columns_);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.name_);
            avro::decode(d, v.fileList_);
            avro::decode(d, v.columns_);
        }
    }
};

template<> struct codec_traits<cmr::ACatalog> {
    static void encode(Encoder& e, const cmr::ACatalog& v) {
        avro::encode(e, v.tableMap_);
    }
    static void decode(Decoder& d, cmr::ACatalog& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.tableMap_);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.tableMap_);
        }
    }
};

}
#endif

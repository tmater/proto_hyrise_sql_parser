

# Build

## Pre-requisites
```
mkdir -p third_party/local/lib
mkdir -p third_party/local/include
cd third_party
git clone git@github.com:hyrise/sql-parser.git
cd sql-parser
edit Makefile "static ?= no" -> "static ?= yes"
edit Makefile "INSTALL     = /usr/local" -> "INSTALL     =../local"
make
make install
cp libsqlparser.a ../local/lib/
cd ../..
```
```
cd third_party
git clone git@github.com:apache/avro.git
cd avro
brew install boost # let's to with brew boost for now
```

## Build steps
```
mkdir -p cmake/build
cd cmake/build
cmake ../..
make -j
```

## Run
```
./cmake/build/proto_hyrise_sql
```

## TODO

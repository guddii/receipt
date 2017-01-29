# ReceiptCollection Sources
A C++ project for receipt handling.

[![Build Status](https://travis-ci.org/guddii/receipt.svg?branch=master)](https://travis-ci.org/guddii/receipt)

## Getting started
This file can be compiled with `clang`:
```
#!/usr/bin/env bash
clang++ receiptCollection.cpp -c -o receiptCollection.o -std=c++11 -Weverything -Wno-c++98-compat
clang++ receiptItem.cpp -c -o recieptItem.o -std=c++11 -Weverything -Wno-c++98-compat
clang++ main.cpp receiptCollection.o recieptItem.o -o receipt -std=c++11 -Weverything -Wno-c++98-compat
```

Build verified with:
```
Apple LLVM version 8.0.0 (clang-800.0.42.1)
Target: x86_64-apple-darwin16.3.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
```

Invoke program:
```
./receipt
```
## Program tests
Test files require google test to run:
- `ReceiptCollection.test.cpp` Contains ReceiptCollection unit tests
- `ReceiptItem.test.cpp` Contains ReceiptItem unit tests
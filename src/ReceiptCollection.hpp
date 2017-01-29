/**
 *  @file ReceiptCollection.hpp
 *  @brief Interface for receipt function prototypes.
 *
 *  @author Florian Gudat (guddii)
 *  @see https://github.com/guddii/receipt
 *  @bug https://github.com/guddii/receipt/issues
 */

#ifndef RECEIPT_COLLECTION_HPP
#define RECEIPT_COLLECTION_HPP

#include <regex>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include "ReceiptItem.hpp"

class ReceiptCollection {

public:

    ReceiptCollection();

    ReceiptCollection(std::vector<ReceiptItem> collection);

    void dialog();

    double getTotal() const;

    double getTotal(std::string filter) const;

    bool isValidInput(const std::string &price);

    bool isExitInput(const std::string &price);

    bool isStatInput(const std::string &price);

private:

    void set(const std::string &price);

    void input();

    void read();

    std::smatch get(const std::string &price);

    void print(std::ostream &out) const;

    void printReceipt(std::ostream &out) const;

    void printSummary(std::ostream &out) const;

    void write() const;

    std::vector<ReceiptItem> m_collection;

};

#endif

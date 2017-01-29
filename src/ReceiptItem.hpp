/**
 *  @file ReceiptItem.hpp
 *  @brief Interface for ReceiptItem function prototypes.
 *
 *  @author Florian Gudat (guddii)
 *  @see https://github.com/guddii/receipt
 *  @bug https://github.com/guddii/receipt/issues
 */

#ifndef RECEIPT_ITEM_HPP
#define RECEIPT_ITEM_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class ReceiptItem {

public:

    ReceiptItem(double figure, std::string vatType);

    double getFigure() const;

    double getVatFigure() const;

    std::string getVatType() const;

private:

    double m_figure;

    std::string m_vatType;

};

#endif

/**
 *  @file ReceiptItem.cpp
 *  @brief ReceiptItem function prototypes.
 *
 *  @author Florian Gudat (guddii)
 *  @see https://github.com/guddii/receipt
 *  @bug https://github.com/guddii/receipt/issues
 */

#include "ReceiptItem.hpp"

/**
 * @brief Construct a receipt item
 * @param figure Figure entry
 * @param vatType VAT type entry
 */
ReceiptItem::ReceiptItem(double figure, std::string vatType) {
    if (!static_cast<bool>(figure) || !vatType.size()) {
        throw std::runtime_error("Figure and VAT Type are mandatory!");
    }
    m_figure = figure;
    m_vatType = vatType;
}

/**
 * @brief Get the figure
 * @return Returns the figure
 */
double ReceiptItem::getFigure() const {
    return m_figure;
}

/**
 * @brief Get the VAT type
 * @return Return the VAT type
 */
std::string ReceiptItem::getVatType() const {
    return m_vatType;
}

/**
 * @brief Calculate the VAT from a figure
 * @return The rate of VAT from a figure
 */
double ReceiptItem::getVatFigure() const {
    int factor = 19;
    if (getVatType() == "E") {
        factor = 7;
    }
    return ((getFigure() * factor) / (100 + factor));
}

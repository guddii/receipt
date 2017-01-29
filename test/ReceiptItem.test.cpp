/**
 *  @file ReceiptItem.test.cpp
 *  @brief Unit test for ReceiptItem function prototypes.
 *
 *  @author Florian Gudat (guddii)
 *  @see https://github.com/guddii/receipt
 *  @bug https://github.com/guddii/receipt/issues
 */

#include "../src/ReceiptItem.hpp"
#include "gtest/gtest.h"

TEST(ReceiptItemTests, constructorSuccess) {
    EXPECT_NO_THROW(ReceiptItem(1.19, "V"));
}

TEST(ReceiptItemTests, constructorFailure) {
    EXPECT_THROW(ReceiptItem(1.19, ""), std::runtime_error);
}

TEST(ReceiptItemTests, getFigure) {
    ReceiptItem item(1.19, "V");
    EXPECT_EQ(1.19, item.getFigure());
}

TEST(ReceiptItemTests, getVatType) {
    ReceiptItem item(1.19, "V");
    EXPECT_EQ("V", item.getVatType());
}

TEST(ReceiptItemTests, getVatFigure) {
    ReceiptItem item(1.19, "V");
    EXPECT_EQ(0.19, item.getVatFigure());
}

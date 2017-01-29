/**
 *  @file ReceiptCollection.test.cpp
 *  @brief Unit test for ReceiptItem function prototypes.
 *
 *  @author Florian Gudat (guddii)
 *  @see https://github.com/guddii/receipt
 *  @bug https://github.com/guddii/receipt/issues
 */

#include "../src/ReceiptCollection.hpp"
#include "gtest/gtest.h"

TEST(ReceiptCollectionTests, getTotal) {
    std::vector<ReceiptItem> v;
    ReceiptItem item1(1.19, "V");
    ReceiptItem item2(1.07, "E");
    v.push_back(item1);
    v.push_back(item2);
    ReceiptCollection collection(v);
    EXPECT_EQ(2.26, collection.getTotal());
}

TEST(ReceiptCollectionTests, getTotalFiltered) {
    std::vector<ReceiptItem> v;
    ReceiptItem item1(1.19, "V");
    ReceiptItem item2(1.07, "E");
    v.push_back(item1);
    v.push_back(item2);
    ReceiptCollection collection(v);
    EXPECT_EQ(0.19, collection.getTotal("V"));
    EXPECT_EQ(0.07, collection.getTotal("E"));
}

TEST(ReceiptCollectionTests, isExitInput) {
    std::vector<ReceiptItem> v;
    ReceiptCollection collection9(v);
    ReceiptItem item1(1.19, "V");
    v.push_back(item1);
    EXPECT_EQ(true, collection9.isExitInput("0"));
}

TEST(ReceiptCollectionTests, isStatInput) {
    ReceiptCollection collection10;
    EXPECT_EQ(false, collection10.isStatInput("0"));
}
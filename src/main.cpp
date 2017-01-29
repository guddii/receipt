#include <iostream>
#include <exception>
#include "ReceiptCollection.hpp"

/**
 * Entry point of this program
 */
int main() {

    try {

        ReceiptCollection collection;
        collection.dialog();

    } catch (const std::exception &e) {

        std::cerr << e.what() << std::endl;

    }

}

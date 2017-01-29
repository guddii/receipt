/**
 *  @file ReceiptCollection.cpp
 *  @brief Receipt function prototypes.
 *
 *  @author Florian Gudat (guddii)
 *  @see https://github.com/guddii/receipt
 *  @bug https://github.com/guddii/receipt/issues
 */

#include "ReceiptCollection.hpp"

/**
 * @brief Construct receipt w/o further actions
 */
ReceiptCollection::ReceiptCollection() {
}

/**
 * @brief Construct receipt w/ data
 * @param collection A array of receipt
 */
ReceiptCollection::ReceiptCollection(std::vector<ReceiptItem> collection) {
    m_collection = collection;
}

/**
 * @brief Open a user dialog
 */
void ReceiptCollection::dialog() {
    std::cout << std::endl;
    std::cout << "Bitte geben Sie die Beträge ein: " << std::endl;
    std::cout << "--------------------------------" << std::endl;
    input();
}

/**
 * @brief Calculates the total sum
 * @return The sum of all prices
 */
double ReceiptCollection::getTotal() const {
    double total = 0.0;
    for (size_t i = 0; i < m_collection.size(); i++) {
        total += m_collection.at(i).getFigure();

    }
    return total;
}

/**
 * @brief Get total VAT
 * @param filter Filter VAT by identifier
 * @return Total of VAT
 */
double ReceiptCollection::getTotal(std::string filter) const {
    double total = 0.0;
    for (size_t i = 0; i < m_collection.size(); i++) {
        if (m_collection.at(i).getVatType() == filter) {
            total += m_collection.at(i).getVatFigure();
        }
    }
    return total;
}

/**
 * @brief Test input if exit should be called
 * @param price Price values that will be passed from the CLI
 * @return Returns true when session should terminate
 */
bool ReceiptCollection::isExitInput(const std::string &price) {
    return price == "0" && !m_collection.size();
}

/**
 * @brief Test input if statistics should be called
 * @param price Price values that will be passed from the CLI
 * @return Returns true when statistics should be shown
 */
bool ReceiptCollection::isStatInput(const std::string &price) {
    return price == "0" && m_collection.size();
}

/**
 * @brief User input validator
 * @param price Price values that will be passed from the CLI
 * @return True when input is valid
 */
bool ReceiptCollection::isValidInput(const std::string &price) {
    return get(price).size() != 0;
}

/**
 * @brief Get data from CLI
 */
void ReceiptCollection::input() {

    std::string price;
    std::getline(std::cin, price);

    if (!isValidInput(price)) {
        std::cerr << "└> Diese Eingabe wurde ignoriert.";
        std::cerr << std::endl << std::endl;
        input();
    } else if (isExitInput(price)) {
        read();
    } else if (isStatInput(price)) {
        print(std::cout);
        write();
    } else {
        set(price);
        input();
    }

}

/**
 * @brief Read database
 */
void ReceiptCollection::read() {
    std::ifstream input("database.csv");
    for (std::string line; getline(input, line);) {
        set(line);
    }
    printSummary(std::cout);
}

/**
 * @brief Set session based receipt entries
 * @param price Price values that will be passed from the CLI
 */
void ReceiptCollection::set(const std::string &price) {
    std::smatch matches = get(price);
    ReceiptItem item(std::stod(matches[2]), matches[4]);
    m_collection.push_back(item);
}

/**
 * @brief Get data from string
 * @param price Price values that will be passed from the CLI
 * @return Returns an array of matches
 */
std::smatch ReceiptCollection::get(const std::string &price) {
    std::regex expression("(([0-9]{1,5}\\.[0-9]{2})(\\s|;)(V|E))([;0-9]{0,11})|0");
    std::smatch matches;
    std::regex_match(price, matches, expression);
    return matches;
}

/**
 * @brief Print the full receipt on the CLI
 * @param out Printable stream
 */
void ReceiptCollection::print(std::ostream &out) const {
    printReceipt(out);
    printSummary(out);
}

/**
 * @brief Print receipt only on the CLI
 * @param out Printable stream
 */
void ReceiptCollection::printReceipt(std::ostream &out) const {
    out << std::setprecision(2);
    out << std::fixed;
    out << "--------------------------------" << std::endl;
    out << "Rechnung:" << std::endl;
    for (size_t i = 0; i < m_collection.size(); i++) {
        out << "       ";
        out << m_collection.at(i).getFigure();
        out << " ";
        out << m_collection.at(i).getVatType();
        out << std::endl;
    }
}

/**
 * @brief Print summary only on the CLI
 * @param out Printable stream
 */
void ReceiptCollection::printSummary(std::ostream &out) const {
    out << std::setprecision(2);
    out << std::fixed;
    out << "--------------------------------" << std::endl;
    out << "Summe: " << (getTotal()) << " EUR" << std::endl;
    out << "Enthaltene MwSt zu 7%: ";
    out << (getTotal("E")) << " EUR" << std::endl;
    out << "Enthaltene MwSt zu 19%: ";
    out << (getTotal("V")) << " EUR" << std::endl;
    out << "--------------------------------" << std::endl << std::endl;
}

/**
 * @brief Write session data into the database
 */
void ReceiptCollection::write() const {
    std::fstream fs;
    fs.open("database.csv", std::fstream::in | std::fstream::out | std::fstream::app);
    std::time_t session = std::time(nullptr);
    for (size_t i = 0; i < m_collection.size(); i++) {
        fs << std::setprecision(2);
        fs << std::fixed;
        fs << (m_collection.at(i).getFigure()) << ";";
        fs << m_collection.at(i).getVatType() << ";";
        fs << session;
        fs << "\n";
    }
    fs.close();
}

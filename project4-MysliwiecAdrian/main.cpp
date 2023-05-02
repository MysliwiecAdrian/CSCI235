#include <iostream>
#include "LibraryRecord.hpp"

int main() {
    LibraryRecord record("dataset.csv");
    record.displayFilter("Refrigerator"); 
}
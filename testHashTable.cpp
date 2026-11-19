
#include <iostream>
#include <stdexcept>

#include "Dict.h"
#include "TableEntry.h"
#include "HashTable.h"

using namespace std;

int main() {

    HashTable<int> dict(3);

    cout << dict << endl;

    cout << "dict.capacity(): " << dict.capacity() << endl;
    cout << "dict.entries(): " << dict.entries() << endl;

    cout << "dict.insert('One', 1) ..." << endl;
    dict.insert("One", 1);

    cout << "dict.insert('Two', 2) ..." << endl;
    dict.insert("Two", 2);

    cout << "dict.insert('Three', 3) ..." << endl;
    dict.insert("Three", 3);

    cout << "dict.insert('Four', 4) ..." << endl;
    dict.insert("Four", 4);

    cout << "dict.insert('Five', 5) ..." << endl;
    dict.insert("Five", 5);

    cout << "dict.insert('Six', 6) ..." << endl;
    dict.insert("Six", 6);

    cout << endl << dict << endl;

    cout << "dict.search('One'): "
         << dict.search("One") << endl;

    cout << "dict['Four']: "
         << dict["Four"] << endl;

    cout << "dict.remove('Three'): "
         << dict.remove("Three") << endl;

    cout << endl << dict << endl;

    // Comprobación de errores

    try {
        dict.insert("One", 10);
    }
    catch (runtime_error& e) {
        cout << "dict.insert('One') => throwed "
             << "std::runtime_error: "
             << e.what() << endl;
    }

    try {
        dict.search("Ten");
    }
    catch (runtime_error& e) {
        cout << "dict.search('Ten') => throwed "
             << "std::runtime_error: "
             << e.what() << endl;
    }

    try {
        dict.remove("Ten");
    }
    catch (runtime_error& e) {
        cout << "dict.remove('Ten') => throwed "
             << "std::runtime_error: "
             << e.what() << endl;
    }

    return 0;
}


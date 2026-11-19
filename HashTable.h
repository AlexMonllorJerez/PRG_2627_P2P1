
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <list>

#include "Dict.h"
#include "TableEntry.h"

template <typename V>
class HashTable : public Dict<V> {

private:
    int n;
    int max;
    std::list<TableEntry<V>>* table;

    // Función hash
    int h(std::string key) {
        int sum = 0;

        for (int i = 0; i < key.length(); i++) {
            sum += int(key.at(i));
        }

        return sum % max;
    }

public:

    // Constructor
    HashTable(int size) {
        if (size <= 0) {
            throw std::invalid_argument(
                "HashTable size must be positive"
            );
        }

        n = 0;
        max = size;
        table = new std::list<TableEntry<V>>[max];
    }

    // Destructor
    ~HashTable() {
        delete[] table;
    }

    // Número de cubetas
    int capacity() {
        return max;
    }

    // Número de entradas
    int entries() override {
        return n;
    }

    // Insertar un elemento
    void insert(std::string key, V value) override {

        int pos = h(key);

        TableEntry<V> entry(key);

        for (const auto& element : table[pos]) {
            if (element == entry) {
                throw std::runtime_error(
                    "Key '" + key + "' already exists!"
                );
            }
        }

        table[pos].push_front(
            TableEntry<V>(key, value)
        );

        n++;
    }

    // Buscar un elemento
    V search(std::string key) override {

        int pos = h(key);

        TableEntry<V> entry(key);

        for (const auto& element : table[pos]) {
            if (element == entry) {
                return element.value;
            }
        }

        throw std::runtime_error(
            "Key '" + key + "' not found!"
        );
    }

    // Eliminar un elemento
    V remove(std::string key) override {

        int pos = h(key);

        TableEntry<V> entry(key);

        for (auto it = table[pos].begin();
             it != table[pos].end(); ++it) {

            if (*it == entry) {

                V value = it->value;

                table[pos].erase(it);

                n--;

                return value;
            }
        }

        throw std::runtime_error(
            "Key '" + key + "' not found!"
        );
    }

    // Operador []
    V operator[](std::string key) {
        return search(key);
    }

    // Operador de impresión
    friend std::ostream& operator<<(std::ostream& out,
                                    const HashTable<V>& th) {

        out << "HashTable [entries: " << th.n
            << ", capacity: " << th.max << "]\n";

        out << "==============\n";

        for (int i = 0; i < th.max; i++) {

            out << "\n== Cubeta " << i << " ==\n\n";

            out << "List => [";

            if (!th.table[i].empty()) {
                out << "\n";

                for (const auto& element : th.table[i]) {
                    out << "  " << element << "\n";
                }
            }

            out << "]\n";
        }

        out << "\n==============\n";

        return out;
    }
};

#endif


//
// Created by titom on 10/27/2025.
//
#ifndef SLOT_MACHINE_SYMBOL_H
#define SLOT_MACHINE_SYMBOL_H

#include <string>
#include <vector>
#include <map>

class Symbol {
private:
    std::string m_name;
    double m_multiplier;    // payout multiplier (e.g. 0.5, 1, 2, ...)
    int m_probability;      // probability weight (we store the upper bound 1..100)
public:
    Symbol() = default;
    Symbol(const std::string& name, double multiplier, int probability);

    const std::string& name() const;
    double multiplier() const;
    int probability() const;

    // Returns the ASCII art for this symbol (each symbol has fixed 8 lines)
    std::vector<std::string> art() const;

    // Helpers to compute padding / width for ASCII-art
    static int computeMaxSymbolWidth();
    static std::vector<std::string> padToWidth(const std::vector<std::string>& art, int width);

    // static repository of art mapped by name
    static const std::map<std::string, std::vector<std::string>> & artTable();
};

#endif //SLOT_MACHINE_SYMBOL_H
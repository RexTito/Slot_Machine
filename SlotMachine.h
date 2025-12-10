//
// Created by titom on 10/27/2025.
//

#ifndef SLOT_MACHINE_SLOTMACHINE_H
#define SLOT_MACHINE_SLOTMACHINE_H

#include <vector>
#include <string>
#include "Wheel.h"
#include "Symbol.h"

class SlotMachine {
private:
    std::vector<Symbol> m_symbols;   // repository of symbol objects (probabilities + multipliers)
    std::vector<Wheel> m_wheels;     // one wheel per column (3 wheels)
    int m_bank;                      // number of coins the player has
    double Multiplier(const std::string& name) const;
    void initSymbols();              // populate m_symbols in proper cumulative-probability order

public:
    SlotMachine(int wheelCount = 3, int startingCoins = 20);

    int currentBalance() const;
    void insertCoins(int count);

    // Performs a spin with the given bet (removes bet from bank), returns 3x3 results as vector of symbol names
    // return vector of 9 names in row-major order (rows then columns: row0col0, row0col1,...)
    std::vector<std::string> spin(int bet);

    // Payout helper: returns winnings for the middle row (based on bet)
    int evaluateMiddleRowWinnings(const std::vector<std::string>& grid, int bet) const;
    void printPayTable() const;};

#endif //SLOT_MACHINE_SLOTMACHINE_H
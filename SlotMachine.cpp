//
// Created by titom on 10/27/2025.
//

#include "SlotMachine.h"
#include <iostream>
#include <algorithm>
#include <cmath>

SlotMachine::SlotMachine(int wheelCount, int startingCoins)
    : m_bank(startingCoins)
{
    initSymbols();
    m_wheels.reserve(wheelCount);
    for (int i = 0; i < wheelCount; ++i) {
        m_wheels.emplace_back(&m_symbols);
    }
}

void SlotMachine::initSymbols() {
    m_symbols.clear();
    m_symbols.emplace_back("TopHat", 0.0, 30);
    m_symbols.emplace_back("Crown", 0.5, 55);
    m_symbols.emplace_back("Coin", 1.0, 70);
    m_symbols.emplace_back("Seven", 2.0, 80);
    m_symbols.emplace_back("QuestionMark", 3.0, 86);
    m_symbols.emplace_back("Cherry", 3.0, 92);
    m_symbols.emplace_back("Heart", 5.0, 97);
    m_symbols.emplace_back("Diamond", 10.0, 100);
}

int SlotMachine::currentBalance() const { return m_bank; }
void SlotMachine::insertCoins(int count) { m_bank += count; }

std::vector<std::string> SlotMachine::spin(int bet) {
    if (bet <= 0) {
        std::cout << "Bet must be > 0\n";
        return {};
    }
    if (bet > m_bank) {
        std::cout << "Not enough coins to bet that amount.\n";
        return {};
    }

    m_bank -= bet;

    // 3 columns x 3 rows (we assume m_wheels.size() columns)
    int cols = (int)m_wheels.size();
    int rows = 3;
    std::vector<std::string> grid(rows * cols);

    // For each column (wheel), spin 3 times for top/mid/bottom
    for (int col = 0; col < cols; ++col) {
        for (int row = 0; row < rows; ++row) {
            const Symbol &s = m_wheels[col].spin();
            grid[row * cols + col] = s.name();
        }
    }
    return grid;
}

int SlotMachine::evaluateMiddleRowWinnings(const std::vector<std::string>& grid, int bet) const {
    // grid is row-major: row0col0 row0col1 row0col2 | row1col0 row1col1 row1col2 | row2col0 ...
    if (grid.size() < 6) return 0;
    std::string left = grid[1 * 3 + 0];
    std::string mid  = grid[1 * 3 + 1];
    std::string right= grid[1 * 3 + 2];

    if (left == mid && mid == right) {
        // find symbol multiplier
        auto it = std::find_if(m_symbols.begin(), m_symbols.end(),
            [&](const Symbol& s){ return s.name() == mid; });
        if (it != m_symbols.end()) {
            double mult = it->multiplier();
            // winnings are bet * multiplier (rounded down to int)
            int winnings = static_cast<int>(std::floor(bet * mult + 0.000001));
            return winnings;
        }
    }
    return 0;
}
void SlotMachine::printPayTable() const {
    std::cout << "\nPAYOUT TABLE\n";
    std::cout << "-----------------------------------\n";
    for (const auto& s : m_symbols) {
        std::cout << s.name() << " : x" << s.multiplier() << '\n';
    }
    std::cout << "-----------------------------------\n\n";
}

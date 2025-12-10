#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "SlotMachine.h"
#include "Symbol.h"

// helper to print a 3x3 grid of symbol art
void printGrid(const std::vector<std::string>& grid) {
    if (grid.size() < 9) return;
    int width = Symbol::computeMaxSymbolWidth();
    const int HEIGHT = 8; // each art has 8 lines

    std::vector<std::vector<std::string>> arts(9);
    for (int i = 0; i < 9; ++i) {
        // get art from symbol name and pad to width
        std::vector<std::string> a;
        const auto &table = Symbol::artTable();
        auto it = table.find(grid[i]);
        if (it != table.end()) a = it->second;
        else a = std::vector<std::string>(HEIGHT, std::string(width, ' '));
        arts[i] = Symbol::padToWidth(a, width);
    }

    for (int row = 0; row < 3; ++row) {
        for (int line = 0; line < HEIGHT; ++line) {
            for (int col = 0; col < 3; ++col) {
                std::cout << arts[row * 3 + col][line] << "  ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
}


int main() {
    SlotMachine machine(3, 25);  // 3 wheels, 25 starting credits


    std::cout << "Simple Slot Machine\n";
    std::cout << "Starting balance: "
              << machine.currentBalance() << " credits.\n";
    machine.printPayTable();

    char again = 'y';
    while (again == 'y' || again == 'Y') {
        if (machine.currentBalance() <= 0) {
            char add;
            std::cout << "You are out of credits. Add more? (y/n) ";
            std::cin >> add;
            if (add == 'y' || add == 'Y') {
                int more;
                std::cout << "How many credits would you like to add? ";
                std::cin >> more;
                machine.insertCoins(more);
                std::cout << "New balance is: "
                          << machine.currentBalance() << " credits.\n";
            } else {
                std::cout << "Game over.\n";
                std::cout << "Thanks for playing!\n";
                return 0;
            }
        }
        int bet;
        std::cout << "Place your bet (current balance "
                  << machine.currentBalance() << "): ";
        std::cin >> bet;
        auto grid = machine.spin(bet);
        if (grid.empty()) {
            continue;
        }
        printGrid(grid);
        int winnings = machine.evaluateMiddleRowWinnings(grid,bet);
        if (winnings > 0) {
            machine.insertCoins(winnings);
            std::cout<<"You bet "<< bet << " credits and Won "
                     << winnings << " credits!.\n";
        } else {
            std::cout << "You bet "<< bet << " credits but lost.\n";
        }
        std::cout << "New balance: "
                  << machine.currentBalance() << " credits.\n";
    std::cout << "Spin again? (y/n): ";
    std::cin >> again;
    }
    std::cout << "Thanks for playing!\n";
    return 0;
}


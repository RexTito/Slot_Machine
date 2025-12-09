#include <iostream>
#include "SlotMachine.h"

int main() {
    SlotMachine machine(3, 10);  // 3 wheels, 10 starting credits

    std::cout << "Simple Slot Machine\n";
    std::cout << "Starting balance: "
              << machine.currentBalance() << " credits.\n";

    char again = 'y';
    while (again == 'y' || again == 'Y') {
        int bet;
        std::cout << "Place your bet (current balance "
                  << machine.currentBalance() << "): ";
        std::cin >> bet;

        machine.spin(bet);

        if (machine.currentBalance() <= 0) {
            std::cout << "You are out of credits. Game over.\n";
            break;
        }

        std::cout << "Spin again? (y/n): ";
        std::cin >> again;
    }

    std::cout << "Thanks for playing!\n";
    return 0;
}


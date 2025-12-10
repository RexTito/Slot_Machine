//
// Created by titom on 10/27/2025.
//

#ifndef SLOT_MACHINE_WHEEL_H
#define SLOT_MACHINE_WHEEL_H

#include <random>
#include <vector>
#include "Symbol.h"

class Wheel {
private:
    std::mt19937 m_rng;
    const std::vector<Symbol> *m_symbols; // pointer to repository of symbols (owned elsewhere)
public:
    Wheel(const std::vector<Symbol> *symbols);
    // returns a symbol chosen by rolling 1..100 and mapping using probability ranges
    const Symbol& spin();
};

#endif //SLOT_MACHINE_WHEEL_H
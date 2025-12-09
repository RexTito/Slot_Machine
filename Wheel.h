//
// Created by titom on 10/27/2025.
//

#ifndef SLOT_MACHINE_WHEEL_H
#define SLOT_MACHINE_WHEEL_H

#include <vector>
#include <random>
#include "Symbol.h"

class Wheel {
private:
    std::vector<Symbol> m_strip; // list of possible symbols
    std::mt19937 m_rng;          // random number generator

public:
    Wheel();
    Symbol spin();               // returns a randomly chosen Symbol
};


#endif //SLOT_MACHINE_WHEEL_H
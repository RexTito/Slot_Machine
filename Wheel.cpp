//
// Created by titom on 10/27/2025.
//

#include "Wheel.h"
#include <random>
#include <stdexcept>

Wheel::Wheel(const std::vector<Symbol> *symbols)
    : m_symbols(symbols)
{
    std::random_device rd;
    m_rng.seed(rd());
}

const Symbol& Wheel::spin() {
    if (!m_symbols || m_symbols->empty())
        throw std::runtime_error("Wheel has no symbols repository");

    std::uniform_int_distribution<int> dist(1, 100);
    int roll = dist(m_rng);

    // Symbols are expected to have their probability() as upper bound in 1..100
    // We'll search for the first symbol with probability >= roll
    for (const auto &sym : *m_symbols) {
        if (roll <= sym.probability()) return sym;
    }
    // fallback (shouldn't happen if probabilities configured correctly)
    return (*m_symbols)[m_symbols->size() - 1];
}

//
// Created by titom on 10/27/2025.
//

#include "Wheel.h"


Wheel::Wheel() : m_rng(std::random_device{}()) {
    // name, multiplier, probability weight (roughly 100 total)
    m_strip.emplace_back("TopHat",   10, 30); // 1–30
    m_strip.emplace_back("Crown",     5, 25); // 31–55
    m_strip.emplace_back("Coin",      3, 15); // 56–70
    m_strip.emplace_back("Seven",     4, 10); // 71–80
    m_strip.emplace_back("Wild",      6,  6); // 81–86
    m_strip.emplace_back("Cherry",    2,  6); // 87–92
    m_strip.emplace_back("Heart",     7,  5); // 93–97
    m_strip.emplace_back("Diamond",   8,  3); // 98–100
}

Symbol Wheel::spin() {
    int totalProb = 0;
    for (const auto& s : m_strip) {
        totalProb += s.probability();
    }

    std::uniform_int_distribution<int> dist(1, totalProb);
    int roll = dist(m_rng);

    int cumulative = 0;
    for (const auto& s : m_strip) {
        cumulative += s.probability();
        if (roll <= cumulative) {
            return s;
        }
    }

    // Fallback (shouldn't happen)
    return m_strip.back();
}

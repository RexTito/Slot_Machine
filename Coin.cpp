//
// Created by titom on 10/27/2025.
//

#include "Coin.h"

Coin::Coin(long cents) : m_cents(cents) {}

long Coin::value() const {
    return m_cents;
}
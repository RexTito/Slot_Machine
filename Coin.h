//
// Created by titom on 10/27/2025.
//

#ifndef SLOT_MACHINE_COIN_H
#define SLOT_MACHINE_COIN_H

class Coin {
private:
    long m_cents;          // value of one coin in cents (default 25)

public:
    explicit Coin(long cents = 25); // cannot change coin value
    long value() const;
};

#endif //SLOT_MACHINE_COIN_H
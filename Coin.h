//
// Created by titom on 10/27/2025.
//

#ifndef SLOT_MACHINE_COIN_H
#define SLOT_MACHINE_COIN_H

class Coin {
private:
    long m_cents;          // value of one coin in cents (default 25)

public:
    Coin();
    Coin(long cents);
    long value() const;
};
#endif //SLOT_MACHINE_COIN_H
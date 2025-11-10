//
// Created by titom on 10/27/2025.
//
#include <iostream>
#include <random>
#include "Symbol.h"

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    int roll = dist(gen);
    std::cout << roll << std::endl;

    if (roll <= 30) {
        std::cout << " _______________" << std::endl;
        std::cout << "|    ______     |" << std::endl;
        std::cout << "|   |       |   |" << std::endl;
        std::cout << "|   |       |   |" << std::endl;
        std::cout << "| __|       |__ |" << std::endl;
        std::cout << "||             ||" << std::endl;
        std::cout << "||_____________||" << std::endl;
        std::cout << "|_______________|" << std::endl;
    }
    else if (roll <= 55 and roll > 30) {
        std::cout << " _______________" << std::endl;
        std::cout << "|   0   0    0  |" << std::endl;
        std::cout << "|  |\\  /-\\  /|  |" << std::endl;
        std::cout << "|  | \\/   \\/ |  |" << std::endl;
        std::cout << "|  |         |  |" << std::endl;
        std::cout << "|  |         |  |" << std::endl;
        std::cout << "|  |_________|  |" << std::endl;
        std::cout << "|_______________|" << std::endl;
    }
    else if (roll <= 70 and roll > 55) {
        std::cout << " _______________" << std::endl;
        std::cout << "|      ___      |" << std::endl;
        std::cout << "|     /   \\     |" << std::endl;
        std::cout << "|    /     \\    |" << std::endl;
        std::cout << "|   |   $   |   |" << std::endl;
        std::cout << "|    \\     /    |" << std::endl;
        std::cout << "|     \\___/     |" << std::endl;
        std::cout << "|_______________|" << std::endl;
    }
    else if (roll <= 80 and roll > 70) {
        std::cout << " _______________" << std::endl;
        std::cout << "|   _________   |" << std::endl;
        std::cout << "|  |_____   /   |" << std::endl;
        std::cout << "|       /  /    |" << std::endl;
        std::cout << "|      /  /     |" << std::endl;
        std::cout << "|     /  /      |" << std::endl;
        std::cout << "|    /__/       |" << std::endl;
        std::cout << "|_______________|" << std::endl;
    }
    else if (roll <= 86 and roll > 80) {
        std::cout << " _______________" << std::endl;
        std::cout << "|     ____      |" << std::endl;
        std::cout << "|    /    \\     |" << std::endl;
        std::cout << "|    |    /     |" << std::endl;
        std::cout << "|        /      |" << std::endl;
        std::cout << "|       |       |" << std::endl;
        std::cout << "|       0       |" << std::endl;
        std::cout << "|_______________|" << std::endl;
    }
    else if (roll <= 92 and roll > 86) {
        std::cout << " _______________" << std::endl;
        std::cout << "|        _      |" << std::endl;
        std::cout << "|       /|      |" << std::endl;
        std::cout << "|    __/ |__    |" << std::endl;
        std::cout << "|   /  \\ /  \\   |" << std::endl;
        std::cout << "|  |    |    |  |" << std::endl;
        std::cout << "|   \\__/ \\__/   |" << std::endl;
        std::cout << "|_______________|" << std::endl;
    }
    else if (roll <= 97 and roll > 92) {
        std::cout << " _______________" << std::endl;
        std::cout << "|    __  __     |" << std::endl;
        std::cout << "|   /  \\/  \\    |" << std::endl;
        std::cout << "|   \\      /    |" << std::endl;
        std::cout << "|    \\    /     |" << std::endl;
        std::cout << "|     \\  /      |" << std::endl;
        std::cout << "|      \\/       |" << std::endl;
        std::cout << "|_______________|" << std::endl;
    }
    else{
        std::cout << " _______________" << std::endl;
        std::cout << "|    _______    |" << std::endl;
        std::cout << "|   /       \\   |" << std::endl;
        std::cout << "|   \\       /   |" << std::endl;
        std::cout << "|    \\     /    |" << std::endl;
        std::cout << "|     \\   /     |" << std::endl;
        std::cout << "|      \\_/      |" << std::endl;
        std::cout << "|_______________|" << std::endl;
    }

    return 0;
}
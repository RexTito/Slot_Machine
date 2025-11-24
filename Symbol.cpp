#include <iostream>
#include <random>
#include <vector>
#include <string>

// This returns the art for symbol based on the roll
std::vector<std::string> getSymbol(int roll) {
    if (roll <= 30) {
        return {
            " _______________ ",
            "|    _______    |",
            "|   |       |   |",
            "|   |       |   |",
            "| __|       |__ |",
            "||             ||",
            "||_____________||",
            "|_______________|"
        };
    }
    else if (roll <= 55) {
        return {
            " _______________ ",
            "|   0   0    0  |",
            "|  |\\  /-\\  /|  |",
            "|  | \\/   \\/ |  |",
            "|  |         |  |",
            "|  |         |  |",
            "|  |_________|  |",
            "|_______________|"
        };
    }
    else if (roll <= 70) {
        return {
            " _______________ ",
            "|      ___      |",
            "|     /   \\     |",
            "|    /     \\    |",
            "|   |   $   |   |",
            "|    \\     /    |",
            "|     \\___/     |",
            "|_______________|"
        };
    }
    else if (roll <= 80) {
        return {
            " _______________ ",
            "|   _________   |",
            "|  |_____   /   |",
            "|       /  /    |",
            "|      /  /     |",
            "|     /  /      |",
            "|    /__/       |",
            "|_______________|"
        };
    }
    else if (roll <= 86) {
        return {
            " _______________ ",
            "|     ____      |",
            "|    /    \\     |",
            "|    |    /     |",
            "|        /      |",
            "|       |       |",
            "|       0       |",
            "|_______________|"
        };
    }
    else if (roll <= 92) {
        return {
            " _______________ ",
            "|        _      |",
            "|       /|      |",
            "|    __/ |__    |",
            "|   /  \\ /  \\   |",
            "|  |    |    |  |",
            "|   \\__/ \\__/   |",
            "|_______________|"
        };
    }
    else if (roll <= 97) {
        return {
            " _______________ ",
            "|    __  __     |",
            "|   /  \\/  \\    |",
            "|   \\      /    |",
            "|    \\    /     |",
            "|     \\  /      |",
            "|      \\/       |",
            "|_______________|"
        };
    }
    else {
        return {
            " _______________ ",
            "|    _______    |",
            "|   /       \\   |",
            "|   \\       /   |",
            "|    \\     /    |",
            "|     \\   /     |",
            "|      \\_/      |",
            "|_______________|"
        };
    }
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);

    // This prints a 3x3 grid of our symbols
    std::vector<std::vector<std::vector<std::string>>> grid(3, std::vector<std::vector<std::string>>(3));

    // This generates all the rolls we need and it gets the symbols assigned to the value
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            int roll = dist(gen);
            grid[r][c] = getSymbol(roll);
        }
    }

    // Each symbol is 8 lines tall
    const int SYMBOL_HEIGHT = 8;

    // This prints the grid of symbols by doing it row by row, with the symbols side by side
     for (int row = 0; row < 3; row++) {
        for (int line = 0; line < SYMBOL_HEIGHT; line++) {
            std::cout
                << grid[row][0][line] << "   "
                << grid[row][1][line] << "   "
                << grid[row][2][line] << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
#include <iostream>
#include <random>
#include <vector>
#include <map>
#include <string>

//This is the drawing of our symbols
static std::map<std::string, std::vector<std::string>> SYMBOLS = {
    {
        "Top-Hat",
        {
            " _______________",
            "|    ______     |",
            "|   |       |   |",
            "|   |       |   |",
            "| __|       |__ |",
            "||             ||",
            "||_____________||",
            "|_______________|"
        }
    },
    {
        "Crown",
        {
            " _______________",
            "|   0   0    0  |",
            "|  |\\  /-\\  /|  |",
            "|  | \\/   \\/ |  |",
            "|  |         |  |",
            "|  |         |  |",
            "|  |_________|  |",
            "|_______________|"
        }
    },
    {
        "Coin",
        {
            " _______________",
            "|      ___      |",
            "|     /   \\     |",
            "|    /     \\    |",
            "|   |   $   |   |",
            "|    \\     /    |",
            "|     \\___/     |",
            "|_______________|"
        }
    },
    {
        "Seven",
        {
            " _______________",
            "|   _________   |",
            "|  |_____   /   |",
            "|       /  /    |",
            "|      /  /     |",
            "|     /  /      |",
            "|    /__/       |",
            "|_______________|"
        }
    },
    {
        "Question-Mark",
        {
            " _______________",
            "|     ____      |",
            "|    /    \\     |",
            "|    |    /     |",
            "|        /      |",
            "|       |       |",
            "|       0       |",
            "|_______________|"
        }
    },
    {
        "Cherry",
        {
            " _______________",
            "|        _      |",
            "|       /|      |",
            "|    __/ |__    |",
            "|   /  \\ /  \\   |",
            "|  |    |    |  |",
            "|   \\__/ \\__/   |",
            "|_______________|"
        }
    },
    {
        "Heart",
        {
            " _______________",
            "|    __  __     |",
            "|   /  \\/  \\    |",
            "|   \\      /    |",
            "|    \\    /     |",
            "|     \\  /      |",
            "|      \\/       |",
            "|_______________|"
        }
    },
    {
        "Diamond",
        {
            " _______________",
            "|    _______    |",
            "|   /       \\   |",
            "|   \\       /   |",
            "|    \\     /    |",
            "|     \\   /     |",
            "|      \\_/      |",
            "|_______________|"
        }
    }
};

// This returns the art for symbol based on the roll
std::string getSymbolName(int roll) {
    if (roll <= 30) return "Top-Hat";
    if (roll <= 55) return "Crown";
    if (roll <= 70) return "Coin";
    if (roll <= 80) return "Seven";
    if (roll <= 86) return "Question-Mark";
    if (roll <= 92) return "Cherry";
    if (roll <= 97) return "Heart";
    return "Diamond";
}

int computeMaxSymbolWidth() {
    int maxw = 0;
    for (const auto &p : SYMBOLS) {
        for (const std::string &line : p.second) {
            if ((int)line.size() > maxw) maxw = (int)line.size();
        }
    }
    return maxw;
}

// Got help with this and the function above this
// Pad each line to the specified width (right-pad with spaces).
// We right-pad for simplicity (keeps left borders aligned).
std::vector<std::string> padToWidth(const std::vector<std::string>& art, int width) {
    std::vector<std::string> padded;
    padded.reserve(art.size());
    for (const auto &line : art) {
        std::string s = line;
        if ((int)s.size() < width) s += std::string(width - s.size(), ' ');
        padded.push_back(s);
    }
    return padded;
}

// Retrieve art by name and return padded art
std::vector<std::string> getSymbolArt(const std::string& name, int width) {
    auto it = SYMBOLS.find(name);
    if (it == SYMBOLS.end()) return std::vector<std::string>(8, std::string(width, ' '));
    return padToWidth(it->second, width);
}


int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);

    const int SYMBOL_HEIGHT = 8;
    const int MAX_WIDTH = computeMaxSymbolWidth();

    // This builds a 3x3 grid for the symbols
    std::vector<std::vector<std::vector<std::string>>> grid(3, std::vector<std::vector<std::string>>(3, std::vector<std::string>()));

    // This generates all the rolls we need, and it gets the symbols assigned to the value
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; c++) {
            int roll = dist(gen);
            std::string name = getSymbolName(roll);
            grid[r][c] = getSymbolArt(name, MAX_WIDTH);
        }
    }
    // This prints the grid of symbols by doing it row by row, with the symbols side by side
    for (int r = 0; r < 3; r++) {
        for (int line = 0; line < SYMBOL_HEIGHT; line++) {
            std::cout
                << grid[r][0][line] << "   "
                << grid[r][1][line] << "   "
                << grid[r][2][line] << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
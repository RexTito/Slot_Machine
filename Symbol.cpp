#include "Symbol.h"
#include <algorithm>

static std::map<std::string, std::vector<std::string>> SYMBOL_ARTS = {
    {
        "TopHat",
        {
            " _______________",
            "|    _______    |",
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
        "QuestionMark",
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

Symbol::Symbol(const std::string& name, double multiplier, int probability)
    : m_name(name), m_multiplier(multiplier), m_probability(probability) {}

const std::string& Symbol::name() const { return m_name; }
double Symbol::multiplier() const { return m_multiplier; }
int Symbol::probability() const { return m_probability; }

std::vector<std::string> Symbol::art() const {
    auto it = SYMBOL_ARTS.find(m_name);
    if (it != SYMBOL_ARTS.end()) return it->second;
    return {"", "", "", "", "", "", "", ""};
}

const std::map<std::string, std::vector<std::string>> & Symbol::artTable() {
    return SYMBOL_ARTS;
}

int Symbol::computeMaxSymbolWidth() {
    int maxw = 0;
    for (auto &p : SYMBOL_ARTS) {
        for (auto &line : p.second)
            maxw = std::max(maxw, (int)line.size());
    }
    return maxw;
}

std::vector<std::string> Symbol::padToWidth(const std::vector<std::string>& art, int width) {
    std::vector<std::string> out;
    out.reserve(art.size());
    for (const auto &line : art) {
        std::string padded = line;
        if ((int)padded.size() < width)
            padded += std::string(width - padded.size(), ' ');
        out.push_back(padded);
    }
    return out;
}

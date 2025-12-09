//
// Created by titom on 10/27/2025.
//

#ifndef SLOT_MACHINE_SYMBOL_H
#define SLOT_MACHINE_SYMBOL_H

std::string getSymbolName(int roll);
int computeMaxSymbolWidth();
std::vector<std::string> padToWidth(const std::vector<std::string>& art, int width);
std::vector<std::string> getSymbolArt(const std::string& name, int width);

#endif //SLOT_MACHINE_SYMBOL_H
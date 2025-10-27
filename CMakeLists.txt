cmake_minimum_required(VERSION 4.0)
project(Slot_Machine)

set(CMAKE_CXX_STANDARD 14)

add_executable(Slot_Machine
        .idea/.gitignore
        .idea/workspace.xml
        main.cpp
        README.md
        SlotMachine.cpp
        SlotMachine.h
        Coin.cpp
        Coin.h
        Wheel.cpp
        Wheel.h
        Symbol.cpp
        Symbol.h)

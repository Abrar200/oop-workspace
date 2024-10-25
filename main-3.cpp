#include <iostream>
#include "Game.hpp"

int main()
{
    // Create a 4x6 grid with a pit at (3,0)
    std::vector<std::tuple<int, int>> pitCoordinates = {
        std::make_tuple(3, 0)};

    Game game(4, 6, pitCoordinates);

    std::cout << "Initial game state:" << std::endl;
    game.displayState();
    std::cout << "\nInitial grid:" << std::endl;
    game.printGrid();

    // Test some moves
    std::cout << "\nMoving right..." << std::endl;
    game.movePlayer(1, 0);
    game.printGrid();
    game.displayState();

    std::cout << "\nMoving right again..." << std::endl;
    game.movePlayer(1, 0);
    game.printGrid();
    game.displayState();

    std::cout << "\nTrying to move into pit..." << std::endl;
    game.movePlayer(1, 0);
    game.printGrid();
    game.displayState();

    return 0;
}
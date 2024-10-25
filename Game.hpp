#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <tuple>
#include <iostream>
#include "Explorer.hpp"
#include "Exit.hpp"
#include "Pit.hpp"

enum GameState
{
    WIN,
    LOSE,
    PLAYING
};

class Game
{
private:
    int m_width;
    int m_height;
    GameState m_state;
    Explorer *m_player;
    Exit *m_exit;
    std::vector<Pit *> m_pits;

    void checkGameState()
    {
        // Check if player reached exit
        if (m_exit->interact(m_player))
        {
            m_state = WIN;
            return;
        }

        // Check if player fell into a pit and ran out of stamina
        for (auto pit : m_pits)
        {
            if (pit->interact(m_player))
            {
                m_state = LOSE;
                return;
            }
        }
    }

public:
    Game(int width, int height, std::vector<std::tuple<int, int>> pitCoordinates)
        : m_width(width), m_height(height), m_state(PLAYING)
    {

        // Create player at (0,0)
        m_player = new Explorer(width, height);

        // Create exit at (width-1, height-1)
        m_exit = new Exit(width, height);

        // Create pits at specified coordinates
        for (const auto &coord : pitCoordinates)
        {
            int x = std::get<0>(coord);
            int y = std::get<1>(coord);

            // Skip if position is taken by player or exit
            if ((x == 0 && y == 0) || (x == width - 1 && y == height - 1))
            {
                continue;
            }

            m_pits.push_back(new Pit(x, y, width, height));
        }
    }

    ~Game()
    {
        delete m_player;
        delete m_exit;
        for (auto pit : m_pits)
        {
            delete pit;
        }
    }

    bool displayState()
    {
        switch (m_state)
        {
        case WIN:
            std::cout << "You win!" << std::endl;
            return true;
        case LOSE:
            std::cout << "You lose :(" << std::endl;
            return true;
        case PLAYING:
            std::cout << "Game on" << std::endl;
            return false;
        default:
            return false;
        }
    }

    void movePlayer(int dx, int dy)
    {
        if (m_state == PLAYING)
        {
            m_player->move(dx, dy);
            checkGameState();
        }
    }

    void printGrid()
    {
        for (int y = 0; y < m_height; ++y)
        {
            for (int x = 0; x < m_width; ++x)
            {
                // Default to underscore
                char cell = '_';

                // Get positions
                auto [playerX, playerY] = m_player->getCoordinates();
                auto [exitX, exitY] = m_exit->getCoordinates();

                // If player is here, always show X regardless of what's underneath
                if (x == playerX && y == playerY)
                {
                    std::cout << 'X';
                    continue;
                }

                // Check for exit
                if (x == exitX && y == exitY)
                {
                    cell = 'E';
                }

                // Check for pits
                for (const auto &pit : m_pits)
                {
                    auto [pitX, pitY] = pit->getCoordinates();
                    if (x == pitX && y == pitY)
                    {
                        cell = 'P';
                        break;
                    }
                }

                std::cout << cell;
            }
            std::cout << std::endl;
        }
    }
};

#endif
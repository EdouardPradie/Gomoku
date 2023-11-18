/*
** EPITECH PROJECT, 2023
** AIA_gomoku
** File description:
** main
*/

#include "Board.hpp"
#include "Gomoku.hpp"
#include <tuple>

int main(int const argc, char *const *argv)
{
    try {
        Gomoku game(5, 5);

        // Player 1 places a tile at (0, 0)
        game.setTile(0, 0, Board::Tile::PLAYER1);
        // Check the state of the game
        std::cout << game.getGame()->toString() << std::endl;

        // Player 2 places a tile at (0, 1)
        game.setTile(0, 1, Board::Tile::PLAYER2);
        // Check the state of the game
        std::cout << game.getGame()->toString() << std::endl;

        // Call the Expand function
        game.getMonteCarlo()->Expand();

        // Check the state of the game after expanding
        for (const auto &node : game.getMonteCarlo()->getNode()) {
            std::cout << node.getSandBox()->toString() << std::endl;
        }
        return SUCCESS;
    } catch (const std::exception &e) {
        return FAILURE;
    }
    return SUCCESS;
}
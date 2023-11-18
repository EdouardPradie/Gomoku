/*
** EPITECH PROJECT, 2023
** Gomoku
** File description:
** Board class for gomoku project
*/

#include <cstddef>
#include <memory>
#include <tuple>
#include <vector>

#pragma once

class Board
{
    public:
        enum Tile {
            EMPTY,
            PLAYER1,
            PLAYER2,
            ERROR,
        };

        Board(size_t size_y = 20, size_t size_x = 20);
        Board &operator=(Board const &to_copy);
        ~Board();
        void setBoard(size_t size_y, size_t size_x);
        void setBoard(std::shared_ptr<std::vector<std::vector<Tile>>> &board);
        std::tuple<size_t, size_t> getSize() const;
        std::shared_ptr<std::vector<std::vector<Tile>>> getBoard() const;
        void setTile(size_t pos_y, size_t pos_x, Tile status);
        Tile getTile(size_t pos_y, size_t pos_x) const;

    private:
        size_t size_x;
        size_t size_y;
        std::shared_ptr<std::vector<std::vector<Tile>>> board;
};

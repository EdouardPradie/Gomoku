/*
** EPITECH PROJECT, 2023
** gomoku
** File description:
** game class
*/

#pragma once

#include "Command.hpp"

class Game
{
    public:
        Game();
        Game(size_t size_y, size_t size_x);
        void setBoard(size_t size_y = 20, size_t size_x = 20);
        std::shared_ptr<const Board> getBoard() const;
        void setTile(size_t pos_y, size_t pos_x, Board::Tile tile);
        Board::Tile getTile(size_t pos_y, size_t pos_x) const;
        void setCommand(std::shared_ptr<Board> &board);
        std::shared_ptr<Board> getCommandsBoard() const;
        std::shared_ptr<Command> getCommands() const;
        bool checkTiles(size_t pos_y, size_t pos_x, int d_y, int d_x, Board::Tile tile);
        bool checkWinOnTurn(std::tuple<size_t, size_t> pos, Board::Tile tile);
        std::string toString() const;
        ~Game() = default;

    private:
        std::shared_ptr<Command> commands;
        std::shared_ptr<Board> board;
};

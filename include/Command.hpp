/*
** EPITECH PROJECT, 2023
** AIA_gomoku
** File description:
** Command.hh
*/

#pragma once

#include "Board.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Command
{
    public:
        Command() = default;
        Command(Command const &to_copy) = default;
        Command(Command &&to_move) = default;
        ~Command() = default;
        Command &operator=(Command const &to_copy) = default;
        Command &operator=(Command &&to_move) = default;

        void parseCommand(std::vector<std::string> message);
        void setBoard(std::shared_ptr<Board> &board);
        void resetBoard(size_t size_y = 20, size_t size_x = 20);
        std::shared_ptr<Board> getBoard() const;
        void setTile(int cord_y, int cord_x, Board::Tile tile);
        void beginCommand(size_t size, size_t time, Board::Tile tile);
        void turnCommand(size_t cord_y, size_t cord_x, Board::Tile tile);
        void boardCommand(size_t size_y, size_t size_x, Board::Tile tile);
        static void aboutCommand(size_t size_y, size_t size_x, Board::Tile tile);
        [[nodiscard]] std::vector<std::string> getMessage();
        // void setStart(int size);
        // static void setInfo(std::string key, int value);
        // static void setEnd();
        // static void setAbout();
    private:
        std::vector<unsigned int> m_cord{0, 0};
        std::string m_message{};
        std::shared_ptr<Board> board;
};

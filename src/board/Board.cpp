/*
** EPITECH PROJECT, 2023
** Gomoku
** File description:
** Board cpp file
*/

#include "Board.hpp"
#include "Gomoku.hpp"
#include <cstddef>
#include <stdexcept>

Board::Board(size_t size_y, size_t size_x)
{
    if (size_x != size_y) {
        std::cout << "Board must be a square" << std::endl;
        throw std::invalid_argument("Board must be a square");
    }
    if (size_x < 5 || size_x > 20) {
        std::cout << "Board size must be between 5 and 20" << std::endl;
        throw std::invalid_argument("Board size must be between 5 and 20");
    }
    setBoard(size_y, size_x);
}

void Board::setBoard(size_t size_y, size_t size_x)
{
    this->size_y = size_y;
    this->size_x = size_x;
    this->board =
        std::make_shared<std::vector<std::vector<Tile>>>(size_y, std::vector<Tile>(size_x, EMPTY));
}

void Board::setBoard(std::shared_ptr<std::vector<std::vector<Tile>>> &board)
{
    this->board = board;
}

std::shared_ptr<std::vector<std::vector<Board::Tile>>> Board::getBoard() const
{
    return board;
}

void Board::setTile(size_t pos_y, size_t pos_x, Tile status)
{
    if (pos_x < size_x && pos_y < size_y) {
        (*board)[pos_y][pos_x] = status;
    } else {
        //std::cout << "Position out of range on setTile" << std::endl;
        throw std::out_of_range("Position out of range");
    }
}

Board::Tile Board::getTile(size_t pos_y, size_t pos_x) const
{
    if (pos_x < size_x && pos_y < size_y) {
        return (*board)[pos_y][pos_x];
    }
    //std::cout << "Position out of range on getTile" << std::endl;
    throw std::out_of_range("Position out of range");
}

std::tuple<size_t, size_t> Board::getSize() const
{
    return std::make_tuple(size_y, size_x);
}

Board::~Board() = default;

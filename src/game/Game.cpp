/*
** EPITECH PROJECT, 2023
** Gomoku
** File description:
** game file
*/

#include "Game.hpp"
#include <cstddef>
#include <tuple>

Game::Game()
{
    this->commands = std::make_shared<Command>();
    this->board = std::make_shared<Board>(20, 20);
}

Game::Game(size_t size_y, size_t size_x)
{
    this->commands = std::make_shared<Command>();
    this->board = std::make_shared<Board>(size_y, size_x);
}

void Game::setBoard(size_t size_y, size_t size_x)
{
    this->board = std::make_shared<Board>(size_x, size_y);
    this->commands->setBoard(this->board);
}

std::shared_ptr<const Board> Game::getBoard() const
{
    return this->board;
}

void Game::setTile(size_t pos_y, size_t pos_x, Board::Tile tile)
{
    try {
        this->board->setTile(pos_y, pos_x, tile);
    } catch (std::out_of_range &e) {
        std::cout << "Position out of range" << std::endl;
    }
}

Board::Tile Game::getTile(size_t pos_y, size_t pos_x) const
{
    try {
        return this->board->getTile(pos_y, pos_x);
    } catch (std::out_of_range &e) {
        std::cout << "Position out of range" << std::endl;
        return Board::Tile::ERROR;
    }
}

void Game::setCommand(std::shared_ptr<Board> &board)
{
    this->commands->setBoard(board);
}

std::shared_ptr<Command> Game::getCommands() const
{
    return this->commands;
}

std::shared_ptr<Board> Game::getCommandsBoard() const
{
    return this->commands->getBoard();
}

bool Game::checkTiles(size_t pos_y, size_t pos_x, int d_y, int d_x, Board::Tile tile)
{
    size_t count = 0;
    for (size_t i = 0; i < 5; i++) {
        try {
            if (this->board->getTile(pos_y + i * d_y, pos_x + i * d_x) == tile)
                count++;
            else
                break;
        } catch (std::out_of_range &e) {
            break;
        }
    }
    return count == 5;
}

bool Game::checkWinOnTurn(std::tuple<size_t, size_t> pos, Board::Tile tile)
{
    size_t pos_y = std::get<0>(pos);
    size_t pos_x = std::get<1>(pos);
    bool win = false;
    win = win || checkTiles(pos_y, pos_x, 0, 1, tile);
    win = win || checkTiles(pos_y, pos_x, 0, -1, tile);
    win = win || checkTiles(pos_y, pos_x, 1, 0, tile);
    win = win || checkTiles(pos_y, pos_x, -1, 0, tile);
    win = win || checkTiles(pos_y, pos_x, 1, 1, tile);
    win = win || checkTiles(pos_y, pos_x, -1, -1, tile);
    win = win || checkTiles(pos_y, pos_x, 1, -1, tile);
    win = win || checkTiles(pos_y, pos_x, -1, 1, tile);
    return win;
}

std::string Game::toString() const
{
    std::string str;
    for (size_t idx_y = 0; idx_y < std::get<0>(this->board->getSize()); idx_y++) {
        for (size_t idx_x = 0; idx_x < std::get<1>(this->board->getSize()); idx_x++) {
            if (this->board->getTile(idx_y, idx_x) == Board::Tile::EMPTY)
                str += "0";
            else if (this->board->getTile(idx_y, idx_x) == Board::Tile::PLAYER1)
                str += "1";
            else if (this->board->getTile(idx_y, idx_x) == Board::Tile::PLAYER2)
                str += "2";
        }
    }
    return str;
}
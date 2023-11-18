/*
** EPITECH PROJECT, 2023
** gomoku
** File description:
** gomoku file
*/

#include "Gomoku.hpp"
#include <cstddef>
#include <memory>

Gomoku::Gomoku()
{
    this->game = std::make_shared<Game>();
    this->sandbox = std::make_shared<Game>();
    this->monte_carlo = std::make_shared<MonteCarlo>(this->sandbox);
}

Gomoku::Gomoku(size_t size_y, size_t size_x)
{
    this->game = std::make_shared<Game>();
    this->sandbox = std::make_shared<Game>();
    this->monte_carlo = std::make_shared<MonteCarlo>(this->sandbox);
    this->game->setBoard(size_y, size_x);
    this->sandbox->setBoard(size_y, size_x);
}

std::shared_ptr<Game> Gomoku::getGame() const
{
    return this->game;
}

std::shared_ptr<Game> Gomoku::getSandbox() const
{
    return this->sandbox;
}

std::shared_ptr<MonteCarlo> Gomoku::getMonteCarlo() const
{
    return this->monte_carlo;
}

void Gomoku::setTile(size_t pos_y, size_t pos_x, Board::Tile tile)
{
    this->game->setTile(pos_y, pos_x, tile);
    this->sandbox->setTile(pos_y, pos_x, tile);
}
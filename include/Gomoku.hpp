/*
** EPITECH PROJECT, 2023
** AIA_gomoku
** File description:
** Gomoku.hh
*/

#pragma once

#include "Board.hpp"
#include "Command.hpp"
#include "Game.hpp"
#include "MonteCarlo.hpp"
#include <cstddef>
#include <memory>
#include <string>
#include <vector>

class Gomoku
{
    public:
        Gomoku();
        Gomoku(size_t size_y, size_t size_x);
        ~Gomoku() = default;
        std::shared_ptr<Game> getGame() const;
        std::shared_ptr<Game> getSandbox() const;
        std::shared_ptr<MonteCarlo> getMonteCarlo() const;
        void setTile(size_t pos_y, size_t pos_x, Board::Tile tile);

    private:
        std::shared_ptr<Game> game;
        std::shared_ptr<Game> sandbox;
        std::shared_ptr<MonteCarlo> monte_carlo;
};

#define FAILURE 84
#define SUCCESS 0

/*
** EPITECH PROJECT, 2023
** AIA_gomoku
** File description:
** MonteCarlo.cpp
*/

#include "MonteCarlo.hpp"
#include "Board.hpp"
#include <memory>
#include <tuple>

MonteCarlo::MonteCarlo(std::shared_ptr<Game> &sand_box)
{
    setSandBox(sand_box);
}

MonteCarlo::MonteCarlo(const std::shared_ptr<Game> &sand_box, size_t const idx_x,
                       size_t const idx_y)
{
    std::shared_ptr<Game> cp_sand_box = std::make_shared<Game>();
    cp_sand_box->setBoard(std::get<0>(sand_box->getBoard()->getSize()),
                          std::get<1>(sand_box->getBoard()->getSize()));
    for (size_t idx_y = 0; idx_y < std::get<0>(sand_box->getBoard()->getSize()); idx_y++) {
        for (size_t idx_x = 0; idx_x < std::get<1>(sand_box->getBoard()->getSize()); idx_x++) {
            cp_sand_box->setTile(idx_y, idx_x, sand_box->getBoard()->getTile(idx_y, idx_x));
        }
    }
    cp_sand_box->setTile(idx_y, idx_x, Board::PLAYER1);
    this->setSandBox(cp_sand_box);
}

void MonteCarlo::setSandBox(std::shared_ptr<Game> &game)
{
    this->sand_box = game;
}

std::shared_ptr<Game> MonteCarlo::getSandBox() const
{
    return this->sand_box;
}

std::shared_ptr<const Board> MonteCarlo::getBoard() const
{
    return this->sand_box->getBoard();
}

void MonteCarlo::setBoard(std::shared_ptr<Board> &board)
{
    this->sand_box->setBoard(std::get<0>(board->getSize()), std::get<1>(board->getSize()));
}

void MonteCarlo::Expand()
{
    for (size_t idx_y = 0; idx_y < std::get<0>(this->getBoard()->getSize()); idx_y++) {
        for (size_t idx_x = 0; idx_x < std::get<1>(this->getBoard()->getSize()); idx_x++) {
            if (this->getBoard()->getTile(idx_y, idx_x) == Board::Tile::EMPTY) {
                MonteCarlo copy(this->getSandBox(), idx_x, idx_y);
                this->m_node.emplace_back(copy);
            }
        }
    }
}

MonteCarlo MonteCarlo::Select() const
{
    float ucb = 0;
    MonteCarlo ucb_mc = this->m_node[0];
    float c_val = sqrt(2);

    for (const auto &idx : this->m_node) {
        Info tmp = idx.getInfo();
        float uct =
            (tmp.m_nb_win / tmp.m_draw) + c_val * sqrt(log(tmp.m_nb_win + tmp.m_lose) / tmp.m_draw);
        if (uct > ucb) {
            ucb = uct;
            ucb_mc = idx;
        }
    }
    return ucb_mc;
}

[[nodiscard]] Info MonteCarlo::getInfo() const
{
    return this->m_info;
}

std::vector<MonteCarlo> MonteCarlo::getNode() const
{
    return this->m_node;
}
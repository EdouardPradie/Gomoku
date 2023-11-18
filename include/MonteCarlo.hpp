/*
** EPITECH PROJECT, 2023
** AIA_gomoku
** File description:
** MonteCarlo.hh
*/

#pragma once
#include "Board.hpp"
#include "Game.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <valarray>
#include <vector>

struct Info {
        size_t m_nb_win{0};
        size_t m_lose{0};
        size_t m_draw{0};
};

class MonteCarlo
{
    public:
        MonteCarlo() = default;
        MonteCarlo(std::shared_ptr<Game> &sand_box);
        MonteCarlo(const std::shared_ptr<Game> &sand_box, size_t idx_x, size_t idx_y);
        MonteCarlo(MonteCarlo const &to_copy) = default;
        MonteCarlo(MonteCarlo &&to_move) = default;
        ~MonteCarlo() = default;
        MonteCarlo &operator=(MonteCarlo const &to_copy) = default;
        MonteCarlo &operator=(MonteCarlo &&to_move) = default;

        [[nodiscard]] MonteCarlo Select() const;
        void Expand();
        void Rollout();
        void Backpropagation();
        [[nodiscard]] Info getInfo() const;
        std::shared_ptr<const Board> getBoard() const;
        std::shared_ptr<Game> getSandBox() const;
        void setSandBox(std::shared_ptr<Game> &game);
        void setBoard(std::shared_ptr<Board> &board);
        std::vector<MonteCarlo> getNode() const;
        void expandSingleNode(size_t idx_y, size_t idx_x);

    private:
        Info m_info{};
        std::vector<MonteCarlo> m_node{};
        std::shared_ptr<Game> sand_box;
};

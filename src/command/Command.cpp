/*
** EPITECH PROJECT, 2023
** AIA_gomoku
** File description:
** Command
*/

#include "Command.hpp"
#include "Board.hpp"
#include <cstddef>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <sstream>
#include <unordered_map>

void Command::setBoard(std::shared_ptr<Board> &board)
{
    this->board = board;
}

void Command::resetBoard(size_t size_y, size_t size_x)
{
    this->board->setBoard(size_y, size_x);
}

std::shared_ptr<Board> Command::getBoard() const
{
    return this->board;
}

void Command::turnCommand(size_t cord_y, size_t cord_x, Board::Tile tile)
{
    this->board->setTile(cord_y, cord_x, tile);
    //std::cout << cord_x << " " << cord_y << std::endl;
}

void Command::setTile(int cord_y, int cord_x, Board::Tile tile)
{
    this->board->setTile(cord_y, cord_x, tile);
}

void Command::beginCommand(size_t /* null */, size_t /* null2 */, Board::Tile /* null3 */)
{
    std::cout << "BEGIN" << std::endl;
    turnCommand(0, 0, Board::Tile::PLAYER1);
}

void Command::boardCommand(size_t /* size_y */, size_t /* size_x */, Board::Tile /* tile */)
{
    resetBoard();
}

void Command::aboutCommand(size_t /* size_y */, size_t /* size_x */, Board::Tile /* tile */)
{
    std::ifstream file("about.json");
    if (!file) {
        std::cerr << "Unable to open file about.json" << std::endl;
        return;
    }
    std::vector<std::string> lines;
    std::string line;
    std::string name;
    std::string version;
    std::string author;
    std::string country;

    while (std::getline(file, line)) {
        if (line.find("name") != std::string::npos) {
            name = line.substr(line.find(":") + 3);
            name = name.substr(0, name.find_last_of("\""));
        } else if (line.find("version") != std::string::npos) {
            version = line.substr(line.find(":") + 3);
            version = version.substr(0, version.find_last_of("\""));
        } else if (line.find("author") != std::string::npos) {
            author = line.substr(line.find(":") + 3);
            author = author.substr(0, author.find_last_of("\""));
        } else if (line.find("country") != std::string::npos) {
            country = line.substr(line.find(":") + 3);
            country = country.substr(0, country.find_last_of("\""));
        }
    }

    std::cout << "name=\"" + name + "\", version=\"" << version
              << "\", author=\"" + author + "\", country=\"" + country + "\"" << std::endl;
}

void Command::parseCommand(std::vector<std::string> message)
{
    std::unordered_map<std::string, std::function<void(size_t, size_t, Board::Tile)>> commands = {
        {"TURN",
         [this](size_t cord_x, size_t cord_y, Board::Tile tile) {
             this->turnCommand(cord_y, cord_x, tile);
         }},
        {
            "BEGIN",
            [this](size_t cord_x, size_t cord_y, Board::Tile tile) {
                this->beginCommand(cord_x, cord_y, tile);
            },
        },
        {
            "BOARD",
            [this](size_t cord_x, size_t cord_y, Board::Tile tile) {
                this->boardCommand(cord_x, cord_y, tile);
            },
        },
        {
            "ABOUT",
            [this](size_t cord_x, size_t cord_y, Board::Tile tile) {
                this->aboutCommand(cord_x, cord_y, tile);
            },
        },
        //{&Command::setStart, "START"},
        //{&Command::setInfo, "INFO"},
        //{&Command::setEnd, "END"},
        //{&Command::setAbout, "ABOUT"},
    };
    std::string command = message[0];
    auto iterator = commands.find(command);
    if (iterator != commands.end()) {
        if (message.size() == 3) {
            iterator->second(std::stoul(message[1]), std::stoul(message[2]), Board::Tile::PLAYER1);
        } else {
            iterator->second(0, 0, Board::Tile::PLAYER1);
        }
    } else {
        std::cerr << "Unknown command" << std::endl;
    }
}

[[nodiscard]] std::vector<std::string> Command::getMessage()
{
    std::getline(std::cin, this->m_message);
    std::istringstream iss(this->m_message);
    std::vector<std::string> words(std::istream_iterator<std::string>{iss},
                                   std::istream_iterator<std::string>());

    return words;
}

/* void Command::setStart(int size)
{
    std::cout << "START " << size << std::endl;
}

void Command::setTurn(int cord_y, int cord_x)
{
    this->m_cord[0] = cord_y;
    this->m_cord[1] = cord_x;
    std::cout << "TURN " << cord_x << cord_y << std::endl;
}

 void Command::setInfo(std::string key, int value)
{
    std::cout << "INFO " << key << " " << value << std::endl;
}

void Command::setEnd()
{
    std::cout << "END" << std::endl;
}

void Command::setAbout()
{
    std::cout << "ABOUT" << std::endl;
}
*/

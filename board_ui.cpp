#include "board_ui.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;
BoardUI::BoardUI(int x, int y, float size, float padding, float border) {
  this->size = size;
  this->border = border;
  num_cols = x;
  num_lines = y;
  cells = new sf::Vertex[4 * x * y];
  if (!font.loadFromFile("arial.ttf")) {
    cout << "Font Error" << endl;
  }
  numbers = new sf::Text[x * y];
  for (int i = 0; i < num_cols; i++) {
    for (int j = 0; j < num_lines; j++) {
      float top_y = size * j + padding + border;
      float bottom_y = size * (j + 1) - padding + border;
      float left_x = size * i + padding + border;
      float right_x = size * (i + 1) - padding + border;
      cells[4 * (j + num_lines * i)] = sf::Vertex(sf::Vector2f(left_x, top_y));
      cells[4 * (j + num_lines * i) + 1] =
          sf::Vertex(sf::Vector2f(right_x, top_y));
      cells[4 * (j + num_lines * i) + 2] =
          sf::Vertex(sf::Vector2f(right_x, bottom_y));
      cells[4 * (j + num_lines * i) + 3] =
          sf::Vertex(sf::Vector2f(left_x, bottom_y));
    }
  }
  initColor();
}
void BoardUI::setColor(sf::Color color, int x, int y) {
  if (x < 0 || x >= num_cols || y < 0 || y >= num_lines) {
    return;
  }
  cells[4 * (y + num_lines * x)].color = color;
  cells[4 * (y + num_lines * x) + 1].color = color;
  cells[4 * (y + num_lines * x) + 2].color = color;
  cells[4 * (y + num_lines * x) + 3].color = color;
}

void BoardUI::initColor() {
  for (int i = 0; i < num_lines; i++) {
    for (int j = 0; j < num_cols; j++) {
      setColor(sf::Color(128, 128, 128), j, i);
    }
  }
}
void BoardUI::updateColor(vector<vector<char>>& board,
                          sf::Vector2i& mouseCell) {
  for (size_t i = 0; i < board.size(); i++) {
    for (size_t j = 0; j < board[0].size(); j++) {
      switch (board[i][j]) {
        case ' ':
          setColor(sf::Color(128, 128, 128), j, i);
          break;
        case 'x':
          setColor(sf::Color::Red, j, i);
          break;
        case 'F':
          setColor(sf::Color::Green, j, i);
          break;
        default:
          setColor(sf::Color::White, j, i);
      }
      if (board[i][j] == 'x') {
        setColor(sf::Color::Red, j, i);
      }
    }
  }
  // TODO(Wagner): update 'x' -> ' ' when the hidden cells are ready
  if (board[mouseCell.y][mouseCell.x] != 'x') {
    setColor(sf::Color::Yellow, mouseCell.x, mouseCell.y);
  }
}
sf::Vertex* BoardUI::getBoard() { return cells; }
sf::Vector2i BoardUI::getMouseCell(sf::Vector2i& pos) {
  pos.x -= int(border);
  pos.y -= int(border);
  return sf::Vector2i(floor(float(pos.x) / size), floor(pos.y / size));
}
sf::Text* BoardUI::setTextBoard(vector<vector<char>>& charBoard) {
  for (int i = 0; i < num_cols; i++) {
    for (int j = 0; j < num_lines; j++) {
      float top_y = size * j + (3 * size) / 4;
      float left_x = size * i + size + 8;
      numbers[j + num_lines * i] = sf::Text(charBoard[j][i], font, 50);
      numbers[j + num_lines * i].setPosition(left_x, top_y);
      numbers[j + num_lines * i].setFillColor(sf::Color::Black);
    }
  }
  return numbers;
}
#include "board_ui.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

// Define UI layout
const float BoardUI::size = 60.f;
const float BoardUI::padding = 2.f;
const float BoardUI::border = 50.f;

BoardUI::BoardUI(int cols, int lines) {
  this->cols = cols;
  this->lines = lines;

  vertices = new sf::Vertex[4 * cols * lines];
  numbers = new sf::Text[cols * lines];

  if (!font.loadFromFile("arial.ttf")) {
    cout << "Font Error" << endl;
  }

  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < lines; j++) {
      float top_y = size * j + padding + border;
      float bottom_y = size * (j + 1) - padding + border;
      float left_x = size * i + padding + border;
      float right_x = size * (i + 1) - padding + border;
      vertices[4 * (j + lines * i)] = sf::Vertex(sf::Vector2f(left_x, top_y));
      vertices[4 * (j + lines * i) + 1] =
          sf::Vertex(sf::Vector2f(right_x, top_y));
      vertices[4 * (j + lines * i) + 2] =
          sf::Vertex(sf::Vector2f(right_x, bottom_y));
      vertices[4 * (j + lines * i) + 3] =
          sf::Vertex(sf::Vector2f(left_x, bottom_y));
    }
  }
  initColor();
}
void BoardUI::setColor(sf::Color color, int col, int line) {
  if (col < 0 || col >= cols || line < 0 || line >= lines) {
    return;
  }
  vertices[4 * (line + lines * col)].color = color;
  vertices[4 * (line + lines * col) + 1].color = color;
  vertices[4 * (line + lines * col) + 2].color = color;
  vertices[4 * (line + lines * col) + 3].color = color;
}
sf::Vector2i BoardUI::getWindowSize() {
  return sf::Vector2i(size * cols + 2 * border, size * lines + 2 * border);
}

void BoardUI::initColor() {
  for (int i = 0; i < lines; i++) {
    for (int j = 0; j < cols; j++) {
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
sf::Vertex* BoardUI::getTiles() { return vertices; }
sf::Vector2i BoardUI::getMouseCell(sf::Vector2i& pos) {
  pos.x -= int(border);
  pos.y -= int(border);
  return sf::Vector2i(floor(float(pos.x) / size), floor(pos.y / size));
}
sf::Text* BoardUI::setTextBoard(vector<vector<char>>& charBoard) {
  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < lines; j++) {
      float top_y = size * j + (3 * size) / 4;
      float left_x = size * i + size + 8;
      numbers[j + lines * i] = sf::Text(charBoard[j][i], font, 50);
      numbers[j + lines * i].setPosition(left_x, top_y);
      numbers[j + lines * i].setFillColor(sf::Color::Black);
    }
  }
  return numbers;
}
//#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
#include "board.hpp"
#include "board_ui.hpp"
using namespace std;
int main() {
  int num_cols = 30, num_lines = 18;
  float cell_size = 60.f, padding = 2.f, border = 50.f;
  Board board(num_cols, num_lines, 60);

  sf::RenderWindow window(sf::VideoMode(cell_size * num_cols + 2 * border,
                                        cell_size * num_lines + 2 * border),
                          "Mine game!");
  // window.setFramerateLimit(30);
  BoardUI boardUI = BoardUI(num_cols, num_lines, cell_size, padding, border);
  while (window.isOpen()) {
    auto cb = board.charBoard();
    auto mouse_pos = sf::Mouse::getPosition(window);
    auto cell_pos = boardUI.getMouseCell(mouse_pos);
    if (board.onBound(cell_pos.x, cell_pos.y) &&
        cb[cell_pos.y][cell_pos.x] != ' ') {
      boardUI.setColor(sf::Color::Red, cell_pos.x, cell_pos.y);
    }
    for (int i = 0; i < num_lines; i++) {
      for (int j = 0; j < num_cols; j++) {
        if (cb[i][j] == '*') {
          boardUI.setColor(sf::Color::Yellow, j, i);
        }
      }
    }
    auto b = boardUI.getBoard();
    auto tb = boardUI.setTextBoard(cb);
    window.clear();
    window.draw(b, 4 * num_lines * num_cols, sf::Quads);

    for (int i = 0; i < num_lines * num_cols; ++i) {
      window.draw(tb[i]);
    }
    window.display();

    boardUI.setColor(sf::Color::White, cell_pos.x, cell_pos.y);

    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      } else if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
          board.discoverCell(cell_pos.x, cell_pos.y);
        } else if (event.mouseButton.button == sf::Mouse::Right) {
          board.flagToggle(cell_pos.x, cell_pos.y);
        }
      }
    }
  }

  return 0;
}
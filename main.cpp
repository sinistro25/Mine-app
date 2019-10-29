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
  BoardUI boardUI = BoardUI(num_cols, num_lines, cell_size, padding, border);

  sf::RenderWindow window(sf::VideoMode(cell_size * num_cols + 2 * border,
                                        cell_size * num_lines + 2 * border),
                          "Mine game!");

  window.setFramerateLimit(30);
  while (window.isOpen()) {
    auto cb = board.charBoard();
    auto mousePos = sf::Mouse::getPosition(window);
    sf::Vector2i mouseCell = boardUI.getMouseCell(mousePos);
    if (board.onBound(mouseCell.x, mouseCell.y)) {
      boardUI.updateColor(cb, mouseCell);
    }
    auto b = boardUI.getBoard();
    auto tb = boardUI.setTextBoard(cb);
    window.clear();
    window.draw(b, 4 * num_lines * num_cols, sf::Quads);

    for (int i = 0; i < num_lines * num_cols; ++i) {
      window.draw(tb[i]);
    }
    window.display();

    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      } else if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
          board.discoverCell(mouseCell);
        } else if (event.mouseButton.button == sf::Mouse::Right) {
          board.flagToggle(mouseCell);
        }
      }
    }
  }

  return 0;
}
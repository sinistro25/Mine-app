#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <thread>
#include "table_ui.hpp"
int main() {
  float cell_size = 120.f, padding = 2.f, border = 50.f;
  int num_cols = 11, num_lines = 10;

  sf::RenderWindow window(sf::VideoMode(cell_size * num_cols + 2 * border,
                                        cell_size * num_lines + 2 * border),
                          "Mine game!");
  window.setFramerateLimit(30);
  BoardUI board = BoardUI(num_cols, num_lines, cell_size, padding, border);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }

    auto mouse_pos = sf::Mouse::getPosition(window);
    auto cell_pos = board.getMouseCell(mouse_pos);

    board.set_color(sf::Color::Red, cell_pos.x, cell_pos.y);
    auto b = board.get_board();
    window.clear();
    window.draw(b, 4 * num_lines * num_cols, sf::Quads);
    window.display();

    board.set_color(sf::Color::White, cell_pos.x, cell_pos.y);
  }

  return 0;
}
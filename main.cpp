#include <SFML/Graphics.hpp>
#include <iostream>
#include "table_ui.hpp"
int main() {
  float cell_size = 60.f, padding = 2.f, border = 50.f;
  int num_cols = 20, num_lines = 20;

  sf::RenderWindow window(sf::VideoMode(cell_size * num_cols + 2 * border,
                                        cell_size * num_lines + 2 * border),
                          "Mine game!");
  BoardUI board = BoardUI(num_lines, num_cols, cell_size, padding, border);
  board.set_color(sf::Color::Red, 5, 3);
  auto b = board.get_board();
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }

    window.clear();
    window.draw(b);
    window.display();
  }

  return 0;
}
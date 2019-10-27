#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
<<<<<<< HEAD
#include <vector>
using namespace std;
struct cell {
  int neighbombs;
  bool bomb;
  bool Flag;
};
class Board {
 private:
  vector<vector<cell>> table;
  int x, y, bombs;

 public:
  Board(int x_val = 10, int y_val = 10, int bombs_val = 10);
  void Print_board();
};

ostream &operator<<(ostream &os, cell const &b) {
  char c = (b.bomb) ? '*' : 'o';
  return os << c;
}
Board::Board(int x_val, int y_val, int bombs_val)
    : x{x_val}, y{y_val}, bombs{bombs_val} {
  table = vector<vector<cell>>(y_val);
  for (int i = 0; i < y_val; i++) {
    table[i] = vector<cell>(x_val);
  }
}

void Board::Print_board() {
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      cout << table[i][j] << " ";
    }
    cout << endl;
  }
}
int main() {
  Board b;
  b.Print_board();
=======
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

>>>>>>> 8d85415a5fe1499bfcda2712138744d7879c9215
  return 0;
}
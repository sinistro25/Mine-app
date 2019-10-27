#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
using namespace std;
class BoardUI {
 private:
  int num_cols, num_lines;
  float size;
  float border;

 public:
  sf::Vertex* cells;
  BoardUI(int x, int y, float size, float padding = 2.f, float border = 50.f);
  void set_color(sf::Color color, int x, int y);
  sf::Vertex* get_board();
  sf::Vector2i getMouseCell(sf::Vector2i& pos);
};
BoardUI::BoardUI(int x, int y, float size, float padding, float border) {
  this->size = size;
  this->border = border;
  num_cols = x;
  num_lines = y;
  cells = new sf::Vertex[4 * x * y];
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
}
void BoardUI::set_color(sf::Color color, int x, int y) {
  std::cout << x << endl;
  if (x < 0 || x >= num_cols || y < 0 || y >= num_lines) {
    return;
  }
  cells[4 * (y + num_lines * x)].color = color;
  cells[4 * (y + num_lines * x) + 1].color = color;
  cells[4 * (y + num_lines * x) + 2].color = color;
  cells[4 * (y + num_lines * x) + 3].color = color;
}
sf::Vertex* BoardUI::get_board() { return cells; }
sf::Vector2i BoardUI::getMouseCell(sf::Vector2i& pos) {
  pos.x -= int(border);
  pos.y -= int(border);
  return sf::Vector2i(floor(float(pos.x) / size), floor(pos.y / size));
}
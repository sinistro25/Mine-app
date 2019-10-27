#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
class BoardUI {
 private:
  int size_x, size_y;

 public:
  sf::VertexArray cells;
  BoardUI(int x, int y, float size, float padding = 2.f, float border = 50.f);
  void set_color(sf::Color color, int x, int y);
  sf::VertexArray get_board();
};
BoardUI::BoardUI(int x, int y, float size, float padding, float border) {
  size_x = x;
  size_y = y;
  cells = sf::VertexArray(sf::Quads, 4 * x * y);
  cout << cells.getVertexCount() << endl;
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      float top_y = size * i + padding + border;
      float bottom_y = size * (i + 1) - padding + border;
      float left_x = size * j + padding + border;
      float right_x = size * (j + 1) - padding + border;

      cells[4 * (i + x * j)].position = sf::Vector2f(left_x, top_y);
      cells[4 * (i + x * j) + 1].position = sf::Vector2f(right_x, top_y);
      cells[4 * (i + x * j) + 2].position = sf::Vector2f(right_x, bottom_y);
      cells[4 * (i + x * j) + 3].position = sf::Vector2f(left_x, bottom_y);
    }
  }
}
void BoardUI::set_color(sf::Color color, int x, int y) {
  cout << size_x << " " << size_y << endl;
  cells[4 * (x + size_x * y)].color = color;
  cells[4 * (x + size_x * y) + 1].color = color;
  cells[4 * (x + size_x * y) + 2].color = color;
  cells[4 * (x + size_x * y) + 3].color = color;
}
sf::VertexArray BoardUI::get_board() {
  cout << cells.getVertexCount() << endl;
  return cells;
}
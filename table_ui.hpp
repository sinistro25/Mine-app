#ifndef TABLE_UI_H_
#define TABLE_UI_H_
#include <SFML/Graphics.hpp>
class BoardUI {
 public:
  sf::VertexArray cells;
  BoardUI(int x, int y, float size, float padding = 2.f, float border = 50.f);
  void set_color(sf::Color color, int x, int y);
  sf::VertexArray get_board();
};
#endif
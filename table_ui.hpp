#ifndef TABLE_UI_H_
#define TABLE_UI_H_
#include <SFML/Graphics.hpp>
#include <vector>
class BoardUI {
  int num_cols, num_lines;
  float size;
  float border;
  sf::VertexArray cells;
  sf::Text* numbers;
  sf::Font font;

 public:
  BoardUI(int x, int y, float size, float padding = 2.f, float border = 50.f);
  void set_color(sf::Color color, int x, int y);
  sf::Vertex* get_board();
  sf::Vector2i getMouseCell(sf::Vector2i& pos);
  sf::Text* setTextBoard(vector<vector<char>>& charBoard);
};
#endif
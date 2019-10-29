#ifndef TABLE_UI_H_
#define TABLE_UI_H_
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
class BoardUI {
  int num_cols, num_lines;
  float size;
  float border;
  sf::Vertex* cells;
  sf::Text* numbers;
  sf::Font font;
  void setColor(sf::Color color, int x, int y);
  void initColor();

 public:
  BoardUI(int x, int y, float size, float padding = 2.f, float border = 50.f);
  sf::Vertex* getTiles();
  sf::Vector2i getMouseCell(sf::Vector2i& pos);
  sf::Text* setTextBoard(vector<vector<char>>& charBoard);
  void updateColor(vector<vector<char>>& board, sf::Vector2i& mousePos);
};
#endif
#ifndef TABLE_UI_H_
#define TABLE_UI_H_
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
class BoardUI {
  static const float size;
  static const float padding;
  static const float border;
  int cols, lines;
  sf::Vertex* cells;
  sf::Text* numbers;
  sf::Font font;
  void setColor(sf::Color color, int x, int y);
  void initColor();

 public:
  BoardUI(int cols, int lines);
  sf::Vertex* getTiles();
  sf::Vector2i getMouseCell(sf::Vector2i& pos);
  sf::Text* setTextBoard(vector<vector<char>>& charBoard);
  void updateColor(vector<vector<char>>& board, sf::Vector2i& mousePos);
};
#endif
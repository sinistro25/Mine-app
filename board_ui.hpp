#ifndef TABLE_UI_H_
#define TABLE_UI_H_
#include <SFML/Graphics.hpp>
#include <ctime>
#include <vector>
using namespace std;
class BoardUI {
  static const float size;
  static const float padding;
  static const float border;
  static const int fontSize;
  static const time_t maxTime;
  int cols, lines;
  sf::Vertex* vertices;
  sf::Text* numbers;
  sf::Text timer;
  sf::Text result;
  sf::Font font;
  void setColor(sf::Color color, int x, int y);
  void initColor();
  void centerTextOrigin(sf::Text& text);

 public:
  static const sf::Vector2i noMouseCell;
  BoardUI(int cols, int lines);
  sf::Vector2i getWindowSize();
  sf::Vertex* getTiles();
  sf::Vector2i getMouseCell(sf::Vector2i& pos);
  sf::Text* setTextBoard(vector<vector<char>>& charBoard);
  sf::Text getTimerText(time_t t);
  sf::Text getResultText(bool won);
  void updateColor(vector<vector<char>>& board, const sf::Vector2i& mousePos);
};
#endif
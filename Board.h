#ifndef BOARD_H_
#define BOARD_H_
#include <vector>
using namespace std;
struct Cell {
  int neighbombs;
  bool bomb;
  bool flag;
};
class Board {
 private:
  int x, y, bombs;
  vector<vector<Cell>> table;
  void addBombs(int n);

 public:
  Board(int x_val = 10, int y_val = 10, int bombs_val = 10);
  vector<vector<char>> charBoard();
  bool onBound(int x, int y);
  void fillCell();
};
#endif
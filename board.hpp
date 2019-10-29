#ifndef BOARD_H_
#define BOARD_H_
#include <vector>
using namespace std;
// TODO(paula): Create flag to indicate that the cell
// is hidden and change default constructor to initialize
// the necessary values with the right value
struct Cell {
  int neighbombs;
  bool bomb;
  bool flag;
};
// TODO(Paula): Define properties to indicate that the game is over, if the
// player won or lost
class Board {
 private:
  int x, y, bombs;
  vector<vector<Cell>> table;
  void addBombs(int n);

 public:
  Board(int x_val = 10, int y_val = 10, int bombs_val = 10);
  vector<vector<char>> charBoard();
  bool onBound(int x, int y);
  void discoverCell(int x, int y);
  void flagToggle(int x, int y);
  void setNeighbombs();
};
#endif
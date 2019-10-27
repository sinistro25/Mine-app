#ifndef BOARD_H_
#define BOARD_H_
#include <vector>
using namespace std;
struct cell {
  int neighbombs;
  bool bomb;
  bool Flag;
  cell() {
    neighbombs = 0;
    bomb = false;
    Flag = false;
  }
};
class Board {
 public:
  int x, y, bombs;
  vector<vector<cell>> table;
  void Add_bombs(int n);

  Board(int x_val = 10, int y_val = 10, int bombs_val = 10);
  vector<vector<char>> char_board();
};
#endif
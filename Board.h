#ifndef BOARD_H_
#define BOARD_H_

using namespace std;
struct cell {
  int neighbombs;
  bool bomb;
  bool Flag;
};
class Board {
 public:
  Board(int x_val = 10, int y_val = 10, int bombs_val = 10);
  void Print_board();
};
#endif
#include <iostream>
#include <vector>
using namespace std;
struct cell {
  int neighbombs;
  bool bomb;
  bool Flag;
};
class Board {
 private:
  vector<vector<cell>> table;
  int x, y, bombs;

 public:
  Board(int x_val = 10, int y_val = 10, int bombs_val = 10);
  void Print_board();
};

ostream &operator<<(ostream &os, cell const &b) {
  char c = (b.bomb) ? '*' : 'o';
  return os << c;
}
Board::Board(int x_val, int y_val, int bombs_val)
    : x{x_val}, y{y_val}, bombs{bombs_val} {
  table = vector<vector<cell>>(y_val);
  for (int i = 0; i < y_val; i++) {
    table[i] = vector<cell>(x_val);
  }
}

void Board::Print_board() {
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      cout << table[i][j] << " ";
    }
    cout << endl;
  }
}
int main() {
  Board b;
  b.Print_board();
  return 0;
}
#include "Board.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

ostream &operator<<(ostream &os, cell const &b) {
  char c = (b.bomb) ? '*' : 'o';
  return os << c;
}
Board::Board(int x_val, int y_val, int bombs_val)
    : x{x_val}, y{y_val}, bombs{bombs_val} {
  table = vector<vector<cell>>();
  for (int i = 0; i < y_val; i++) {
    table.push_back(vector<cell>());
    for (int j = 0; j < x_val; j++) {
      cell c;
      table[i].push_back(c);
    }
  }
  Add_bombs(bombs);
}

vector<vector<char>> Board::char_board() {
  vector<vector<char>> b(y, vector<char>(x, '_'));
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      if (table[i][j].bomb) {
        b[i][j] = '*';
      }
    }
  }
  return b;
}

void Board::Add_bombs(int n) {
  vector<bool> v(n, true);
  v.resize(y * x, false);
  random_shuffle(v.begin(), v.end());
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      table[i][j].bomb = v[i * x + j];
    }
  }
}

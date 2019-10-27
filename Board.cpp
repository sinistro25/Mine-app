#include "Board.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

ostream &operator<<(ostream &os, Cell const &b) {
  char c = (b.bomb) ? '*' : 'o';
  return os << c;
}
Board::Board(int x_val, int y_val, int bombs_val)
    : x{x_val}, y{y_val}, bombs{bombs_val} {
  table = vector<vector<Cell>>();
  for (int i = 0; i < y_val; i++) {
    table.push_back(vector<Cell>());
    for (int j = 0; j < x_val; j++) {
      Cell c;
      table[i].push_back(c);
    }
  }
  addBombs(bombs);
}

vector<vector<char>> Board::charBoard() {
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

void Board::addBombs(int n) {
  vector<bool> v(n, true);
  v.resize(y * x, false);
  random_shuffle(v.begin(), v.end());
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      table[i][j].bomb = v[i * x + j];
    }
  }
}
#include "board.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

Cell::Cell() : isHidden(true) {}
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
  rBlankCells = x * y - bombs;
  setNeighbombs();
}

vector<vector<char>> Board::charBoard() {
  vector<vector<char>> b(y, vector<char>(x, ' '));
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      if (table[i][j].flag) {
        b[i][j] = 'F';
      } else if (table[i][j].isHidden) {
        b[i][j] = ' ';
      } else if (table[i][j].bomb) {
        b[i][j] = 'X';
      } else {
        b[i][j] = char('0' + table[i][j].neighbombs);
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

bool Board::onBound(int x, int y) {
  return !(x < 0 || x >= this->x || y < 0 || y >= this->y);
}
void Board::setNeighbombs() {
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      for (int k = i - 1; k <= i + 1; k++) {
        for (int p = j - 1; p <= j + 1; p++) {
          if (!onBound(p, k) || (p == j && k == i)) {
            continue;
          }
          if (table[k][p].bomb) {
            table[i][j].neighbombs++;
          }
        }
      }
    }
  }
}

void Board::discoverCell(sf::Vector2i &cell) {
  int x = cell.x;
  int y = cell.y;
  if (onBound(x, y) && !table[y][x].flag) {
    table[y][x].isHidden = false;
    if (table[y][x].bomb) {
      gameOver = true;
    } else {
      rBlankCells--;
      if (!rBlankCells) {
        gameOver = true;
      }
    }
  }
  // TODO(Paula): Game ends when discover all blank cells.

  // TODO(Paula) - HARD leave for last: If you discover a cell with
  // 0 neighbombs you have to open all neighbors cells with also 0
  // neighbombs, there is a direct way to implement it. You might
  // want to search for flood fill to get the idea.
}

void Board::flagToggle(sf::Vector2i &cell) {
  int x = cell.x;
  int y = cell.y;
  if (onBound(x, y) && table[y][x].isHidden) {
    table[y][x].flag = !table[y][x].flag;
  }
}

bool Board::isGameOver() { return gameOver; }

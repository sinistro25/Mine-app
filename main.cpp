#include <SFML/Graphics.hpp>
#include <chrono>
#include <ctime>
#include <iostream>
#include <thread>
#include <vector>
#include "board.hpp"
#include "board_ui.hpp"
using namespace std;

int main(int argc, char** argv) {
  srand(time(NULL));
  int cols = 2, lines = 2, bombs = 3;
  // create function to handle user input
  if (argc == 2) {
    lines = cols = atoi(argv[1]);
    bombs = lines * cols / 10 + 1;
  } else if (argc == 3) {
    lines = atoi(argv[1]);
    cols = atoi(argv[2]);
    bombs = lines * cols / 10 + 1;
  } else if (argc > 3) {
    lines = atoi(argv[1]);
    cols = atoi(argv[2]);
    bombs = atoi(argv[3]);
  }

  // init game logic and UI
  Board board(cols, lines, bombs);
  BoardUI boardUI = BoardUI(cols, lines);
  // init window
  auto ws = boardUI.getWindowSize();
  sf::RenderWindow window(sf::VideoMode(ws.x, ws.y), "Mine game!");
  // init timer and set FPS
  auto t0 = time(0);
  window.setFramerateLimit(120);

  // TODO(wagner): proper clean up of the window when the game is over
  // TODO(wagber): make the gameOver screen
  while (!board.isGameOver() && window.isOpen()) {
    auto t = time(0) - t0;
    auto timer = boardUI.getTimerText(t);
    auto cb = board.charBoard();
    auto tb = boardUI.setTextBoard(cb);

    auto m = sf::Mouse::getPosition(window);
    sf::Vector2i mCell = boardUI.getMouseCell(m);

    if (board.onBound(mCell.x, mCell.y)) {
      boardUI.updateColor(cb, mCell);
    }

    window.clear();
    window.draw(timer);
    window.draw(boardUI.getTiles(), 4 * lines * cols, sf::Quads);
    for (int i = 0; i < lines * cols; ++i) {
      window.draw(tb[i]);
    }
    window.display();

    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      } else if (event.type == sf::Event::MouseButtonPressed) {
        switch (event.mouseButton.button) {
          case sf::Mouse::Left:
            board.discoverCell(mCell);
            break;
          case sf::Mouse::Right:
            board.flagToggle(mCell);
            break;
          default:
            break;
        }
      }
    }
  }
  if (board.won()) {
    cout << "WINNER" << endl;
  } else {
    cout << "LOSER" << endl;
  }

  return 0;
}
#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(600, 600), "Mine game!");
  sf::CircleShape circle(200.f, 30);
  circle.setOrigin(200.f, 200.f);
  circle.setPosition(300, 300);
  circle.setFillColor(sf::Color::Green);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }

    window.clear();
    window.draw(circle);
    window.display();
  }

  return 0;
}
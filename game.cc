#include <iostream>
#include "SFML/Graphics.hpp"

class Game
{
public:
  Game();
  /// Run the game loop
  void run();

private:
  /// Get the player inputs
  void process_events();
  /// Update the game state
  void update(sf::Time delta);
  /// Render the view
  void render();

private: //Key press actions
  void handle_keypress_event(sf::Keyboard::Key key, bool is_pressed);

private:
  sf::RenderWindow window_;
  sf::CircleShape  player_;

  //directions
  bool is_moving_up_    = false;
  bool is_moving_down_  = false;
  bool is_moving_left_  = false;
  bool is_moving_right_ = false;
};

Game::Game()
  : window_(sf::VideoMode{640, 480}, "My Game")
  , player_()
{
  player_.setRadius(40.f);
  player_.setPosition(100.f, 100.f);
  player_.setFillColor(sf::Color::Blue);
}


void Game::run()
{
  sf::Clock clock;
  while (window_.isOpen()) {
    sf::Time delta = clock.restart();
    process_events();
    update(delta);
    render();
  }
  return;
}

void Game::process_events()
{
  sf::Event event;
  while (window_.pollEvent(event)) {

    switch (event.type)
    {
      case sf::Event::Closed:
      {
        window_.close();
        break;
      }
      case sf::Event::KeyPressed:
      {
        handle_keypress_event(event.key.code, true);
        break;
      }
      case sf::Event::KeyReleased:
      {
        handle_keypress_event(event.key.code, false);
        break;
      };
      default:
        continue;
    };

    if (event.type == sf::Event::Closed) {
      window_.close();
    }
  }
  return;
}

void Game::update(sf::Time delta)
{
  sf::Vector2f movement{0.f, 0.f};

  static const float speed = 50.f;

  if (is_moving_up_) {
    movement.y -= speed;
  }

  if (is_moving_down_) {
    movement.y += speed;
  }

  if (is_moving_left_) {
    movement.x -= speed;
  }

  if (is_moving_right_) {
    movement.x += speed;
  }

  player_.move(movement * delta.asSeconds());

  return;
}

void Game::render()
{
  window_.clear();
  window_.draw(player_);
  window_.display();
  return;
}


void Game::handle_keypress_event(sf::Keyboard::Key key, bool is_pressed)
{
  switch (key) {
  case sf::Keyboard::W:
    is_moving_up_ = is_pressed;
    break;
  case sf::Keyboard::S:
    is_moving_down_ = is_pressed;
    break;
  case sf::Keyboard::A:
    is_moving_left_ = is_pressed;
    break;
  case sf::Keyboard::D:
    is_moving_right_ = is_pressed;
    break;
  default:
    break;
  };

  return;
}



int main() {
  Game game;
  game.run();
  return 0;
}

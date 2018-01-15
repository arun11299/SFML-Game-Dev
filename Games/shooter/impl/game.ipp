#ifndef GAME_IPP
#define GAME_IPP

#include <cassert>
#include "SFML/Graphics.hpp"

namespace arnml {

Game::Game()
  : window_(sf::VideoMode{640, 480}, "My Game")
{
}

template <typename Resource, typename ResourceID, typename ResourceLoader>
void Game::create_entity(ResourceID id, ResourceLoader& loader)
{
  assert (!entity_);
  entity_.reset(new Resource{id, loader});
  entity_->setPosition(100.f, 100.f);
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
    switch (event.type) {
    case sf::Event::Closed:
      window_.close();
      break;
    case sf::Event::KeyPressed:
      handle_key_press(event.key.code, true/*key_pressed*/);
      break;
    case sf::Event::KeyReleased:
      handle_key_press(event.key.code, false/*key released*/);
      break;
    default:
      continue;
    };
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
  if (is_moving_right_) {
    movement.x += speed;
  }
  if (is_moving_left_) {
    movement.x -= speed;
  }

  entity_->set_velocity(movement);
  entity_->update(delta);
  return;
}

void Game::render()
{
  window_.clear();
  window_.draw(*entity_);
  window_.display();
  return;
}

void Game::handle_key_press(sf::Keyboard::Key key, bool key_pressed)
{
  switch (key) {
  case sf::Keyboard::W:
  case sf::Keyboard::Up: 
    is_moving_up_ = key_pressed;
    break;
  case sf::Keyboard::S:
  case sf::Keyboard::Down:
    is_moving_down_ = key_pressed;
    break;
  case sf::Keyboard::D:
  case sf::Keyboard::Right:
    is_moving_right_ = key_pressed;
    break;
  case sf::Keyboard::A:
  case sf::Keyboard::Left:
    is_moving_left_ = key_pressed;
    break;
  default:
    break;
  };
  return;
}

} // END namespace arnml

#endif

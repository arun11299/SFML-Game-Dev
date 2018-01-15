#include "game.hpp"
#include "entity.hpp"
#include "aircraft.hpp"
#include "resource_holder.hpp"
#include "resource_identifiers.hpp"

using namespace arnml;

int main() {
  ResourceHolder<sf::Texture, textures::ID> texture_holder;
  texture_holder.load_resource(textures::ID::Eagle, "./images/Eagle.png");
  texture_holder.load_resource(textures::ID::Desert, "./images/Desert.png");
  texture_holder.load_resource(textures::ID::Raptor, "./images/Raptor.png");

  Game game;
  game.create_entity<Aircraft>(textures::ID::Eagle, texture_holder);
  game.run();

  return 0;
}

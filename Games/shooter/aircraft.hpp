#ifndef AIRCRAFT_HPP
#define AIRCRAFT_HPP

#include "entity.hpp"
#include "SFML/Graphics.hpp"

namespace arnml {

/**
 */
class Aircraft: public Entity
{
public:
  /**
   */
  enum class type
  {
    Eagle,
    Raptor,
  };

  explicit Aircraft(Aircraft::type type)
    : type_(type)
  {
  }

  Aircraft(const Aircraft& other) = default;
  Aircraft& operator=(const Aircraft& other) = default;

  ~Aircraft() = default;

public:
  /**
   */
  virtual void draw_current(sf::RenderTarget& target,
                            sf::RenderStates states) const override
  {
    target.draw(states);
  }

private:
  /// Type of aircraft
  Aircraft::type type_;
  ///
  sf::Sprite aircraft_;
};

} // END namespace arnml

#endif

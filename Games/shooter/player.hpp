#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "command.hpp"
#include "SFML/Graphics.hpp"

namespace arnml {

/**
 * A player class for handling
 * inputs.
 * Abstracts the input handling from the game processing
 * loop in game
 */
class Player
{
public:
  ///
  Player() = default;
  ~Player() = default;
public:
  /**
   * Handles event for a player.
   */
  void handle_event(sf::Event event, CommandQueue& cmd_q);

  /**
   * Handle real time inputs for a player
   */
  void handle_realtime_input(CommandQueue& cmd_q);
};

} // END namespace arnml

#endif

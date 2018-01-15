#ifndef SPRITE_NODE_HPP
#define SPRITE_NODE_HPP

#include "scene_graph.hpp"

namespace arnml {

/**
 */
class SpriteNode : public SceneNode
{
public:
  /**
   */
  template <typename ResourceID, typename ResourceLoader>
  explicit SpriteNode(ResourceID id, ResourceLoader& loader)
  {
    auto& resource = loader.get(id);
    background_sprite_.setTexture(resource);
  }

  SpriteNode(const SpriteNode& other) = delete;
  SpriteNode& operator=(const SpriteNode& other) = delete;

  ~SpriteNode() = default;

public:
  ///
  void draw_current(sf::RenderTarget& target, sf::RenderStates states) const override
  {
    target.draw(background_sprite_, states);
  }

  ///
  void update_current(sf::Time dt) override
  {
    (void)dt;
  }

private:
  /// Background
  sf::Sprite background_sprite_;
};

}

#endif
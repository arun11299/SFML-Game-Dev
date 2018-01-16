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
  explicit SpriteNode(ResourceID id, ResourceLoader& loader, bool repeat=false)
  {
    auto& resource = loader.get(id);
    if (repeat) {
      resource.setRepeated(true);
    }
    background_sprite_.setTexture(resource);
  }

  template <typename ResourceID, typename ResourceLoader>
  explicit SpriteNode(ResourceID id, ResourceLoader& loader, sf::IntRect& rect, bool repeat=false)
  {
    auto& resource = loader.get(id);
    if (repeat) {
      resource.setRepeated(true);
    }
    background_sprite_.setTexture(resource);
    background_sprite_.setTextureRect(rect);
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

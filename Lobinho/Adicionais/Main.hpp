struct Entity;

void setSize(sf::Sprite& sprite, int width, int height);
void moveEntity(sf::Keyboard::Key key, Entity& entity, std::vector<sf::Keyboard::Key> move_keys);
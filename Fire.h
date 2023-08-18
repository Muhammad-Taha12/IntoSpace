#include <SFML/Graphics.hpp>

using namespace sf;


class Live_add
{
public:
	Live_add( int x, int y, double speed) {
    texture.loadFromFile("img/PNG/Power-ups/powerupBlue_star.png");
    m_sprite.setTexture(texture);
    m_sprite.setPosition(x, y);
    m_speed = speed;
}

	Live_add()
	{}
// Update the position of the danger object
void up(float deltaTime) {
    m_sprite.move(0.0f, m_speed * deltaTime);
}

// Check if the danger object has collided with the player
bool checkColl(sf::FloatRect playerBounds) {
    return m_sprite.getGlobalBounds().intersects(playerBounds);
}

sf::Sprite m_sprite;
    sf::Texture texture;
    float m_speed;

};


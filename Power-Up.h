#include <SFML/Graphics.hpp>

using namespace sf;

class Powerup {
public:
    // Constructor
    Powerup(float x, float y)
    {
        tex.loadFromFile("img/PNG/Lasers/Power-ups/powerupBlue_shield.png");	
        sprte.setPosition(x, y);
        sprte.setOrigin(sprte.getLocalBounds().width / 2.0f, sprte.getLocalBounds().height / 2.0f);
    }

    // Update the powerup state (e.g. movement, collision detection, etc.)
    void update(float deltaTime) {
        // Move the powerup downwards
        float speed = 100.0f;
        sprte.move(0.0f, speed * deltaTime);
    }

    // Draw the powerup sprite on the screen
    void draw(sf::RenderWindow& window) {
        window.draw(sprte);
    }

    // Get the global bounding box of the powerup sprite
    sf::FloatRect getGlobalBounds() const {
        return sprte.getGlobalBounds();
    }

protected:
    sf::Sprite sprte;
    sf::Texture tex;
};

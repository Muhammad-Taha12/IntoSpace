#include <SFML/Graphics.hpp>

class Danger {
public:
    // Constructor
    Danger( int x, int y, double speed);
    
    Danger( )
    {}	

    // Update the position of the danger object
    void update(float deltaTime);

    // Check if the danger object has collided with the player
    bool checkCollision(sf::FloatRect playerBounds);

    // Draw the danger object to the render window
    void draw(sf::RenderWindow& window);


    sf::Sprite m_sprite;
    sf::Texture texture;
    float m_speed;
    int X,Y;
    
       int getX()
{return m_sprite.getPosition().x;}

int getY()
{return m_sprite.getPosition().y;}
};

// Constructor
Danger::Danger( int x, int y, double speed) {
    texture.loadFromFile("img/PNG/Meteors/meteorGrey_big4.png");
    m_sprite.setTexture(texture);
    m_sprite.setPosition(x, y);
    m_speed = speed;
}

// Update the position of the danger object
void Danger::update(float deltaTime) {
    m_sprite.move(0.0f, m_speed * deltaTime);
}

// Check if the danger object has collided with the player
bool Danger::checkCollision(sf::FloatRect playerBounds) {
    return m_sprite.getGlobalBounds().intersects(playerBounds);
}



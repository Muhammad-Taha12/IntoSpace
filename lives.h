#include <SFML/Graphics.hpp>

class Lives {
public:
    Lives(int startingLives, int x,int y, float size, sf::Color color) {
        lives = startingLives;
        font.loadFromFile("/usr/share/fonts/truetype/abyssinica/AbyssinicaSIL-Regular.ttf");
        text.setFont(font);
        text.setCharacterSize(size);
        text.setFillColor(color);
        updateText();
        setPosition(x,y);
    }

    void setPosition(int x,int y) {
        text.setPosition(x,y);
    }

    void decrease() {
        lives--;
        updateText();
        
    }
    
    void increase() {
        lives++;
        updateText();
        
    }

    int getLives() const {
        return lives;
    }

    void draw(sf::RenderWindow& window) const {
        window.draw(text);
    }

    int lives;
    sf::Text text;
    sf::Font font;

    void updateText() {
        text.setString("Lives: " + std::to_string(lives));
    }
};

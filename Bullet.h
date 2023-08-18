#include <SFML/Graphics.hpp>

using namespace sf;
class Bullet{
public:

Sprite sprte;
Texture tex;
int damage=5;
int po_x;
int po_y;
bool act=true;
float speed=-5;

Bullet(std::string png_path)
{
	tex.loadFromFile(png_path);
	sprte.setTexture(tex);
}

Bullet(){}

void update(float time)
{
	sprte.move(0,speed*time);
}
int gtX()
{return sprte.getPosition().x;}

int gtY()
{return sprte.getPosition().y;}

 bool isOffscreen(sf::RenderTarget& target)
    {
        return sprte.getPosition().y < 0 || sprte.getPosition().y > target.getSize().y;
    }
sf::FloatRect getGlobalBounds() const {
        return sprte.getGlobalBounds();
    }

};


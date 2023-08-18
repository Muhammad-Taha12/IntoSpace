#include <SFML/Graphics.hpp>

using namespace sf;

class Enemy3:public Bomb {
public:
    Sprite shape;
    Texture tex;
    Bomb *bombs;


Enemy3(int x,int y):Bomb()
{
	tex.loadFromFile("img/enemy_3.png");
	shape.setTexture(tex);
	shape.setPosition(x,y);
	shape.setScale(0.4,0.4);
	bombs=new Bomb("img/PNG/Lasers/laserGreen16.png");
}

void m()
{
	shape.move(1,0);
}
void n(int n)
{
	shape.move(-n,0);
}
    int gtX()
{return shape.getPosition().x;}

int gtY()
{return shape.getPosition().y;}

void Fire()
{
	bombs->shape.setPosition(gtX()+26,gtY()-15);
}

sf::FloatRect getGlobalBounds() const {
        return shape.getGlobalBounds();
    }
    
    bool isOfscreen(sf::RenderTarget& target)
    {
        return shape.getPosition().y < 0 || shape.getPosition().y > target.getSize().y;
    }
};


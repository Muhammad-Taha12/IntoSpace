#include <SFML/Graphics.hpp>

using namespace sf;


class Bomb {
public:
    Sprite shape;
    Texture tex;
    float speed=10;


    Bomb(std::string png_path)
{
	tex.loadFromFile(png_path);
	shape.setTexture(tex);
}
	Bomb()
	{}
	
    void update(float dt) {
        shape.move(0,speed * dt);
    }

    sf::FloatRect getGlobalBounds() {
        return shape.getGlobalBounds();
    }

int gX()
{return shape.getPosition().x;}

int gY()
{return shape.getPosition().y;}

sf::FloatRect getGlobalBounds() const {
        return shape.getGlobalBounds();
    }

};



class Enemy2:public Bomb {
public:
    Sprite shape;
    Texture tex;
    Bomb *bombs;


Enemy2(int x,int y):Bomb()
{
	tex.loadFromFile("img/enemy_2.png");
	shape.setTexture(tex);
	shape.setPosition(x,y);
	shape.setScale(0.4,0.4);
	bombs=new Bomb("img/PNG/Lasers/laserRed09.png");
}

    int gtX()
{return shape.getPosition().x;}

int gtY()
{return shape.getPosition().y;}

void Fire()
{
	bombs->shape.setPosition(gtX()+30,gtY()-15);
}

sf::FloatRect getGlobalBounds() const {
        return shape.getGlobalBounds();
    }
    
    bool isOfscreen(sf::RenderTarget& target)
    {
        return shape.getPosition().y < 0 || shape.getPosition().y > 780;
    }
};


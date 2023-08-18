#include <SFML/Graphics.hpp>
#include<string.h>
#include<iostream>
#include<cmath>
#include"Bullet.h"


using namespace sf;


	
class Player:public Bullet{
public:
int hp;

Texture tex;
Sprite sprite;
float speed=1;
int x,y;
float angl;
Bullet *B1;

	

Player(std::string png_path)
{
	this->hp=20;
tex.loadFromFile(png_path);
sprite.setTexture(tex);
x=340;y=680;
sprite.setPosition(x,y);
sprite.setScale(0.75,0.75);
B1=new Bullet("img/PNG/Lasers/laserBlue04.png");

}


void fireBullet()
{
	
	B1->po_x=getX();
	B1->po_y=getY();
	B1->sprte.setPosition(getX()+33,getY()-17);
	
}


void move(std::string s){
float delta_x=0,delta_y=0;
if(s=="l"){
	delta_x=-1;//move the player left
		angl=-0.707f;
	sprite.setRotation(angl * 180 / M_PI); 
}
else if(s=="r"){
	delta_x=1;//move the player right
		angl=0.707f;
	sprite.setRotation(angl * 180 / M_PI);
	}
else
{
	angl=0.f;
	sprite.setRotation(0); 	
}
if(s=="u")
	delta_y=-1;
else if(s=="d")
	delta_y=1;
else if(s=="s")
{
	angl=0.707f;
	sprite.setRotation(angl * 180 / M_PI);
	delta_y=-1; 
	delta_x=1;
}

else if(s=="a")
{
	angl=-0.707f;
	sprite.setRotation(angl * 180 / M_PI); 
	delta_x=-1;
	delta_y=-1;
	 
}

else if(s=="d")
{
	angl=0.f;
	sprite.setRotation(0); 	
	
	 
}
delta_x*=speed;
delta_y*=speed;

sprite.move(delta_x, delta_y);




}
void move(int sp)
{
	sprite.move(sp,0);
}


void move1(int sp)
{
	sprite.move(0,sp);
}
int getX()
{return sprite.getPosition().x;}

int getY()
{return sprite.getPosition().y;}

const sf::FloatRect getBounds() const
{
	return sprite.getGlobalBounds();
}


void Rot(Sprite& sprite, float theta)
{
	theta = theta * 3.14159 / 180;
	
		float cosTheta = cos(theta);
    		float sinTheta = sin(theta);
    		float rotationMatrix[2][2] = {
        	{cosTheta, -sinTheta},
        	{sinTheta, cosTheta}
					     };
					    
		float x = sprite.getPosition().x;
    float y = sprite.getPosition().y;

    // Rotate the position of the sprite
    float newX = x * rotationMatrix[0][0] + y * rotationMatrix[0][1];
    float newY = x * rotationMatrix[1][0] + y * rotationMatrix[1][1];

    // Set the new position of the sprite
    sprite.setPosition(newX, newY);   
}

sf::FloatRect getGlobalBounds() const {
        return sprite.getGlobalBounds();
    }
};









class Enemy
{
public:
	
	int curhp;
	int hp;
	
	
Texture tex;
Sprite sprite;

int X,Y;
Enemy(int x,int y)
{
X=x;
Y=y;
	this->hp=10;
	this->curhp=this->hp;
tex.loadFromFile("img/enemy_1.png");
sprite.setTexture(tex);
sprite.setPosition(x,y);
sprite.setScale(0.5,0.5);
}


sf::FloatRect getGlobalBounds() const {
        return sprite.getGlobalBounds();
    }
    
void draw(sf::RenderWindow& window) const {
        window.draw(sprite);
    }
    
     bool isOfscreen(sf::RenderTarget& target)
    {
        return sprite.getPosition().y < 0 || sprite.getPosition().y >780;
    }
    
    
    int getX()
{return sprite.getPosition().x;}

int getY()
{return sprite.getPosition().y;}
    
};




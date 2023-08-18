#include<iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "player.h"
#include"Enemy2.h"
#include<math.h>
#include<string>
#include "startmenu.h"
#include "Add_Ons.h"

using namespace sf;



const char title[] = "OOP-Project, Spring-2023";

class Game 
{
	public:
	Sprite background; 
	Texture bg_texture;
	Player* p; 
	Lives *live;
	Danger Dang;
	Live_add ad;
	Sprite destruction; 
	Texture text;
	Sprite pdestruct; 
	Texture ptext;
	Texture tex;
	Texture t;
	Texture t2;
	Texture t3;
	Sprite smenu;
	StartMenu M;
	Sprite game;
	bool end, start;
	int time1;
	Game()
	{
	t3.loadFromFile("img/Title.png");
	smenu.setTexture(t3);
	smenu.setScale(1.95, 1.95);

	p=new Player("img/player_ship.png");
	bg_texture.loadFromFile("img/background.jpg");
	background.setTexture(bg_texture);
	background.setScale(2.25, 1.95);

	text.loadFromFile("img/PNG/Damage/playerShip1_damage2.png");
	destruction.setTexture(text);
	destruction.setScale(0.75, 1);

	ptext.loadFromFile("img/explosion.png");
	pdestruct.setTexture(ptext);
	pdestruct.setScale(0.75, 1);


	 live=new Lives(3,850, 200, 20, sf::Color::White);
time1 = 0;
	end = false;
	start = true;
	background.setScale(2.5, 1.95);
	t2.loadFromFile("img/GameOver.png");
	game.setTexture(t2);
	game.setScale(4.5, 3.5);
	t.loadFromFile("img/PNG/playerShip1_red.png");
 

	}

void start_game()
{
    srand(time(0));
    RenderWindow window(VideoMode(1000,800 ), title);
    
    
    Clock clock;
    float timer;
    int interval=900;
    bool paus=false;
    float timer1[14]={0};
    int cnt=0,cnt1=0;
    bool A=true,B=false,C=false,danger=false;
    float dx[15],dy[15],dis[15];
    int score=0,c1=0,Pl=false;

 	
 	Font font;
 	font.loadFromFile("/usr/share/fonts/truetype/abyssinica/AbyssinicaSIL-Regular.ttf");
 	

   
    
    
    Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(850, 100);
        
        
   
        
        Enemy e1[10]={
        Enemy(100, 100),Enemy(200, 100),Enemy(300, 100),Enemy(400, 100),Enemy(500, 100),
        Enemy(100, 300),Enemy(100, 200),Enemy(300, 300),Enemy(500, 200),Enemy(500, 300), };
        
        Enemy e12[10]={
        Enemy(100, 100),Enemy(200, 200),Enemy(300, 300),Enemy(400, 400),Enemy(500, 500),
        Enemy(100, 500),Enemy(400, 200),Enemy(300, 300),Enemy(200, 400),Enemy(500, 100), };
        
        Enemy a1(0,300),a2(780,300);
        
        Enemy2 e2[14]= {Enemy2(100,100),Enemy2(200,100),Enemy2(300,100),Enemy2(400,100),Enemy2(500,100),
        		Enemy2(600,100),Enemy2(200,200),Enemy2(300,200),Enemy2(400,200),Enemy2(500,200),
        		Enemy2(250,300),Enemy2(350,300),Enemy2(450,300),Enemy2(350,400)};
        		
       		
        
       Danger Dang(rand()%400,rand()%400,0.5);
       Live_add ad(rand()%700,rand()%700,0.5);
	
	while (window.isOpen())
    	{
    	if (start==true)
    	{

    		window.draw(smenu);
    		window.display();
    		M.display_menu(start, window);
    	
    	}
    	else
    	{

    	if (end==false)
    	{
        float time = clock.getElapsedTime().asSeconds(); 
        if(paus==false)
        timer += time;   
 	Event e;
 	bool rota,rotb;
 	
 	
 	float elapsedTime = clock.getElapsedTime().asSeconds();
 	int cnt=0;
 	time1+=elapsedTime;
 	
 	if(Pl==true)
 	{
 		p->sprite.setTexture(t);
 	}
 	
 	if(ad.checkColl(p->getGlobalBounds()))
			{
				live->increase();
				ad.m_sprite.setPosition(rand()%700,rand()%700);	
			}
 
 	//// Conditions for new shapes of enemy of level 1
 	
 	
 	for(int i=0;i<10;i++)
 	if(e1[i].isOfscreen(window))
 	{
 		
 			cnt++;
 			if(cnt==10)
 			A=false;
 	}
 	 cnt=0;
 	for(int i=0;i<10;i++)
 	if(e12[i].isOfscreen(window))
 	{
 		
 			cnt++;
 			if(cnt==10)
 			B=true;
 	}

 	cnt1=0;
 	if(B==true)
	for(int i=0;i<14;i++)
 	if(e2[i].isOfscreen(window))
 	{
 		
 			cnt1++;
 			if(cnt1==14)
 			C=true;
 	}
 	if(C==true)
 	{
 		for(int i=0;i<14;i++)
 		e2[i].shape.setPosition(rand()%600,rand()%600);
 	}
 	
	///// End tab
        while (window.pollEvent(e))
        {  
            if (e.type == Event::Closed) // If cross/close is clicked/pressed
                window.close(); //close the game                        	    
        }
        
        ///Pause
     
        if (Keyboard::isKeyPressed(Keyboard::P)) 
         {  paus=true;
         
        } 
        ///Resume
        if (Keyboard::isKeyPressed(Keyboard::O)) 
         {  paus=false;
         
        }
        //Exit 
        if(Keyboard::isKeyPressed(Keyboard::E))
        {
       	
        Event::Closed;
            window.close();
        }
           
        if(paus==true)
        continue;
        
        
       //Movement
        if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
            p->move("l");    // Player will move to left
	if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
            p->move("r");  //player will move to right
	if (Keyboard::isKeyPressed(Keyboard::Up)) //If up key is pressed
            p->move("u");    //playet will move upwards
	if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
            p->move("d");  //player will move downwards
       
        if (Keyboard::isKeyPressed(Keyboard::S)) 
         {   p->move("s");  
            rotb =true;
            rota=false;
        }
        
        if (Keyboard::isKeyPressed(Keyboard::A)) 
         {   p->move("a");  
            rota =true;
            rotb=false;
        }
        
        if (Keyboard::isKeyPressed(Keyboard::D)) 
         {   p->move("d");  
            rota =false;
            rotb=false;
        }
        while (p->getX() < 0.f) 
        p->move(800);
     
	while (p->getX() > 800.f) 
        p->move(-800);
        
      	if (p->getY() < 0.f) 
        p->move1(800);
     
	if (p->getY() > 800.f) 
        p->move1(-800);
        
      	/////Bullet
      	if(Keyboard::isKeyPressed(Keyboard::Space))
        {
        	
        	   p->fireBullet();
			
			
	}
	
	if(rota==true)
        p->B1->sprte.move(-5,-5);
        
        else if(rotb==true)
        p->B1->sprte.move(5,-5);
     	
     	else
        p->B1->update(10);
       
       
      if(time1>40)
        Dang.update(5);
        
        
        	if(time1>40&&c1==0)
	{
	dx[0]=pow(p->getX()-Dang.getX(),2);
        dy[0]=pow(p->getY()-Dang.getY(),2);
        dis[0]=sqrt(dx[0]+dy[0]);
	if(dis[0]<30 )
        {
       	live->decrease();
	p->sprite.setPosition(340,680);
	Dang.m_sprite.setPosition(1000,1000);
	danger==true;
	}
	else 
	danger==false;
	
	if(danger==false)
	score+=50;
	c1=1;
	}
	/* What is this
	if(p->hp==0)
       {
       live->decrease();
       p->hp=20;
       }*/
        
      //Enemy Bullet Fire
        if(B==true&&C==false)
      	for(int i=0;i<14;i++)
      	if(timer1[i]>=interval)
	{
	e2[i].bombs->update(0.3);
       
        if(e2[i].bombs->gY()>780)
        {
        timer1[i]=0;
        e2[i].Fire();
        }
        }
                      
          //Interval
        for(int i=0;i<14;i++)
        timer1[i]+=1;
      
        
        
         for(int i=0;i<14;i++)
        {
        dx[i]=pow(e2[i].bombs->gX()-p->getX(),2);
        dy[i]=pow(e2[i].bombs->gY()-p->getY(),2);
        dis[i]=sqrt(dx[i]+dy[i]);
        }
        ///Bound Check 
        if(C==false)
        if(B==true)
        for(int i=0;i<14;i++)
        if(dis[i]<60)
        {
        p->hp-=5;
        pdestruct.setPosition(p->getX(),p->getY());
        window.draw(pdestruct);
        }
      
      //Health Decrease
        for(int i=0;i<10;i++)
        {
        dx[i]=pow(p->getX()-e1[i].getX(),2);
        dy[i]=pow(p->getY()-e1[i].getY(),2);
        dis[i]=sqrt(dx[i]+dy[i]);
        }
        for(int i=0;i<10;i++)
	if(dis[i]<50)
        {
        live->decrease();
        e1[i].sprite.setPosition(1000,1000);
	p->sprite.setPosition(340,680);
	}
	
	
	for(int i=0;i<10;i++)
        {
        dx[i]=pow(p->getX()-e12[i].getX(),2);
        dy[i]=pow(p->getY()-e12[i].getY(),2);
        dis[i]=sqrt(dx[i]+dy[i]);
        }
	if(A==false)
	for(int i=0;i<10;i++)
	if(dis[i]<50)
        {
        live->decrease();
	p->sprite.setPosition(340,680);
	e12[i].sprite.setPosition(1000,1000);
	}
      
      	if(A==true)
	for(int i=0;i<10;i++)
	{
		e1[i].sprite.move(0,0.3);
	}

	if(A==false)
	for(int i=0;i<10;i++)
	{
		e12[i].sprite.move(0,0.3);
	}
     		
	if(ad.checkColl(p->getGlobalBounds()))
	{
	live->increase();
	ad.m_sprite.setPosition(rand()%700,rand()%700);	
	}
	
	if(C==false)
	if(B==true)
	for(int i=0;i<14;i++)
	if(p->B1->getGlobalBounds().intersects(e2[i].getGlobalBounds()))
        {
        destruction.setPosition(e2[i].gtX(),e2[i].gtY());
        e2[i].shape.setPosition(1000,1000);
        e2[i].bombs->shape.setPosition(1000,1000);
        p->B1->sprte.move(-900,-1000);
        score+=20;
        }
	
	
	
	
	if(A==false)
	for(int i=0;i<10;i++)
       if(p->B1->getGlobalBounds().intersects(e12[i].getGlobalBounds()))
        {
        destruction.setPosition(e1[i].X,e1[i].Y);
        e12[i].sprite.move(-900,-1000);
        p->B1->sprte.move(-900,-1000);
        score+=10;
        }
        
        
	for(int i=0;i<10;i++)
       if(p->B1->getGlobalBounds().intersects(e1[i].getGlobalBounds()))
        {
        destruction.setPosition(e1[i].X,e1[i].Y);
        e1[i].sprite.move(1000,1000);
        p->B1->sprte.move(-900,-1000);
        score+=10;
        }
        
        
	window.draw(destruction);}
        	 			 	 if (live->lives == 0)
	{
		window.draw(game);
		end = true;
	}
	        window.display();
	window.display();  
	Event e;
        if (end)
        {
        	  while (window.pollEvent(e))
        {  
            if (e.type == Event::Closed) // If cross/close is clicked/pressed
                window.close(); //close the game                        	    
        }
        
        ///Pause
     
        if (Keyboard::isKeyPressed(Keyboard::E)) 
         {  window.close();
         
        } 
        }

	
	std::string scoreString = "Score: " + std::to_string(score);
        scoreText.setString(scoreString);
        
	////Display 
	
	window.clear(Color::Black); //clears the screen
	window.draw(background);  // setting background
	window.draw(p->sprite);   // setting player on screen
	

	if(time1>40)
	window.draw(Dang.m_sprite);
	
	window.draw(ad.m_sprite);
	window.draw(p->B1->sprte);
	
	
	
	////Enemy 1 Shapes
	if(A==true)
	for (int i = 0; i < 10	; i++) 
	{
            e1[i].draw(window); 
        }
        if(B==false)
	for (int i = 0; i < 10	; i++) 
	{
            e12[i].draw(window); 
        }
        
	////Enemy 2 Shapes
	 
	if( B==true && C==false)
	for (int i = 0; i < 14	; i++)
	window.draw(e2[i].shape);
	
	if(B==true && C==false )
        for (int i = 0; i < 14	; i++) 
	{
            window.draw(e2[i].bombs->shape); 
        }
        
	 window.draw(scoreText);
	 window.draw(live->text);
	
}
	//Dispaly
      
      
      
      
}
}


};


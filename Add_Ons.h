#include"Power-Up.h"
#include"lives.h"
#include"danger.h"
#include"Fire.h"

#include <SFML/Graphics.hpp>

class ADD_Ons
{
public:
    
    ADD_Ons(int choice)
    {
    	if(choice==1)
    	{
    		Powerup p(rand()%800,rand()%800);
    	}
    	
    	
    }
private:
    int choice;
    
};


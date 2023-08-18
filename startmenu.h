#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class StartMenu
{
	public:
	    void display_menu(bool& start, RenderWindow& w)
{
    int choice;
    /*
        cout << "=== Main Menu ===" << endl;
        cout << "1. Instructions" << endl;
        cout << "2. Play Game" << endl;
        cout << "3. High Scores" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";*/
        cin >> choice;

        switch (choice) {
            case 1:
                displayInstructions();
                break;
            case 2:
            		start = false;
		break;
            case 3:
            	//Level Stuff
            	break;
            case 4:
                displayHighScores();
                break;
            case 5:
                cout << "Goodbye!" << endl;
                w.close();
                break;
            
             }
}
		
    void displayInstructions() 
    {
        cout << "=== Instructions ===" << endl;
        cout << "The player controls a spaceship in an enemy filled space field. The spaceship can move in all possible directions (right, left, up, down and diagonally)." <<endl<< endl;
        cout << "The spaceship can fire bullets to destroy the objects in the space field." << endl<< endl;
        cout << "The spaceship can also avail the add-ons options which would fall after random intervals." <<endl<<  endl;
        cout << "1. Power Up: The power-up feature will fall randomly in galactic space. Once the player receives the power-up add-on, the spaceship will fire a continuous beam of bullets in all seven directions as shown in figure. It will be time-controlled lasting only for 5 seconds. In the power-up mode, the spaceship will not be destroyed even if the enemy bombs hit the spaceship." << endl<< endl;
        cout << "2. Fire: Another feature that the spaceship can avail is to catch fire. Once the spaceship avails this add-on, its bullets will change into fire destroying all the spaceships in its way. It will also last for 5 seconds only." <<endl<<  endl;
        cout << "3. Danger: Another add-on feature is the danger sign. This danger sign cannot be destroyed by bullets or bombs. The spaceship needs to maneuver in a way as to dodge and avoid collision with the danger sign. If the spaceship comes in contact with the danger sign, it will be destroyed, and the lives would be decreased. The score to dodge the danger sign is 5." <<endl<<  endl;
        cout << "4. Lives: The lives add-on would help the spaceship by incrementing the remaining lives by 1." <<endl<<  endl;
    }

    void displayGamePlay() 
    {
        cout << "=== Game Play ===" << endl;
        cout << "Use the arrow keys to move the spaceship, and the spacebar to fire bullets." << endl;
        cout << "Destroy all the enemies to advance to the next level." << endl;
        cout << "Collect power-ups to gain special abilities." << endl;
    }

    void displayPauseScreen() 
    {
        cout << "=== Paused ===" << endl;
        cout << "1. Resume" << endl;
        cout << "2. Quit to Main Menu" << endl;
    }

  
	void displayHighScores() {
    std::ifstream file("high_score.txt");
    if (!file.is_open()) {
        std::cout << "Failed to open file" << std::endl;
        return;
    }


    
    std::cout << "=== High Scores ===" << std::endl;
    

    file.close();
}

    void displayEndScreen() 
    {
        cout << "=== Game Over ===" << endl;
        cout << "Thanks for playing!" << endl;
        
    }

};


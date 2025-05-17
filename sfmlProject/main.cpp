#include "Game.h"
int main()
{
	//initGameEngine
	Game game;
	std::srand(static_cast<unsigned>(time(NULL)));
	while (game.getAlive() && game.running())
	{
		//Menu Loop
		while (!game.getStart() && game.running())
		{
			game.updateStart();
			game.renderStart();
		}
		//Levels
		if (game.getLevel() == 1)
		{
			game.levelOne();
		}
		else if (game.getLevel() == 2)
		{
			game.levelTwo();
		}
		else if (game.getLevel() == 3)
		{
			game.levelThree();
		}
		else if (game.getLevel() == 4)
		{
			game.levelFour();
		}
		else if (game.getLevel() == 5)
		{
			game.levelFive();
		}
		//gameloop
		while (game.running() && !game.getEndGame())
		{
			game.update();
			game.render();
		}
		//Restart Loop
		if (game.getLevel() == 5 && game.getAlive())
		{
			while (game.getAlive() && game.running())
			{
				game.updateRestartButton();
				game.renderRestartButton();
			}
		}
		else if (game.getAlive() == false)
		{	
			while (!game.getAlive() && game.running())
			{
				game.updateRestartButton();
				game.renderRestartButton();
			}
		}
		game.clearEvery();
		game.levelUp();
	}
	//End of Code
	return 0;
}
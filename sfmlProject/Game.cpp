#include "Game.h"
//Private Functions
void Game::initVariables()
{
	this->window = nullptr;
	this->points = 0;
	this->lives = 10;
	this->enemySpawnTimer = 10.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 4;
	this->mouseHeld = false;
	this->endGame = false;
	this->fireCooldown = 0;
	this->burnCooldown = 0;
	this->boost = 0;
	this->playerBurnCooldown = 0;
	this->ifRenderPlayerBurn = false;
	this->speed = 1;
	this->specialProbability = 0;
	this->start = false;
	this->level = 1;
	this->alive = true;
	this->restart = true;
	this->totalPoints = 0;
	this->highScore = 0;
	std::ifstream inFile;
	inFile.open("highscore.txt");
	inFile >> this->highScore;
	inFile.close();
}
void Game::initWorld()
{
	this->world.setTexture(this->worldTexture);
	this->world.setScale(0.6f, 1.f);
	this->menuBackground.setTexture(this->menuBackgroundTexture);
}
void Game::initWindow()
{
	this->videoMode.height = 680;
	this->videoMode.width = 1080;
	this->window = new::sf::RenderWindow(this->videoMode, "Space Shooter", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}
void Game::initTexture()
{
	if (!this->enemyTexture.loadFromFile("images/enemy.png"))
	{
		std::cout << "ERROR::LOADING OF ENEMY TEXTURE" << std::endl;
	}
	if (!this->playerTexture.loadFromFile("images/spaceship.png"))
	{
		std::cout << "ERROR::LOADING PLAYER TEXTURE" << std::endl;
	}
	if (!this->enemyBurnTexture.loadFromFile("images/enemyBurn.png"))
	{
		std::cout << "ERROR::LOADING BURN TEXTURE" << std::endl;
	}
	if (!this->fireTexture.loadFromFile("images/fire.png"))
	{
		std::cout << "ERROR::LOADING FIRE TEXTURE" << std::endl;
	}
	if (!this->powerUpTexture.loadFromFile("images/powerUp.png"))
	{
		std::cout << "ERROR::LOADING FIRE TEXTURE" << std::endl;
	}
	if (!this->worldTexture.loadFromFile("images/world.jpeg"))
	{
		std::cout << "ERROR::LOADING OF WORLD TEXTURE" << std::endl;
	}
	if (!this->playerBurnTexture.loadFromFile("images/playerBurn.png"))
	{
		std::cout << "ERROR::LOADING OF PLAYER BURN TEXTURE" << std::endl;
	}
	if (!this->specialEnemyTexture.loadFromFile("images/specialEnemy.png"))
	{
		std::cout << "ERROR::LOADING OF SPECIAL ENEMY TEXTURE" << std::endl;
	}
	if (!this->menuBackgroundTexture.loadFromFile("images/world.jpeg"))
	{
		std::cout << "ERROR::LOADING OF MENU BACKGROUND TEXTURE" << std::endl;
	}
}
void Game::initFire()
{
	this->fire.setTexture(this->fireTexture);
	this->fire.setScale(0.05f, 0.05f);
}
void Game::initEnemyBurn()
{
	this->enemyBurn.setTexture(this->enemyBurnTexture);
	this->enemyBurn.setScale(0.05f, 0.05f);
}
void Game::initPowerUp()
{
	this->powerUp.setTexture(this->powerUpTexture);
	this->powerUp.setScale(0.15f, 0.15f);
}
void Game::initHpBar()
{
	this->hpBarBack.setFillColor(sf::Color(128, 128, 128, 255));
	this->hpBarBack.setSize(sf::Vector2f(200.f, 25.f));
	this->hpBarBack.setPosition(sf::Vector2f(this->window->getSize().x / 2 + 200, 100.f));
	this->hpBar.setFillColor(sf::Color(0, 128, 0, 255));
	this->hpBar.setSize(sf::Vector2f(200.f, 25.f));
	this->hpBar.setPosition(sf::Vector2f(this->window->getSize().x / 2 + 200, 100.f));
}
void Game::initPlayerBurn()
{
	this->playerBurn.setTexture(this->playerBurnTexture);
	this->playerBurn.setScale(0.1f, 0.1f);
}
void Game::initSpecialEnemy()
{
	this->specialEnemy.setTexture(this->specialEnemyTexture);
	this->specialEnemy.setScale(0.1f, -0.1f);
}
void Game::initSprite()
{
	this->enemy.setTexture(this->enemyTexture);
	this->enemy.setScale(sf::Vector2f(0.08f, -0.08f));
}
void Game::initPlayer()
{
	this->player.setTexture(this->playerTexture);
	this->player.setPosition(sf::Vector2f(500.f, 500.f));
	this->player.setScale(0.1f, 0.1f);
}
void Game::initFonts()
{
	if (!this->font.loadFromFile("Fonts/ARLRDBD.ttf"))
	{
		std::cout << "ERROR::GAME::initFonts()::FAILED TO LOAD FONTS" << std::endl;
	}
}
void Game::initText()
{
	this->uiText.setFont(font);
	this->uiText.setCharacterSize(22);
	this->uiText.setFillColor(sf::Color::White);
	this->uiText.setString("NONE");
	this->uiText.setPosition(sf::Vector2f(this->window->getSize().x/2+200, 100.f));
	this->startButtonText.setFont(font);
	this->startButtonText.setCharacterSize(40);
	this->startButtonText.setFillColor(sf::Color::Blue);
	this->startButtonText.setString("NONE");
	this->startButtonText.setPosition(window->getSize().x / 2 - 125, window->getSize().y / 2 - 27);
	this->restartButtonText.setFont(font);
	this->restartButtonText.setCharacterSize(40);
	this->restartButtonText.setFillColor(sf::Color::Blue);
	this->restartButtonText.setPosition(window->getSize().x / 2 - 132, window->getSize().y / 2 - 27);
	this->restartButtonText.setString("Restart Game");
	this->exitButtonText.setFont(font);
	this->exitButtonText.setCharacterSize(40);
	this->exitButtonText.setFillColor(sf::Color::White);
	this->exitButtonText.setPosition(window->getSize().x / 2 - 100, window->getSize().y / 2 + 90);
	this->exitButtonText.setString("Exit Game");
	this->exitButtonText2.setFont(font);
	this->exitButtonText2.setCharacterSize(40);
	this->exitButtonText2.setFillColor(sf::Color::White);
	this->exitButtonText2.setPosition(window->getSize().x / 2 + 230, window->getSize().y / 2 + 90);
	this->exitButtonText2.setString("Exit Game");
	this->instruction1.setFont(font);
	this->instruction1.setCharacterSize(28);
	this->instruction1.setFillColor(sf::Color::White);
	this->instruction1.setPosition(window->getSize().x / 2 - 400, 30);
	this->instruction1.setString("Welcome to our Space Shooter Game! Here are the instrucitons:\n1. Press Arrow Keys/A or D to move around.\n2. Press SPACE to shoot.\n3. Press ESCAPE or Exit button to exit\n4. Score 50 points in one level to move to next level\n5. Your lives(10) will not replenish when you move to next level\n6. Complete all five levels to win the game");
	this->instruction2.setFont(font);
	this->instruction2.setCharacterSize(40);
	this->instruction2.setFillColor(sf::Color::White);
	this->instruction2.setPosition(window->getSize().x / 2 -140, 100);
	this->instruction2.setString("NONE");
}
void Game::level1Variables()
{
	this->maxEnemies = 2;
	this->points = 0;
	this->enemySpawnTimer = 10.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->mouseHeld = false;
	this->endGame = false;
	this->fireCooldown = 0;
	this->burnCooldown = 0;
	this->boost = 0;
	this->playerBurnCooldown = 0;
	this->ifRenderPlayerBurn = false;
	this->speed = 1.25;
	this->specialProbability = 0;
	this->alive = true;
	this->totalPoints = 0;
}
void Game::level2Variables()
{
	this->maxEnemies = 3;
	this->points = 0;
	this->enemySpawnTimer = 10.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->mouseHeld = false;
	this->endGame = false;
	this->fireCooldown = 0;
	this->burnCooldown = 0;
	this->boost = 0;
	this->playerBurnCooldown = 0;
	this->ifRenderPlayerBurn = false;
	this->speed = 1.5;
	this->specialProbability = 4;
	this->alive = true;
}
void Game::level3Variables()
{
	this->maxEnemies = 4;
	this->points = 0;
	this->enemySpawnTimer = 10.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->mouseHeld = false;
	this->endGame = false;
	this->fireCooldown = 0;
	this->burnCooldown = 0;
	this->boost = 0;
	this->playerBurnCooldown = 0;
	this->ifRenderPlayerBurn = false;
	this->speed = 2;
	this->specialProbability = 8;
	this->alive = true;
}
void Game::level4Variables()
{
	this->maxEnemies = 5;
	this->points = 0;
	this->enemySpawnTimer = 10.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->mouseHeld = false;
	this->endGame = false;
	this->fireCooldown = 0;
	this->burnCooldown = 0;
	this->boost = 0;
	this->playerBurnCooldown = 0;
	this->ifRenderPlayerBurn = false;
	this->speed = 2.25;
	this->specialProbability = 12;
	this->alive = true;
}
void Game::level5Variables()
{
	this->maxEnemies = 6;
	this->points = 0;
	this->enemySpawnTimer = 10.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->mouseHeld = false;
	this->endGame = false;
	this->fireCooldown = 0;
	this->burnCooldown = 0;
	this->boost = 0;
	this->playerBurnCooldown = 0;
	this->ifRenderPlayerBurn = false;
	this->speed = 2.5;
	this->specialProbability = 16;
	this->alive = true;
}
void Game::initMenu()
{
	this->menu.setFillColor(sf::Color::Black);
	this->menu.setSize(sf::Vector2f(this->window->getSize().x / 2 - 100,this->window->getSize().y));
	this->menu.setPosition(sf::Vector2f(this->window->getSize().x / 2+100, 0.f));
	this->menu.setOutlineThickness(4);
	this->menu.setOutlineColor(sf::Color::Blue);
}
void Game::initStartButtons()
{
	this->startButton.setFillColor(sf::Color::Green);
	this->startButton.setSize(sf::Vector2f(300.f, 100.f));
	this->startButton.setPosition(sf::Vector2f(this->window->getSize().x / 2 - 150, this->window->getSize().y/2 - 50));
	this->restartButton.setFillColor(sf::Color::Green);
	this->restartButton.setSize(sf::Vector2f(300.f, 100.f));
	this->restartButton.setPosition(sf::Vector2f(this->window->getSize().x / 2 - 150, this->window->getSize().y / 2 - 50));
	this->exitButton.setFillColor(sf::Color::Red);
	this->exitButton.setSize(sf::Vector2f(300.f, 100.f));
	this->exitButton.setPosition(sf::Vector2f(this->window->getSize().x / 2 - 150, this->window->getSize().y / 2 + 70));
	this->exitButton2.setFillColor(sf::Color::Red);
	this->exitButton2.setSize(sf::Vector2f(300.f, 100.f));
	this->exitButton2.setPosition(sf::Vector2f(this->window->getSize().x / 2 +180, this->window->getSize().y / 2 + 70));
}
//Constructors/Destructors
void Game::levelOne()
{
	initFire();
	initEnemyBurn();
	initPowerUp();
	initSpecialEnemy();
	initPlayerBurn();
	initSprite();
	initPlayer();
	level1Variables();

}
void Game::levelTwo()
{
	initFire();
	initEnemyBurn();
	initPowerUp();
	initSpecialEnemy();
	initPlayerBurn();
	initSprite();
	initPlayer();
	level2Variables();

}
void Game::levelThree()
{
	initFire();
	initEnemyBurn();
	initPowerUp();
	initSpecialEnemy();
	initPlayerBurn();
	initSprite();
	initPlayer();
	level3Variables();
}
void Game::levelFour()
{
	initFire();
	initEnemyBurn();
	initPowerUp();
	initSpecialEnemy();
	initPlayerBurn();
	initSprite();
	initPlayer();
	level4Variables();
}
void Game::levelFive()
{
	initFire();
	initEnemyBurn();
	initPowerUp();
	initSpecialEnemy();
	initPlayerBurn();
	initSprite();
	initPlayer();
	level5Variables();
}
void Game::clearEvery()
{
	for (int i = this->enemies.size() - 1; i >= 0; i--)
	{
		this->enemies.erase(this->enemies.begin() + i);
	}
	for (int i = this->Fires.size() - 1; i >= 0; i--)
	{
		this->Fires.erase(this->Fires.begin() + i);
	}
	for (int i = this->PowerUps.size() - 1; i >= 0; i--)
	{
		this->PowerUps.erase(this->PowerUps.begin() + i);
	}
	for (int i = this->Burns.size() - 1; i >= 0; i--)
	{
		this->Burns.erase(this->Burns.begin() + i);
	}
	for (int i = this->SpecialEnemies.size() - 1; i >= 0; i--)
	{
		this->SpecialEnemies.erase(this->SpecialEnemies.begin() + i);
	}
}
void Game::levelUp()
{
	this->level++;
	this->alive = true;
	this->start = false;
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initTexture();
	this->initSprite();
	this->initPlayer();
	this->initFire();
	this->initEnemyBurn();
	this->initFonts();
	this->initText();
	this->initPowerUp();
	this->initWorld();
	this->initHpBar();
	this->initPlayerBurn();
	this->initSpecialEnemy();
	this->initMenu();
	this->initStartButtons();
}

Game::~Game()
{
	delete this->window;
}
//Accessors
bool Game::running()
{
	return this->window->isOpen();
}
bool Game::getEndGame()
{
	return this->endGame;
}
int Game::getLevel()
{
	return this->level;
}
bool Game::getStart()
{
		return start;
}
bool Game::getAlive()
{
	return this->alive;
}
bool Game::getRestart()
{
	return this->restart;
}
//Functions
void Game::pollEvents()
{
	//Event Polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}
void Game::updateMousePositions()
{
	//this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
void Game::spawnEnemy()
{
	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x)/2 + 2),
		0.f
		);
	//Spawn the Enemy
	this->enemies.push_back(this->enemy);
}
void Game::spawnSpecialEnemy()
{
		this->specialEnemy.setPosition(sf::Vector2f(static_cast<float>(rand() % this->window->getSize().x/2 + 25), 0.f));
		this->SpecialEnemies.push_back(this->specialEnemy);	
		this->SpecialEnemiesHealth.push_back(3);
}
void Game::updateEnemies()
{
	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			this->spawnEnemy();
			enemySpawnTimer = 0.f;
		}
		else
			enemySpawnTimer++;
	}
	for (int i = 0; i < this->enemies.size(); i++)
	{
		this->enemies[i].move(0.f, this->speed);
		if (this->enemies[i].getPosition().y >= this->window->getSize().y)
		{
			this->enemies.erase(this->enemies.begin() + i);
			this->updateHpBar();
			lives--;
		}
		if (this->enemies[i].getGlobalBounds().intersects(this->player.getGlobalBounds()))
		{
			this->enemies.erase(this->enemies.begin() + i);
			this->updateHpBar();
			this->updateHpBar();
			this->playerBurnCooldown+=30;
			lives -= 2;
		}
	}
	if (this->playerBurnCooldown > 0)
	{
		--this->playerBurnCooldown;
		this->updatePlayerBurn();
	}
	else
		this->ifRenderPlayerBurn = false;
}

void Game::updateEnemyBurn()
{
	for (int j = 0; j < this->Burns.size(); j++)
	{
		this->burnCounter[j]--;
		if (this->burnCounter[j] <= 0)
		{
			this->burnCounter.erase(this->burnCounter.begin() + j);
			this->Burns.erase(this->Burns.begin() + j);
			j--;
		}
	}
}
void Game::updateFire()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->fireCooldown <= 0)
	{
		this->fire.setPosition(sf::Vector2f(this->player.getPosition().x, 500.f));
		this->Fires.push_back(this->fire);
		if(boost<=0)
			this->fireCooldown = 20;
		else if (boost > 0)
		{
			this->fireCooldown = 3;
		}
	}
	else
		fireCooldown--;
	if (boost > 0)
		boost--;
	for (int i = 0; i < this->Fires.size(); i++)
	{
		bool kill = false;
		int j;
		for (j = 0; j < this->enemies.size(); j++)
		{
			if (this->Fires[i].getGlobalBounds().intersects(this->enemies[j].getGlobalBounds()))
			{
				kill = true;
				this->enemyBurn.setPosition(sf::Vector2f(Fires[i].getPosition().x, Fires[i].getPosition().y - 5));
				this->Burns.push_back(this->enemyBurn);
				this->burnCounter.push_back(20);
				break;
			}
			if (j + 1 == this->enemies.size())
				break;
		}
		if (this->Fires[i].getPosition().y < 0.f)
		{
			this->Fires.erase(this->Fires.begin() + i);
		}
		else if (kill)
		{
			this->Fires.erase(this->Fires.begin() + i);
			this->enemies.erase(this->enemies.begin() + j);
			this->points++;
			this->totalPoints++;
		}
		else
		{
			this->Fires[i].move(0.f, -8.f);
		}
		if (i + 1 == this->Fires.size())
			break;
	}
}

void Game::updatePowerUp()
{
	if (rand() % 10000 < 14)
	{
		this->powerUp.setPosition(sf::Vector2f(static_cast<float>((rand() % 1080) / 2 + 25), 0.f));
		this->PowerUps.push_back(this->powerUp);
	}
	for (int i = 0; i < this->PowerUps.size(); i++)
	{
		this->PowerUps[i].move(0.f, 2.f);
		if (this->PowerUps[i].getPosition().y > this->window->getSize().y)
		{
			this->PowerUps.erase(this->PowerUps.begin() + i);
			i--;
		}
	}
	if (this->PowerUps.size() > 0)
	{
		for (int i = 0; i < this->Fires.size(); i++)
		{
			for (int j = 0; j < this->PowerUps.size(); j++)
			{
				if (this->Fires[i].getGlobalBounds().intersects(this->PowerUps[j].getGlobalBounds()))
				{
					this->Fires.erase(this->Fires.begin() + i);
					this->PowerUps.erase(this->PowerUps.begin() + j);
					boost += 180;
				}
			}
		}
	}
}

void Game::updateHpBar()
{
	//Called when Player takes damage
	this->hpBar.setSize(sf::Vector2f(this->hpBar.getSize().x - 20, 25.f));
}

void Game::updatePlayerBurn()
{
	//Call in updateEnemies updateSpecialEnemies
	this->playerBurn.setPosition(sf::Vector2f(this->player.getPosition().x-50, this->player.getPosition().y));
	this->ifRenderPlayerBurn = true;
}

void Game::updateSpecialEnemy()
{
	if (rand() % 10000 < this->specialProbability)
	{
		this->spawnSpecialEnemy();
	}
	if (this->playerBurnCooldown > 0)
	{
		--this->playerBurnCooldown;
		this->updatePlayerBurn();
	}
	else
		this->ifRenderPlayerBurn = false;
	for (int i = this->SpecialEnemies.size()-1; i >=0; i--)
	{
		this->SpecialEnemies[i].move(0.f, 3.f);
		if (this->SpecialEnemies[i].getPosition().y >= this->window->getSize().y)
		{
			this->SpecialEnemies.erase(this->SpecialEnemies.begin() + i);
			this->SpecialEnemiesHealth.erase(this->SpecialEnemiesHealth.begin() + i);
			--this->lives;
			this->updateHpBar();
			break;
		}
		if (this->SpecialEnemies[i].getGlobalBounds().intersects(this->player.getGlobalBounds()))
		{
			this->SpecialEnemies.erase(this->SpecialEnemies.begin() + i);
			this->SpecialEnemiesHealth.erase(this->SpecialEnemiesHealth.begin() + i);
			this->updateHpBar();
			this->updateHpBar();
			this->playerBurnCooldown += 30;
			lives -= 2;
			break;
		}
		for (int j=this->Fires.size()-1; j>=0 ; j--)
		{
			if (this->SpecialEnemies[i].getGlobalBounds().intersects(this->Fires[j].getGlobalBounds()))
			{
				--this->SpecialEnemiesHealth[i];
				this->enemyBurn.setPosition(sf::Vector2f(Fires[j].getPosition().x, Fires[j].getPosition().y - 5));
				this->Burns.push_back(this->enemyBurn);
				this->burnCounter.push_back(20);
				this->Fires.erase(this->Fires.begin() + j);
				if (this->SpecialEnemiesHealth[i] <= 0)
				{
					this->SpecialEnemies.erase(this->SpecialEnemies.begin() + i);
					this->SpecialEnemiesHealth.erase(this->SpecialEnemiesHealth.begin() + i);
					this->points += 5;
					this->totalPoints += 5;
				}
				break;
			}
		}
	}
}

void Game::updateStart()
{
	this->pollEvents();
	this->mousePosView=this->window->mapPixelToCoords(sf::Mouse::getPosition(*window));
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (this->startButton.getGlobalBounds().contains(this->mousePosView))
		{
			start = true;
		}
		else if (this->exitButton.getGlobalBounds().contains(this->mousePosView))
		{
			window->close();
		}
	}
	this->updateStartButtonText();
}
void Game::updateStartButtonText()
{
	std::stringstream sbt;
	sbt << "Start Level " << this->level;
	this->startButtonText.setString(sbt.str());
}
void Game::updateRestartButton()
{
	this->pollEvents();
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->updateMousePositions();
		if (this->restartButton.getGlobalBounds().contains(this->mousePosView))
		{
			this->restart = true;
			if (this->level == 5 && this->alive == true)
				this->alive = false;
			else
				this->alive = true;
			this->lives = 10;
			this->initHpBar();
			this->level = 0;
			
		}
		else if (this->exitButton.getGlobalBounds().contains(this->mousePosView))
		{
			window->close();
		}
	}
	if (this->totalPoints >= this->highScore)
	{
		this->highScore = this->totalPoints;
		std::ofstream outFile;
		outFile.open("highscore.txt");
		outFile << this->highScore;
		outFile.close();
	}
	this->updateInstruction2();
}
void Game::updateInstruction2()
{
	std::stringstream gameOver;
	gameOver << " GAME OVER!" << std::endl << "Total Points: " << this->totalPoints << std::endl << "Highscore: " <<highScore;
	this->instruction2.setString(gameOver.str());
}
void Game::update()
{
	this->pollEvents();
	if (!this->endGame)
	{
		this->updateMousePositions();
		this->updateText();
		this->updateEnemies();
		this->updatePlayer();
		this->updateFire();
		this->updatePowerUp();
		this->updateSpecialEnemy();
		this->updateEnemyBurn();
		//exit button
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (this->exitButton2.getGlobalBounds().contains(this->mousePosView))
			{
				window->close();
			}
		}
	}
	if (lives <= 0 || points>=50)
	{
		if (lives <= 0)
			this->alive = false;
		else if (points >= 50)
		{
			this->alive = true;
			this->restart = false;
		}
		this->endGame = true;
	}
}
void Game::updateText()
{
	std::stringstream ss;
	if (boost<= 0)
		ss << "Lives: " << this->lives << std::endl << "Points: " << this->points << std::endl << "Level: " << this->level;
	else
		ss << "Lives: " << this->lives << std::endl << "Points: " << this->points << std::endl << "Level: " << this->level << std::endl << "Boost: " << std::setprecision(2) << static_cast<float>(boost)/60.0;
	this->uiText.setString(ss.str());
}
void Game::updatePlayer()
{
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && player.getPosition().x>0)
	{
		this->player.move(-4.5f, 0.f);
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && player.getPosition().x < this->window->getSize().x/2)
	{
		this->player.move(4.5f, 0.f);
	}
}
void Game::renderEnemies(sf::RenderTarget& target)
{
	for (auto& e : this->enemies)
	{
		target.draw(e);
	}
}
void Game::renderEnemyBurn(sf::RenderTarget& target)
{
	for (int i = 0; i < Burns.size(); i++)
		target.draw(Burns[i]);
}
void Game::renderFire(sf::RenderTarget& target)
{
	for (auto& f : this->Fires)
	{
		target.draw(f);
	}
}
void Game::renderPowerUp(sf::RenderTarget& target)
{
	for (int i = 0; i < this->PowerUps.size(); i++)
	{
		target.draw(PowerUps[i]);
	}
}
void Game::renderHpBar(sf::RenderTarget& target)
{
	target.draw(this->hpBarBack);
	target.draw(this->hpBar);
}
void Game::renderPlayerBurn(sf::RenderTarget& target, bool ifRenderPlayerBurn)
{
	if(ifRenderPlayerBurn)
		target.draw(this->playerBurn);
}
void Game::renderSpecialEnemy(sf::RenderTarget& target)
{
	for (int i = 0; i < this->SpecialEnemies.size(); i++)
	{
		target.draw(this->SpecialEnemies[i]);
	}
}
void Game::renderMenu(sf::RenderTarget& target)
{
	target.draw(this->menu);
}
void Game::render()
{
	this->window->clear();
	this->renderWorld(*this->window);
	this->renderEnemies(*this->window);
	this->renderPowerUp(*this->window);
	this->renderSpecialEnemy(*this->window);
	this->renderPlayer(*this->window);
	this->renderFire(*this->window);
	this->renderEnemyBurn(*this->window);
	this->renderPlayerBurn(*this->window, this->ifRenderPlayerBurn);
	this->renderMenu(*this->window);
	this->renderHpBar(*this->window);
	this->renderText(*this->window);
	//exit button
	this->window->draw(this->exitButton2);
	this->window->draw(this->exitButtonText2);
	this->window->display();
}

void Game::renderWorld(sf::RenderTarget& target)
{
	target.draw(this->world);
}

void Game::renderText(sf::RenderTarget &target)
{
	target.draw(this->uiText);
}

void Game::renderPlayer(sf::RenderTarget& target)
{
	target.draw(this->player);
}
void Game::renderStart()
{
	this->window->clear();
	this->window->draw(this->menuBackground);
	this->window->draw(this->startButton);
	this->window->draw(this->exitButton);
	this->window->draw(this->startButtonText);
	this->window->draw(this->exitButtonText);
	if(this->level==1)
		this->window->draw(this->instruction1);
	this->window->display();
}
void Game::renderRestartButton()
{
	this->window->clear();
	this->window->draw(this->menuBackground);
	this->window->draw(this->restartButton);
	this->window->draw(this->exitButton);
	this->window->draw(this->restartButtonText);
	this->window->draw(this->exitButtonText);
	this->window->draw(this->instruction2);
	this->window->display();
}
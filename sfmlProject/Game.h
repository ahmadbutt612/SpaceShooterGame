#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
//Class that acts as game engine
struct Game
{
private:
	//variables
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;
	//Mouse Position
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	//Resources
	sf::Font font;
	//Text
	sf::Text uiText;
	//Game Logic
	unsigned int points;
	int lives;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;
	bool mouseHeld;
	bool endGame;
	int fireCooldown;
	int burnCooldown;
	int boost;
	int playerBurnCooldown;
	bool ifRenderPlayerBurn;
	int level;
	float speed;
	int specialProbability;
	bool start;
	bool alive;
	bool restart;
	int totalPoints;
	int highScore;
	//Game Objects
	sf::RectangleShape hpBar;
	sf::RectangleShape hpBarBack;
	sf::Sprite world;
	sf::Texture worldTexture;
	std::vector<sf::Sprite> enemies;
	sf::Sprite enemy;
	sf::Texture enemyTexture;
	sf::Sprite enemyBurn;
	sf::Texture enemyBurnTexture;
	std::vector<sf::Sprite> Burns;
	std::vector<int> burnCounter;
	sf::Sprite player;
	sf::Texture playerTexture;
	sf::Sprite fire;
	sf::Texture fireTexture;
	std::vector<sf::Sprite> Fires;
	sf::Sprite powerUp;
	sf::Texture powerUpTexture;
	std::vector<sf::Sprite> PowerUps;
	sf::Sprite playerBurn;
	sf::Texture playerBurnTexture;
	sf::Sprite specialEnemy;
	sf::Texture specialEnemyTexture;
	std::vector<sf::Sprite> SpecialEnemies;
	std::vector<int> SpecialEnemiesHealth;
	sf::RectangleShape menu;
	sf::RectangleShape startButton;
	sf::Text startButtonText;
	sf::RectangleShape restartButton;
	sf::Text restartButtonText;
	sf::RectangleShape exitButton;
	sf::Text exitButtonText;
	sf::RectangleShape exitButton2;
	sf::Text exitButtonText2;
	sf::Text instruction1;
	sf::Text instruction2;
	sf::Sprite menuBackground;
	sf::Texture menuBackgroundTexture;

	//Private Functions
	void initWorld();
	void initVariables();
	void initWindow();
	void initSprite();
	void initPlayer();
	void initFonts();
	void initText();
	void initTexture();
	void initFire();
	void initEnemyBurn();
	void initPowerUp();
	void initHpBar();
	void initPlayerBurn();
	void initSpecialEnemy();
	void level1Variables();
	void level2Variables();
	void level3Variables();
	void level4Variables();
	void level5Variables();
	void initMenu();
	void initStartButtons();
public:
	//Levels
	void levelOne();
	void levelTwo();
	void levelThree();
	void levelFour();
	void levelFive();
	void clearEvery();
	void levelUp();
	bool getAlive();
	//Constructors/Destructors
	Game();
	virtual ~Game();
	//Accessors
	bool running();
	bool getEndGame();
	int getLevel();
	bool getStart();
	bool getRestart();
	//Functions
	void pollEvents();
	void spawnEnemy();
	void spawnSpecialEnemy();
	void updateMousePositions();
	void update();
	void updateText();
	void updatePlayer();
	void updateEnemies();
	void updateEnemyBurn();
	void updateFire();
	void updatePowerUp();
	void updateHpBar();
	void updatePlayerBurn();
	void updateSpecialEnemy();
	void updateStart();
	void updateStartButtonText();
	void updateRestartButton();
	void updateInstruction2();
	void render();
	void renderWorld(sf::RenderTarget& target);
	void renderText(sf::RenderTarget& target);
	void renderPlayer(sf::RenderTarget& target);
	void renderEnemies(sf::RenderTarget& target);
	void renderEnemyBurn(sf::RenderTarget& target);
	void renderFire(sf::RenderTarget& target);
	void renderPowerUp(sf::RenderTarget& target);
	void renderHpBar(sf::RenderTarget& target);
	void renderPlayerBurn(sf::RenderTarget& target,bool ifRenderPlayerBurn);
	void renderSpecialEnemy(sf::RenderTarget& target);
	void renderMenu(sf::RenderTarget& target);
	void renderStart();
	void renderRestartButton();
};


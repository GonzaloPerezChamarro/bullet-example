

#include "Game.hpp"

using namespace std;
using namespace example;

int main()
{
	Game * game = new Game("Bullet!!!!", 1920, 1080);

	game->init();

	return 0;
}
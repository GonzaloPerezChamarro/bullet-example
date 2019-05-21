

#include "Game.hpp"

using namespace std;
using namespace example;

int main()
{
	Game * game = new Game("Bullet!!!!", 1280, 720);

	game->init();

	return 0;
}
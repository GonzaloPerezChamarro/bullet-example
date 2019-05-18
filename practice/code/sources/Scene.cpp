

#include "Scene.hpp"
#include "Entity.hpp"
#include "Game.hpp"

namespace example
{
	Scene::Scene(int width, int height, float gravity)
		:width(width), height(height), gravity(gravity),
		game(nullptr), world(new World())
	{
		have_to_reset = false;
	}

	Scene::~Scene()
	{
		entities_map.clear();
	}

	void Scene::update(float deltaTime)
	{
		for (auto it = entities_map.begin(), end = entities_map.end();
			it != end;
			++it)
		{
			it->second->update(deltaTime);
		}

		if (have_to_reset) reset();

		world->update(deltaTime);

	}

	void Scene::render(sf::RenderWindow & renderer)
	{
		for (auto it = entities_map.begin(), end = entities_map.end();
			it != end;
			++it)
		{
			it->second->render(renderer);
		}
	}

	void Scene::add_entity(const std::string name, const sh_Entity & entity)
	{
		entities_map[name] = entity;
	}

	Entity * Scene::get_entity_by_name(const std::string & name)
	{
		return entities_map.find(name)->second.get();
	}

	void Scene::reset()
	{
		if (game) game->reset();
		have_to_reset = false;
	}
}
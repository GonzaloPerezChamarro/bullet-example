

#include "Scene.hpp"
#include "..\headers\Cube.hpp"
#include "Sphere.hpp"

#include "Game.hpp"

namespace example
{
	Scene::Scene(int width, int height, float gravity)
		:width(width), height(height), gravity(gravity),
		game(nullptr), world(new World), renderer(new glt::Render_Node),
		camera(new glt::Camera(20.f, 1.f, 50.f, 1.f)), light(new glt::Light)
	{
		have_to_reset = false;

		renderer->add("camera", camera);
		renderer->add("light", light);

		renderer->get("light")->translate(glt::Vector3(10.f, 10.f, 10.f));
		renderer->get("camera")->translate(glt::Vector3(0.f, 0.f, 5.f));

		renderer->get_active_camera()->set_aspect_ratio(float(width) / height);

		std::shared_ptr<Sphere> sphere(new Sphere(this, btVector3(0.f, 10.f, 0.f), btQuaternion::getIdentity()));
		entities_map["sphere"] = sphere;
	}

	Scene::~Scene()
	{
		entities_map.clear();
	}

	void Scene::update(float deltaTime)
	{
		world->update(deltaTime);

		for (auto it = entities_map.begin(), end = entities_map.end();
			it != end;
			++it)
		{
			it->second->update(deltaTime);
		}

		if (have_to_reset) reset();

	}

	void Scene::render()
	{
		renderer->render();
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


#include "Scene.hpp"

#include "..\headers\Cube.hpp"
#include "Sphere.hpp"
#include "Wall.hpp"
#include "Key.hpp"
#include "Door.hpp"
#include "Catapult.hpp"

#include "Game.hpp"

namespace example
{
	Scene::Scene(int width, int height, float gravity)
		:width(width), height(height), gravity(gravity),
		game(nullptr), world(new World), renderer(new glt::Render_Node),
		camera(new glt::Camera(20.f, 1.f, 50.f, 1.f)), light(new glt::Light)
	{
		have_to_reset = false;

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
			it->second->input(deltaTime);
		}

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

	void Scene::create_scene()
	{

		renderer->add("camera", camera);
		renderer->add("light", light); 

		renderer->get("light")->translate(glt::Vector3(10.f, 10.f, 10.f));
		renderer->get("camera")->translate(glt::Vector3(0.f, 0.f, 5.f));

		renderer->get_active_camera()->set_aspect_ratio(float(width) / height);


		{
			//Derecha
			std::shared_ptr<Cube> cubeDer(new Cube(this, btVector3(5.f, -2.f, 0.f), btQuaternion::getIdentity()));
			entities_map["cubeDer"] = cubeDer;

			std::shared_ptr<Cube> cubeDerA(new Cube(this, btVector3(5.f, -2.f, -1.f), btQuaternion::getIdentity()));
			entities_map["cubeDerA"] = cubeDerA;

			std::shared_ptr<Cube> cubeDerB(new Cube(this, btVector3(5.f, -2.f, -2.f), btQuaternion::getIdentity()));
			entities_map["cubeDerB"] = cubeDerB;

			//Izquierda
			std::shared_ptr<Cube> cubeIzq(new Cube(this, btVector3(-4.f, -2.f, 0.f), btQuaternion::getIdentity()));
			entities_map["cubeIzq"] = cubeIzq;

			std::shared_ptr<Cube> cubeIzqA(new Cube(this, btVector3(-4.f, -2.f, -1.f), btQuaternion::getIdentity()));
			entities_map["cubeIzqA"] = cubeIzqA;

			std::shared_ptr<Cube> cubeIzqB(new Cube(this, btVector3(-4.f, -2.f, -2.f), btQuaternion::getIdentity()));
			entities_map["cubeIzqB"] = cubeIzqB;

			//Centro 1
			std::shared_ptr<Cube> cubeCentro(new Cube(this, btVector3(0.f, -2.f, 0.f), btQuaternion::getIdentity()));
			entities_map["cubeCentro"] = cubeCentro;

			std::shared_ptr<Cube> cubeCentroA(new Cube(this, btVector3(0.f, -2.f, -1.f), btQuaternion::getIdentity()));
			entities_map["cubeCentroA"] = cubeCentroA;

			std::shared_ptr<Cube> cubeCentroB(new Cube(this, btVector3(0.f, -2.f, -2.f), btQuaternion::getIdentity()));
			entities_map["cubeCentroB"] = cubeCentroB;

			//Centro 2
			std::shared_ptr<Cube> cubeCentro1(new Cube(this, btVector3(1.f, -2.f, 0.f), btQuaternion::getIdentity()));
			entities_map["cubeCentro1"] = cubeCentro1;

			std::shared_ptr<Cube> cubeCentro1A(new Cube(this, btVector3(1.f, -2.f, -1.f), btQuaternion::getIdentity()));
			entities_map["cubeCentro1A"] = cubeCentro1A;

			std::shared_ptr<Cube> cubeCentro1B(new Cube(this, btVector3(1.f, -2.f, -2.f), btQuaternion::getIdentity()));
			entities_map["cubeCentro1B"] = cubeCentro1B;
		}

		std::shared_ptr<Wall> wall(new Wall(this, btVector3(-4.f, 0.f, -1.f), btQuaternion::getIdentity(), Rigidbody::Type::DYNAMIC));
		entities_map["wall"] = wall;

		std::shared_ptr<Wall> wallIzq(new Wall(this, btVector3(0.f, 0.f, 0.f), btQuaternion::getIdentity(), Rigidbody::Type::STATIC));
		entities_map["wallIzq"] = wallIzq;

		std::shared_ptr<Wall> wallDer(new Wall(this, btVector3(0.f, 0.f, -2.f), btQuaternion::getIdentity(), Rigidbody::Type::STATIC));
		entities_map["wallDer"] = wallDer;

		std::shared_ptr<Door> door(new Door(this, btVector3(0.f, 0.f, -1.f), btQuaternion::getIdentity()));
		entities_map["door"] = door;

		std::shared_ptr<Key> key(new Key(this, btVector3(1.f, -0.3f, -1.f), btQuaternion::getIdentity(), *door));
		entities_map["key"] = key;

		std::shared_ptr<Catapult> catapult(new Catapult(this, btVector3(5.f, 0.f, -1.f), btQuaternion::getIdentity()));
		entities_map["catapult"] = catapult;
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
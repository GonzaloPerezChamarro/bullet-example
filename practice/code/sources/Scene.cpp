

#include "Scene.h"

#include "..\headers\Cube.h"
#include "Sphere.h"
#include "Wall.h"
#include "Key.h"
#include "Door.h"
#include "Catapult.h"
#include "Platform.h"

#include "Game.h"

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

		input(deltaTime);

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
		renderer->get("camera")->translate(glt::Vector3(7.f, 0.f, 8.f));

		renderer->get_active_camera()->set_aspect_ratio(float(width) / height);

		// SIDES
		{
			// RIGHT
			std::shared_ptr<Cube> cubeDer(new Cube(this, btVector3(9.f, -2.f, 0.f), btQuaternion::getIdentity()));
			entities_map["cubeDer"] = cubeDer;

			std::shared_ptr<Cube> cubeDerA(new Cube(this, btVector3(9.f, -2.f, -1.f), btQuaternion::getIdentity()));
			entities_map["cubeDerA"] = cubeDerA;

			std::shared_ptr<Cube> cubeDerB(new Cube(this, btVector3(9.f, -2.f, -2.f), btQuaternion::getIdentity()));
			entities_map["cubeDerB"] = cubeDerB;

			std::shared_ptr<Cube> cubeDer1(new Cube(this, btVector3(10.f, -2.f, 0.f), btQuaternion::getIdentity()));
			entities_map["cubeDer1"] = cubeDer1;

			std::shared_ptr<Cube> cubeDer1A(new Cube(this, btVector3(10.f, -2.f, -1.f), btQuaternion::getIdentity()));
			entities_map["cubeDer1A"] = cubeDer1A;

			std::shared_ptr<Cube> cubeDer1B(new Cube(this, btVector3(10.f, -2.f, -2.f), btQuaternion::getIdentity()));
			entities_map["cubeDer1B"] = cubeDer1B;

			// LEFT
			std::shared_ptr<Cube> cubeIzq(new Cube(this, btVector3(-5.f, -2.f, 0.f), btQuaternion::getIdentity()));
			entities_map["cubeIzq"] = cubeIzq;

			std::shared_ptr<Cube> cubeIzqA(new Cube(this, btVector3(-5.f, -2.f, -1.f), btQuaternion::getIdentity()));
			entities_map["cubeIzqA"] = cubeIzqA;

			std::shared_ptr<Cube> cubeIzqB(new Cube(this, btVector3(-5.f, -2.f, -2.f), btQuaternion::getIdentity()));
			entities_map["cubeIzqB"] = cubeIzqB;
		}
		// CENTER
		{
			// CENTER 1
			std::shared_ptr<Cube> cubeCentro(new Cube(this, btVector3(0.f, -2.f, 0.f), btQuaternion::getIdentity()));
			entities_map["cubeCentro"] = cubeCentro;

			std::shared_ptr<Cube> cubeCentroA(new Cube(this, btVector3(0.f, -2.f, -1.f), btQuaternion::getIdentity()));
			entities_map["cubeCentroA"] = cubeCentroA;

			std::shared_ptr<Cube> cubeCentroB(new Cube(this, btVector3(0.f, -2.f, -2.f), btQuaternion::getIdentity()));
			entities_map["cubeCentroB"] = cubeCentroB;

			std::shared_ptr<Cube> cubeCentroC(new Cube(this, btVector3(0.f, -2.f, 1.f), btQuaternion::getIdentity()));
			entities_map["cubeCentroC"] = cubeCentroC;

			std::shared_ptr<Cube> cubeCentroD(new Cube(this, btVector3(0.f, -2.f, -3.f), btQuaternion::getIdentity()));
			entities_map["cubeCentroD"] = cubeCentroD;

			// CENTER 2
			std::shared_ptr<Cube> cubeCentro1(new Cube(this, btVector3(1.f, -2.f, 0.f), btQuaternion::getIdentity()));
			entities_map["cubeCentro1"] = cubeCentro1;

			std::shared_ptr<Cube> cubeCentro1A(new Cube(this, btVector3(1.f, -2.f, -1.f), btQuaternion::getIdentity()));
			entities_map["cubeCentro1A"] = cubeCentro1A;

			std::shared_ptr<Cube> cubeCentro1B(new Cube(this, btVector3(1.f, -2.f, -2.f), btQuaternion::getIdentity()));
			entities_map["cubeCentro1B"] = cubeCentro1B;

			std::shared_ptr<Cube> cubeCentro1C(new Cube(this, btVector3(1.f, -2.f, 1.f), btQuaternion::getIdentity()));
			entities_map["cubeCentro1C"] = cubeCentro1C;

			std::shared_ptr<Cube> cubeCentro1D(new Cube(this, btVector3(1.f, -2.f, -3.f), btQuaternion::getIdentity()));
			entities_map["cubeCentro1D"] = cubeCentro1D;

			// CENTER 3
			std::shared_ptr<Cube> cubeCentro3(new Cube(this, btVector3(2.f, -2.f, 0.f), btQuaternion::getIdentity()));
			entities_map["cubeCentro3"] = cubeCentro3;

			std::shared_ptr<Cube> cubeCentro3A(new Cube(this, btVector3(2.f, -2.f, -1.f), btQuaternion::getIdentity()));
			entities_map["cubeCentro3A"] = cubeCentro3A;

			std::shared_ptr<Cube> cubeCentro3B(new Cube(this, btVector3(2.f, -2.f, -2.f), btQuaternion::getIdentity()));
			entities_map["cubeCentro3B"] = cubeCentro3B;

			std::shared_ptr<Cube> cubeCentro3C(new Cube(this, btVector3(2.f, -2.f, 1.f), btQuaternion::getIdentity()));
			entities_map["cubeCentro3C"] = cubeCentro3C;

			std::shared_ptr<Cube> cubeCentro3D(new Cube(this, btVector3(2.f, -2.f, -3.f), btQuaternion::getIdentity()));
			entities_map["cubeCentro3D"] = cubeCentro3D;

			// CENTER 4
			std::shared_ptr<Cube> cubeCentro4(new Cube(this, btVector3(3.f, -2.f, 0.f), btQuaternion::getIdentity()));
			entities_map["cubeCentro4"] = cubeCentro4;

			std::shared_ptr<Cube> cubeCentro4A(new Cube(this, btVector3(3.f, -2.f, -1.f), btQuaternion::getIdentity()));
			entities_map["cubeCentro4A"] = cubeCentro4A;

			std::shared_ptr<Cube> cubeCentro4B(new Cube(this, btVector3(3.f, -2.f, -2.f), btQuaternion::getIdentity()));
			entities_map["cubeCentro4B"] = cubeCentro4B;

			std::shared_ptr<Cube> cubeCentro4C(new Cube(this, btVector3(3.f, -2.f, 1.f), btQuaternion::getIdentity()));
			entities_map["cubeCentro4C"] = cubeCentro4C;

			std::shared_ptr<Cube> cubeCentro4D(new Cube(this, btVector3(3.f, -2.f, -3.f), btQuaternion::getIdentity()));
			entities_map["cubeCentro4D"] = cubeCentro4D;
		}

		// WALL TO HIT
		std::shared_ptr<Wall> wall(new Wall(this, btVector3(-5.5f, 0.f, -1.f), btQuaternion::getIdentity(), Rigidbody::Type::DYNAMIC));
		entities_map["wall"] = wall;

		// OTHER WALLS
		{
			std::shared_ptr<Wall> wallIzq(new Wall(this, btVector3(1.f, 0.f, 1.f), btQuaternion::getIdentity(), Rigidbody::Type::STATIC));
			entities_map["wallIzq"] = wallIzq;

			std::shared_ptr<Wall> wallDer(new Wall(this, btVector3(1.f, 0.f, -3.f), btQuaternion::getIdentity(), Rigidbody::Type::STATIC));
			entities_map["wallDer"] = wallDer;

			std::shared_ptr<Cube> c1(new Cube(this, btVector3(1, 1.1f, 1.9), btQuaternion::getIdentity(), Rigidbody::Type::STATIC));
			c1->set_model_scale("box", 0.1f);
			entities_map["c1"] = c1;

			std::shared_ptr<Cube> c2(new Cube(this, btVector3(1, 1.1f, 1.5), btQuaternion::getIdentity(), Rigidbody::Type::STATIC));
			c2->set_model_scale("box", 0.1f);
			entities_map["c2"] = c2;

			std::shared_ptr<Cube> c3(new Cube(this, btVector3(1, 1.1f, 1.1), btQuaternion::getIdentity(), Rigidbody::Type::STATIC));
			c3->set_model_scale("box", 0.1f);
			entities_map["c3"] = c3;

			std::shared_ptr<Cube> c4(new Cube(this, btVector3(1, 1.1f, 0.7), btQuaternion::getIdentity(), Rigidbody::Type::STATIC));
			c4->set_model_scale("box", 0.1f);
			entities_map["c4"] = c4;

			std::shared_ptr<Cube> c5(new Cube(this, btVector3(1, 1.1f, 0.3), btQuaternion::getIdentity(), Rigidbody::Type::STATIC));
			c5->set_model_scale("box", 0.1f);
			entities_map["c5"] = c5;

			std::shared_ptr<Cube> c1A(new Cube(this, btVector3(1, 1.1f, -3.9), btQuaternion::getIdentity(), Rigidbody::Type::STATIC));
			c1A->set_model_scale("box", 0.1f);
			entities_map["c1A"] = c1A;

			std::shared_ptr<Cube> c2A(new Cube(this, btVector3(1, 1.1f, -3.5), btQuaternion::getIdentity(), Rigidbody::Type::STATIC));
			c2A->set_model_scale("box", 0.1f);
			entities_map["c2A"] = c2A;

			std::shared_ptr<Cube> c3A(new Cube(this, btVector3(1, 1.1f, -3.1), btQuaternion::getIdentity(), Rigidbody::Type::STATIC));
			c3A->set_model_scale("box", 0.1f);
			entities_map["c3A"] = c3A;

			std::shared_ptr<Cube> c4A(new Cube(this, btVector3(1, 1.1f, -2.7), btQuaternion::getIdentity(), Rigidbody::Type::STATIC));
			c4A->set_model_scale("box", 0.1f);
			entities_map["c4A"] = c4A;

			std::shared_ptr<Cube> c5A(new Cube(this, btVector3(1, 1.1f, -2.3), btQuaternion::getIdentity(), Rigidbody::Type::STATIC));
			c5A->set_model_scale("box", 0.1f);
			entities_map["c5A"] = c5A;
		}

		// DOOR AND KEY
		std::shared_ptr<Door> door(new Door(this, btVector3(1.f, 0.f, -1.f), btQuaternion::getIdentity()));
		entities_map["door"] = door;

		std::shared_ptr<Key> key(new Key(this, btVector3(2.1f, -0.3, -3.f), btQuaternion::getIdentity(), *door));
		entities_map["key"] = key;

		// CATAPULT
		std::shared_ptr<Catapult> catapult(new Catapult(this, btVector3(9.f, 0.f, 0.f), btQuaternion::getIdentity()));
		entities_map["catapult"] = catapult;

		// PLATFORM
		std::shared_ptr<Platform> platform(new Platform(this, btVector3(7, -1.20f, 0), btQuaternion::getIdentity(), btVector3(5, -1.20f, 0)));
		entities_map["platform"] = platform;
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

	void Scene::input(float deltaTime)
	{
		// Camera movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			renderer->get("camera")->translate(glt::Vector3(0.f, 0.f, -5.f) * deltaTime);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			renderer->get("camera")->translate(glt::Vector3(0.f, 0.f, 5.f) * deltaTime);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			renderer->get("camera")->translate(glt::Vector3(5.f, 0.f, 0.f) * deltaTime);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			renderer->get("camera")->translate(glt::Vector3(-5.f, 0.f, 0.f) * deltaTime);
		}

		// Camera height
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
		{
			renderer->get("camera")->translate(glt::Vector3(0.f, 5.f, 0.f) * deltaTime);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
		{
			renderer->get("camera")->translate(glt::Vector3(0.f, -5.f, 0.f) * deltaTime);
		}

		// Camera rotation
		static float rotation = 0;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) // right
		{
			rotation += deltaTime * 5;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) // left
		{
			rotation -= deltaTime * 5;
		}
		else
		{
			rotation = 0;
		}

		renderer->get("camera")->rotate_around_y(glm::radians(rotation));
	}
}

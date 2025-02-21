/**
 * @file Entity.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Base class of an entity. Other scene elements must inherit from it
 * @version 1.0
 * @date 2019-05-30
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef ENTITY_BULLET_HEADER
#define ENTITY_BULLET_HEADER


#include <map>
#include <string>
#include <iostream>

#include "Scene.h"
#include "Rigidbody.h"
#include "Sensor.h"
#include "SFML/Graphics.hpp"

#include <btBulletDynamicsCommon.h>
#include <Model_Obj.hpp>

using namespace std;

namespace example
{
	class Entity
	{
	protected:
		/* Pointer to game scene */
		Scene* scene;

		/* Initial position */
		btVector3 initial_position;

		/* Transform */
		btTransform transform;

		/* Struct that group a model with its rigidbody and scale */
		struct Model_Group
		{
			float scale = 1.f;
			std::shared_ptr<glt::Model> mesh;
			std::shared_ptr<Rigidbody> body;
		};

		/* Map of model groups */
		std::map<std::string, Model_Group> models;

		/* Map of sensors */
		std::map<std::string, std::shared_ptr<Sensor>> sensors;

		/* Map of contraints */
		std::map<std::string, std::shared_ptr<btHingeConstraint>> joints;

	public:
		/**
		 * @brief Constructor
		 * @param scene Pointer to game scene
		 * @param pos Initial position
		 * @param rot Initial rotation
		 */
		Entity(Scene * scene, btVector3 pos, btQuaternion rot)
			:scene(scene), initial_position(pos)
		{
			initial_position = pos;
		}

		/* Destructor */
		virtual ~Entity() {}

	public:
		/**
		 * @brief Updates the state of the entity
		 * @param deltatime 
		 */
		virtual void update(float deltatime);

		/* Virtual. Reset the entity to its initial state */
		virtual void reset() = 0;

		/**
		 * @brief Manages the inputs with keyboard and mouse
		 * @param deltatime 
		 */
		virtual void input(float deltatime) {}

	public:
		/**
		 * @brief Returns a rigidbody
		 * @param name of the model
		 * @return std::shared_ptr<Rigidbody> 
		 */
		std::shared_ptr<Rigidbody> get_rigidbody(const std::string & name)
		{
			return models[name].body;
		}

		/**
		 * @brief Returns a mesh
		 * @param name of the model
		 * @return std::shared_ptr<glt::Model> 
		 */
		std::shared_ptr<glt::Model> get_mesh(const std::string & name)
		{
			return models[name].mesh;
		}

		/**
		 * @brief Modifies the scale of a model
		 * @param name of the model
		 * @param new_scale new scale
		 */
		void set_model_scale(const std::string & name, const float new_scale) 
		{
			models[name].body->get_shape()->setLocalScaling(btVector3(new_scale, new_scale, new_scale));
			models[name].scale = new_scale;
		}

		/* Returns the current position of the entity */
		const btVector3 & get_current_position() const{ return transform.getOrigin(); }

		/* Returns the game scene */
		Scene * get_scene() const { return scene; }

		/**
		 * @brief Adds a new model
		 * @param name of the model
		 * @param rb rigidbody
		 * @param path to the model
		 * @param scale of the model
		 */
		void add_model(const std::string & name, std::shared_ptr<Rigidbody> & rb, const std::string & path, float scale = 1.f);

		/**
		 * @brief Adds a new sensor
		 * @param name of the model
		 * @param sensor pointer to the sensor
		 */
		void add_sensor(const std::string & name, std::shared_ptr<Sensor> & sensor);

		/**
		 * @brief Adds a new constraint
		 * @param name of the model
		 * @param joint constraint
		 */
		void add_joint(const std::string & name, std::shared_ptr<btHingeConstraint> & joint);

		// TODO: move it from here
		/* Returns if two vectors are equals with a tolerance */
		static bool near_equals(btVector3 vec1, btVector3 vec2, float tolerance)
		{
			float offset = abs(vec1.getX() - vec2.getX()) + abs(vec1.getY() - vec2.getY()) + abs(vec1.getZ() - vec2.getZ());
			return offset < tolerance;
		}
	};
}

#endif

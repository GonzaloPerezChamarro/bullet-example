/**
 * @file Entity.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase base de Entidad. Otros elementos de escena deben heredar
 * @version 0.1
 * @date 2019-05-30
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef ENTITY_BULLET_HEADER
#define ENTITY_BULLET_HEADER


#include <map>
#include <string>
#include <iostream>


#include "Scene.hpp"
#include "Rigidbody.hpp"
#include "Sensor.hpp"
#include "SFML/Graphics.hpp"

#include <btBulletDynamicsCommon.h>
#include <Model_Obj.hpp>



using namespace std;

namespace example
{
	class Entity
	{
	protected:
		/**
		 * @brief Puntero a la escena principal
		 * 
		 */
		Scene * scene;

		/**
		 * @brief Posicion inicial
		 * 
		 */
		btVector3 initial_position;

		/**
		 * @brief Transform de la entidad
		 * 
		 */
		btTransform transform;

		/**
		 * @brief Estructura que recoge los modelos, su rigidbody y su escala
		 * 
		 */
		struct Model_Group
		{
			float scale = 1.f;
			std::shared_ptr<glt::Model> mesh;
			std::shared_ptr<Rigidbody> body;
		};
		/**
		 * @brief Mapa de estructuras 
		 * 
		 */
		std::map<std::string, Model_Group> models;

		/**
		 * @brief Mapa de sensores
		 * 
		 */
		std::map<std::string, std::shared_ptr<Sensor>> sensors;

		/**
		 * @brief Mapa de constraint
		 * 
		 */
		std::map<std::string, std::shared_ptr<btHingeConstraint>> joints;


	public:
		/**
		 * @brief Constructor de Entity
		 * 
		 * @param scene 
		 * @param pos Posicion inicial
		 * @param rot Rotacion inicial
		 */
		Entity(Scene * scene, btVector3 pos, btQuaternion rot)
			:scene(scene), initial_position(pos)
		{
			initial_position = pos;
		}

		/**
		 * @brief Destructor de Entity
		 * 
		 */
		virtual ~Entity() {}

	public:
		/**
		 * @brief Actualiza el estado de la entidad
		 * 
		 * @param deltatime 
		 */
		virtual void update(float deltatime);

		/**
		 * @brief Resetea la entidad a su estadoo inicial
		 * 
		 */
		virtual void reset() = 0;

		/**
		 * @brief Gestiona las entradas de teclado o raton
		 * 
		 * @param deltatime 
		 */
		virtual void input(float deltatime) {}

	public:
		/**
		 * @brief Devuelve rigidbody 
		 * 
		 * @param name 
		 * @return std::shared_ptr<Rigidbody> 
		 */
		std::shared_ptr<Rigidbody> get_rigidbody(const std::string & name)
		{
			return models[name].body;
		}

		/**
		 * @brief Devuelve mesh 
		 * 
		 * @param name 
		 * @return std::shared_ptr<glt::Model> 
		 */
		std::shared_ptr<glt::Model> get_mesh(const std::string & name)
		{
			return models[name].mesh;
		}

		/**
		 * @brief Modifica el valor de model scale 
		 * 
		 * @param name 
		 * @param new_scale 
		 */
		void set_model_scale(const std::string & name, const float new_scale) 
		{
			models[name].body->get_shape()->setLocalScaling(btVector3(new_scale, new_scale, new_scale));
			models[name].scale = new_scale;
		}

		/**
		 * @brief Devuelve current position 
		 * 
		 * @return const btVector3& 
		 */
		const btVector3 & get_current_position() const{ return transform.getOrigin(); }

		/**
		 * @brief Devuelve scene 
		 * 
		 * @return Scene* 
		 */
		Scene * get_scene() const { return scene; }

		/**
		 * @brief Añade un nuevo modelo 
		 * 
		 * @param name 
		 * @param rb 
		 * @param path 
		 * @param scale 
		 */
		void add_model(const std::string & name, std::shared_ptr<Rigidbody> & rb, const std::string & path, float scale = 1.f);

		/**
		 * @brief Añade un nuevo sensor
		 * 
		 * @param name 
		 * @param sensor 
		 */
		void add_sensor(const std::string & name, std::shared_ptr<Sensor> & sensor);

		/**
		 * @brief Añade un nuevo constraint
		 * 
		 * @param name 
		 * @param joint 
		 */
		void add_joint(const std::string & name, std::shared_ptr<btHingeConstraint> & joint);

		/**
		 * @brief Indica si los dos vectores son iguales con una tolerancia
		 * 
		 * @param vec1 
		 * @param vec2 
		 * @param tolerance 
		 * @return true 
		 * @return false 
		 */
		bool near_equals(btVector3 vec1, btVector3 vec2, float tolerance)
		{
			float offset = abs(vec1.getX() - vec2.getX()) + abs(vec1.getY() - vec2.getY()) + abs(vec1.getZ() - vec2.getZ());
			return offset < tolerance;
		}
	};
}

#endif

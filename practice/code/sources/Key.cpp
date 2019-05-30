

#include "Key.hpp"

namespace example
{
	Key::Key(Scene * scene, btVector3 pos, btQuaternion rot, Door & door)
		:Entity(scene, pos, rot), door(&door), is_taken(false)
	{
		//Creacion de la llave
		std::shared_ptr<Rigidbody> key(new Rigidbody(pos, rot, std::shared_ptr<btCollisionShape>(new btSphereShape(btScalar(0.3f))), Rigidbody::Type::STATIC));
		add_model("key", key, "../../assets/key.obj", 1);

		//Sensor de recogida de la llave
		std::shared_ptr<Sensor> sensor(new Sensor(pos, rot, std::shared_ptr<btBoxShape>(new btBoxShape(btVector3(0.3, 0.3, 0.3)))));
		add_sensor("sensor", sensor);
	}

	void Key::update(float deltatime)
	{
		Entity::update(deltatime);

		//Si ya esta recogida, no realiza nada mas
		if (is_taken) return;

		//Comprueba el estado del sensor
		size_t overlapping_objects = sensors["sensor"]->get_sensor()->getNumOverlappingObjects();

		if (overlapping_objects > 0)
		{
			is_taken = true;

			//Recogida de la llave, y apertura de puerta
			get_mesh("key")->set_visible(false);
			get_rigidbody("key")->get_rigidbody()->setCollisionFlags(btCollisionObject::CF_NO_CONTACT_RESPONSE);

			door->get_rigidbody("door")->get_rigidbody()->setCollisionFlags(btCollisionObject::CF_NO_CONTACT_RESPONSE);
			door->get_mesh("door")->set_visible(false);
			

		}
	}
}
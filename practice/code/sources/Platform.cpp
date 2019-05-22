#include "Platform.hpp"


namespace example
{
	Platform::Platform(Scene * scene, btVector3 pos, btQuaternion rot, btVector3 target)
		:Entity(scene, pos, rot), target(target)
	{
		direction = target - pos;
		direction.normalize();

		std::shared_ptr<Rigidbody> body(new Rigidbody(pos, rot, std::shared_ptr<btBoxShape>(new btBoxShape(btVector3(1.f, 0.2f, 0.75f)))));
		add_model("body", body, "../../assets/platform.obj");

		std::shared_ptr<Sensor> sensor(new Sensor(pos + btVector3(0.f, 0.3f, 0.f), rot, std::shared_ptr<btBoxShape>(new btBoxShape(btVector3(.8f, 0.2f, 0.5f)))));
		add_sensor("sensor", sensor);
	}

	void Platform::update(float deltatime)
	{
		Entity::update(deltatime);

		//Movimiento....
	}

	void Platform::move_to_init()
	{
	}

	void Platform::move_to_target()
	{
	}

}

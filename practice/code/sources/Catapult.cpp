
#include "Catapult.hpp"


namespace example
{
	Catapult::Catapult(Scene * scene, btVector3 pos, btQuaternion rot)
		:Entity(scene, pos, rot)
	{
		std::shared_ptr<Rigidbody> body(new Rigidbody(pos, rot, std::shared_ptr<btBoxShape>(new btBoxShape(btVector3(0.7f, 0.1f, 0.4f)))));
		add_model("body", body, "../../assets/catapult_body.obj");

		std::shared_ptr<Rigidbody> wheel1(new Rigidbody(pos, rot, std::shared_ptr<btCollisionShape>(new btSphereShape(btScalar(0.1f)))));
		add_model("wheel1", wheel1, "../../assets/catapult_wheel.obj");

		std::shared_ptr<Rigidbody> wheel2(new Rigidbody(pos, rot, std::shared_ptr<btCollisionShape>(new btSphereShape(btScalar(0.1f)))));
		add_model("wheel2", wheel2, "../../assets/catapult_wheel.obj");

		std::shared_ptr<Rigidbody> wheel3(new Rigidbody(pos, rot, std::shared_ptr<btCollisionShape>(new btSphereShape(btScalar(0.1f)))));
		add_model("wheel3", wheel3, "../../assets/catapult_wheel.obj");

		std::shared_ptr<Rigidbody> wheel4(new Rigidbody(pos, rot, std::shared_ptr<btCollisionShape>(new btSphereShape(btScalar(0.1f)))));
		add_model("wheel4", wheel4, "../../assets/catapult_wheel.obj");

		std::shared_ptr<Rigidbody> arm(new Rigidbody(pos, rot, std::shared_ptr<btBoxShape>(new btBoxShape(btVector3(0.8, 0.1f, 0.1f)))));
		add_model("arm", arm, "../../assets/catapult_arm.obj");

		//Añadir pala....


	}

	void Catapult::fire()
	{
	}
}
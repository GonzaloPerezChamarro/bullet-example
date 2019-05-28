
#include "Catapult.hpp"


namespace example
{
	Catapult::Catapult(Scene * scene, btVector3 pos, btQuaternion rot)
		:Entity(scene, pos, rot)
	{
		std::shared_ptr<Rigidbody> body(new Rigidbody(pos, rot, std::shared_ptr<btBoxShape>(new btBoxShape(btVector3(0.7f, 0.1f, 0.4f)))));

		add_model("body", body, "../../assets/catapult_body.obj");

		std::shared_ptr<Rigidbody> wheel1(new Rigidbody(pos + btVector3(0.4,0,0.4), rot, std::shared_ptr<btCollisionShape>(new btSphereShape(btScalar(0.1f)))));
		wheel1->get_rigidbody()->setFriction(0.5);
		add_model("wheel1", wheel1, "../../assets/catapult_wheel.obj");

		std::shared_ptr<Rigidbody> wheel2(new Rigidbody(pos + btVector3(-0.4, 0, 0.4), rot, std::shared_ptr<btCollisionShape>(new btSphereShape(btScalar(0.1f)))));
		wheel2->get_rigidbody()->setFriction(0.5);
		add_model("wheel2", wheel2, "../../assets/catapult_wheel.obj");

		std::shared_ptr<Rigidbody> wheel3(new Rigidbody(pos + btVector3(0.4, 0, -0.4), rot, std::shared_ptr<btCollisionShape>(new btSphereShape(btScalar(0.1f)))));
		wheel3->get_rigidbody()->setFriction(0.3);
		add_model("wheel3", wheel3, "../../assets/catapult_wheel.obj");

		std::shared_ptr<Rigidbody> wheel4(new Rigidbody(pos + btVector3(-0.4, 0, -0.4), rot, std::shared_ptr<btCollisionShape>(new btSphereShape(btScalar(0.1f)))));
		wheel4->get_rigidbody()->setFriction(0.3);
		add_model("wheel4", wheel4, "../../assets/catapult_wheel.obj");

		std::shared_ptr<Rigidbody> arm(new Rigidbody(pos + btVector3(0, 0.2, 0), rot, std::shared_ptr<btBoxShape>(new btBoxShape(btVector3(0.8, 0.1f, 0.1f)))));
		add_model("arm", arm, "../../assets/catapult_arm.obj");

		//Añadir pala....

		std::shared_ptr<btHingeConstraint> joint1(new btHingeConstraint(* models["body"].body->get_rigidbody(), * models["wheel1"].body->get_rigidbody(),
			btVector3(-0.4, -0.2, 0.5), btVector3(0, 0, 0),
			btVector3(0, 0, 1), btVector3(0, 0, 1)));
		joint1->enableAngularMotor(false, 0.f, 3.0);
		add_joint("joint1", joint1);

		std::shared_ptr<btHingeConstraint> joint2(new btHingeConstraint(*models["body"].body->get_rigidbody(), *models["wheel2"].body->get_rigidbody(),
			btVector3(0.4, -0.2, 0.5), btVector3(0, 0, 0),
			btVector3(0, 0, 1), btVector3(0, 0, 1)));
		joint2->enableAngularMotor(false, 0.f, 3.0);
		add_joint("joint2", joint2);

		std::shared_ptr<btHingeConstraint> joint3(new btHingeConstraint(*models["body"].body->get_rigidbody(), *models["wheel3"].body->get_rigidbody(),
			btVector3(-0.4, -0.2, -0.5), btVector3(0, 0, 0),
			btVector3(0, 0, 1), btVector3(0, 0, 1)));
		joint3->enableAngularMotor(false, 0.f, 3.0);
		add_joint("joint3", joint3);

		std::shared_ptr<btHingeConstraint> joint4(new btHingeConstraint(*models["body"].body->get_rigidbody(), *models["wheel4"].body->get_rigidbody(),
			btVector3(0.4, -0.2, -0.5), btVector3(0, 0, 0),
			btVector3(0, 0, 1), btVector3(0, 0, 1)));
		joint4->enableAngularMotor(false, 0.f, 3.0);
		add_joint("joint4", joint4);

		std::shared_ptr<btHingeConstraint> joint5(new btHingeConstraint(*models["body"].body->get_rigidbody(), *models["arm"].body->get_rigidbody(),
			btVector3(0, 0.5, 0), btVector3(0, 0, 0),
			btVector3(0, 0, 1), btVector3(0, 0, 1)));
		joint5->enableAngularMotor(false, 0.f, 3.0);
		joint5->setLimit(-40, 40);
		add_joint("joint5", joint5);


	}

	void Catapult::input(float deltaTime)
	{
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			joints["joint1"]->enableMotor(true);
			joints["joint2"]->enableMotor(true);
			joints["joint3"]->enableMotor(true);
			joints["joint4"]->enableMotor(true);
			joints["joint1"]->setMotorTargetVelocity(-5.f);
			joints["joint2"]->setMotorTargetVelocity(-5.f);
			joints["joint3"]->setMotorTargetVelocity(-5.f);
			joints["joint4"]->setMotorTargetVelocity(-5.f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			joints["joint1"]->enableMotor(true);
			joints["joint2"]->enableMotor(true);
			joints["joint3"]->enableMotor(true);
			joints["joint4"]->enableMotor(true);
			joints["joint1"]->setMotorTargetVelocity(5.f);
			joints["joint2"]->setMotorTargetVelocity(-5.f);
			joints["joint3"]->setMotorTargetVelocity(5.f);
			joints["joint4"]->setMotorTargetVelocity(-5.f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			joints["joint1"]->enableMotor(true);
			joints["joint2"]->enableMotor(true);
			joints["joint3"]->enableMotor(true);
			joints["joint4"]->enableMotor(true);
			joints["joint1"]->setMotorTargetVelocity(-5.f);
			joints["joint2"]->setMotorTargetVelocity(5.f);
			joints["joint3"]->setMotorTargetVelocity(-5.f);
			joints["joint4"]->setMotorTargetVelocity(5.f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			joints["joint1"]->enableMotor(true);
			joints["joint2"]->enableMotor(true);
			joints["joint3"]->enableMotor(true);
			joints["joint4"]->enableMotor(true);
			joints["joint1"]->setMotorTargetVelocity(5.f);
			joints["joint2"]->setMotorTargetVelocity(5.f);
			joints["joint3"]->setMotorTargetVelocity(5.f);
			joints["joint4"]->setMotorTargetVelocity(5.f);
		}
		else
		{
			joints["joint1"]->enableMotor(false);
			joints["joint2"]->enableMotor(false);
			joints["joint3"]->enableMotor(false);
			joints["joint4"]->enableMotor(false);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			joints["joint5"]->enableMotor(true);
			joints["joint5"]->setMotorTargetVelocity(-10.f);
		}
		else
		{
			//joints["joint5"]->enableMotor(true);
			//joints["joint5"]->setMotorTargetVelocity(0.f);

		}
	}

	void Catapult::fire()
	{
	}
}
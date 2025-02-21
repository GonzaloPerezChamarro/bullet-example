

#include "Platform.h"
#include <iostream>

namespace example
{
	Platform::Platform(Scene * scene, btVector3 pos, btQuaternion rot, btVector3 target)
		:Entity(scene, pos, rot), target(target), stopped(true), have_to_move(false), was_object(false),
		current_time(0.f)
	{
		// Direction to move
		direction = target - pos;
		direction.normalize();

		// Create the platform
		std::shared_ptr<Rigidbody> body(new Rigidbody(pos, rot, std::shared_ptr<btBoxShape>(new btBoxShape(btVector3(1.f, 0.2f, 0.75f))), Rigidbody::Type::DYNAMIC));

		body->get_rigidbody()->setLinearFactor(btVector3(1, 0, 0)); // Should be modified according the direction
		body->get_rigidbody()->setAngularFactor(btVector3(0.f, 0.f, 0.f));
		body->get_rigidbody()->setFriction(0.8f);

		add_model("body", body, "../../assets/platform.obj");

		// Platform trigger
		std::shared_ptr<Sensor> sensor(new Sensor(pos + btVector3(0.f, 0.4f, 0.f), rot, std::shared_ptr<btBoxShape>(new btBoxShape(btVector3(0.8f, 0.2f, 0.5f)))));
		add_sensor("sensor", sensor);
	}

	void Platform::update(float deltatime)
	{
		check_sensor();

		// If something actives the trigger, move
		if (was_object)
		{
			current_time += deltatime;
			if (current_time >= delay)
				set_have_to_move(true);
		}

		// Movement
		if (have_to_move)
		{
			move_to_target(deltatime);
		}
		else
		{
			move_to_init(deltatime);
		}

		Entity::update(deltatime);
	}

	void Platform::move_to_init(float deltaTime)
	{
		// Moves while is not on the origin
		if (!near_equals(models["body"].body->get_rigidbody()->getWorldTransform().getOrigin(), initial_position, 0.01f))
		{
			models["body"].body->get_rigidbody()->setLinearVelocity(-direction * speed);

			sensors["sensor"]->get_sensor()->getWorldTransform().setOrigin(models["body"].body->get_rigidbody()->getWorldTransform().getOrigin() + btVector3(0, 0.3, 0));
		}
		else if (!stopped)
		{
			models["body"].body->get_rigidbody()->getWorldTransform().setOrigin(initial_position);

			stopped = true;

			sensors["sensor"]->get_sensor()->getWorldTransform().setOrigin(models["body"].body->get_rigidbody()->getWorldTransform().getOrigin() + btVector3(0, 0.3, 0));
		}
	}

	void Platform::move_to_target(float deltaTime)
	{
		// Moves while is not on the target
		if (!near_equals(models["body"].body->get_rigidbody()->getWorldTransform().getOrigin(), target, 0.01f))
		{
			models["body"].body->get_rigidbody()->setLinearVelocity(direction * speed);

			sensors["sensor"]->get_sensor()->getWorldTransform().setOrigin(models["body"].body->get_rigidbody()->getWorldTransform().getOrigin() + btVector3(0, 0.3, 0));
		}
		else if (!stopped)
		{
			models["body"].body->get_rigidbody()->getWorldTransform().setOrigin(target);

			stopped = true;

			sensors["sensor"]->get_sensor()->getWorldTransform().setOrigin(models["body"].body->get_rigidbody()->getWorldTransform().getOrigin() + btVector3(0, 0.3, 0));
		}
	}

	void Platform::check_sensor()
	{
		// Check overlapping objects
		const size_t overlapping_objects = sensors["sensor"]->get_sensor()->getNumOverlappingObjects();

		if (overlapping_objects > 1)
		{
			if (!was_object)
				current_time = 0.f;
			was_object = true;
		}
		else if(was_object)
		{
			was_object = false;
			current_time = 0.f;
			set_have_to_move(false);
		}
	}

	void Platform::set_have_to_move(bool b)
	{
		have_to_move = b;
		stopped = false;
	}
}

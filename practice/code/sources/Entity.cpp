
#include "Entity.hpp"


namespace example
{
	void Entity::update(float deltatime)
	{
		for (auto & model : models)
		{
			btTransform tr;

			model.second.body->get_rigidbody()->getMotionState()->getWorldTransform(tr);

			glm::mat4 graphics_transform;

			tr.getOpenGLMatrix(glm::value_ptr(graphics_transform));

			model.second.mesh->set_transformation(graphics_transform);
			model.second.mesh->scale(model.second.scale);
		}
	}

	void Entity::add_model(const std::string & name, std::shared_ptr<Rigidbody>& rb, const std::string & path, float scale)
	{
		std::shared_ptr<glt::Model> n(new glt::Model_Obj(path));

		models[name] = Model_Group{ scale, n, rb };


		for (int i = 0; ; ++i)
		{
			if (scene->get_renderer()->get(name + char(i)) == nullptr)
			{
				scene->get_renderer()->add(name + char(i), n);
				break;
			}
		}
		scene->get_world().add_rigidbody(rb);
		
	}

	void Entity::add_sensor(const std::string & name, std::shared_ptr<Sensor>& sensor)
	{

		sensors[name] = sensor;
		scene->get_world().add_sensor(sensor);
	}

}

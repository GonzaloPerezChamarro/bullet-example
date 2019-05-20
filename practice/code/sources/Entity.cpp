

#include "Entity.hpp"


namespace example
{
	void Entity::update(float deltatime)
	{
		for (auto & model : models)
		{
			btTransform tr;
			glm::mat4 graphics_transform;

			model.second.body->get_rigidbody()->getMotionState()->getWorldTransform(tr);

			tr.getOpenGLMatrix(glm::value_ptr(graphics_transform));

			model.second.mesh->set_transformation(graphics_transform);
			model.second.mesh->scale(model.second.scale);
		}
	}

	void Entity::add_model(const std::string & name, std::shared_ptr<Rigidbody>& rb, const std::string & path, float scale)
	{
		std::shared_ptr<glt::Model> new_model(new glt::Model_Obj(path));

		models[name] = Model_Group{ scale, new_model, rb };

		scene->get_renderer()->add(name, new_model);
		scene->get_world().add_rigidbody(rb);
		
	}

}
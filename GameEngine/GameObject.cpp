#include "GameObject.h"
//#include "Component.h"
//#include "Transform.h"
//#include "Sprite.h"
//#include "UpDown.h"
//#include "Controller.h"
#include <vector>

GameObject::GameObject()
{
	components = (new std::vector<Component*>);
	//components->reserve(NUMBER_OF_COMPONENTS);
	//t = components->begin();
}

GameObject::GameObject(Component* i)
{
	components = (new std::vector<Component*>(1, i));
	//components->reserve(NUMBER_OF_COMPONENTS);
	//t = components->end();
}

GameObject::GameObject(std::vector<Component*> * i)
{
	components = i;
	//components->reserve(NUMBER_OF_COMPONENTS);
	//t = components->end();
}


void GameObject::addComponent(Component* i)
{


	components->push_back(i);
	
	

}



Component* GameObject::getComponent(int type)
{
	if (components != NULL )//&& components->size() > 0)
	{
		for (int i = components->size()-1; i>=0; i--)
		{
			if (components->at(i)->getType() == type)
			{
				return components->at(i);

			}

		}
	}
	printf("ERROR:  no such component exists in this object.\n");
	return NULL;

}


std::vector<Component*> * GameObject::getComponentVector()
{
	return components;
}





void GameObject::setComponentVector(std::vector<Component*> i)
{
	for (int k = i.size(); k >= 0; k--)
	{
		components->push_back(i.at(k));
	}

}




Component* GameObject::getSprite()
{
	return getComponent(COMPONENT_TYPE_SPRITE);
}

Component* GameObject::getTransform()
{
	return getComponent(COMPONENT_TYPE_TRANSFORM);
}


Component* GameObject::getUpDown()
{
	return getComponent(COMPONENT_TYPE_UPDOWN);
}

Component* GameObject::getController()
{

	return getComponent(COMPONENT_TYPE_CONTROLLER);

}

void GameObject::update()
{
	for (int i = components->size()-1; i >= 0; i--)
	{
		if(components->at(i) != NULL)
		{components->at(i)->update();}
	}
}
/*

Sprite* GameObject::getSprite()
{
	for (int i = 0; i < components->size(); i++)
	{
		if (components->at(i)->getType() == COMPONENT_TYPE_SPRITE)
		{
			return (dynamic_cast<Sprite*>(components->at(i)));
		}
	}
}




Transform* GameObject::getTransform()
{
	for (int i = 0; i < components->size(); i++)
	{
		if (components->at(i)->getType() == COMPONENT_TYPE_TRANSFORM)
		{
			return (dynamic_cast<Transform*>(components->at(i)));
		}
	}
}



UpDown* GameObject::getUpDown()
{
	for (int i = 0; i < components->size(); i++)
	{
		if (components->at(i)->getType() == COMPONENT_TYPE_UPDOWN)
		{
			return (dynamic_cast<UpDown*>(components->at(i)));
		}
	}
}





Controller* GameObject::getController()
{
	for (int i = 0; i < components->size(); i++)
	{
		if (components->at(i)->getType() == COMPONENT_TYPE_CONTROLLER)
		{
			return (dynamic_cast<Controller*>(components->at(i)));
		}
	}
}
*/


GameObject::~GameObject()
{

}

#include "GameObject.h"
#include "Component.h"
#include "Transform.h"
#include "Sprite.h"
#include "UpDown.h"
#include "Controller.h"
#include <vector>

int GameObject::IDcounter = 0;

GameObject::GameObject()
{
	components = (new std::vector<Component*>);
	objectID = getCounter();
	incrementCounter();
	//components->reserve(NUMBER_OF_COMPONENTS);
	//t = components->begin();
}

GameObject::GameObject(Component* i)
{
	components = (new std::vector<Component*>(1, i));
	objectID = getCounter();
	incrementCounter();
	//components->reserve(NUMBER_OF_COMPONENTS);
	//t = components->end();
}

GameObject::GameObject(Component* i, int t)
{
	components = (new std::vector<Component*>(1, i));
	objectID = t;
	incrementCounter();
	//components->reserve(NUMBER_OF_COMPONENTS);
	//t = components->end();
}

GameObject::GameObject(std::vector<Component*> * i)
{
	components = i;
	objectID = getCounter();
	incrementCounter();
	//components->reserve(NUMBER_OF_COMPONENTS);
	//t = components->end();
}


GameObject::GameObject(std::vector<Component*> * i, int t)
{
	components = i;
	objectID = t;
	incrementCounter();
	//components->reserve(NUMBER_OF_COMPONENTS);
	//t = components->end();
}

void GameObject::addComponent(Component* i)
{


	components->push_back(i);
	
	

}

void GameObject::initializeCounter(int x)
{
	GameObject::IDcounter = x;
}

void GameObject::incrementCounter()
{
	GameObject::IDcounter++;
}

void GameObject::decrementCounter()
{
	GameObject::IDcounter--;
}

void GameObject::initializeCounter()
{
	initializeCounter(0);
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



int GameObject::getID()
{
	return objectID;
}

void GameObject::setID(int i)
{
	objectID = i;
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

int GameObject::getCounter()
{
	return GameObject::IDcounter;
}


GameObject::~GameObject()
{
	decrementCounter();
}


GameObject* GameObject::LoadObject(const char* filename)
{
	GameObject* obj = NULL;
	FILE * fp; 
	fopen_s(&fp, filename, "r");
	if (fp)
	{
		obj = new GameObject();
		while (!feof(fp))
		{
			char componentName[256];
			memset(componentName, 0, 256 * sizeof(char));
			fscanf_s(fp,"%255s\n", componentName, sizeof(componentName));

			if (0 == strcmp(componentName, "Transform"))
			{
				Transform* t = new Transform();
				t->serialize(&fp);
				t->setOwner(obj);
				obj->addComponent(t);
			}

			else if (0 == strcmp(componentName, "Sprite"))
			{
				Sprite * s = new Sprite();
				s->serialize(&fp);
				s->setOwner(obj);
				obj->addComponent(s);
			}

			else if (0 == strcmp(componentName, "Controller"))
			{
				Controller * c = new Controller();
				c->serialize(&fp);
				c->setOwner(obj);
				obj->addComponent(c);
			}

			else if (0 == strcmp(componentName, "UpDown"))
			{
				UpDown* u = new UpDown();
				u->serialize(&fp);
				u->setOwner(obj);
				obj->addComponent(u);
			}
		}
	}

	return obj;

}

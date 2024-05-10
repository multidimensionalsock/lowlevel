#include "Core/GameObject.h"

LLGP::GameObject::~GameObject()
{
	for (int i = 0; i < m_Components.size(); i++)
	{
		delete(m_Components[i]);
	}
}

void LLGP::GameObject::Colliding(bool isColliding, GameObject* other)
{
	if (other == nullptr) return;
	bool currentlyCollidingWith = false;
	auto collidingwithindex = std::find(_collidingWith.begin(), _collidingWith.end(), other);;
	
	if (collidingwithindex != _collidingWith.end())
	{
		currentlyCollidingWith = true;
	}
	
	if (currentlyCollidingWith && isColliding)
	{
		for (int i = 0; i < m_Components.size(); i++)
		{ 
			m_Components[i]->OnCollisionStay(other);
		}
		return;
	}
	else if (!currentlyCollidingWith && isColliding) 
	{
		_collidingWith.push_back(other);
		for (int i = 0; i < m_Components.size(); i++)
		{
			m_Components[i]->OnCollisionEnter(other);
		}
		return;
	}
	else if (!isColliding && currentlyCollidingWith) 
	{
		_collidingWith.erase(collidingwithindex);
		for (int i = 0; i < m_Components.size(); i++)
		{
			m_Components[i]->OnCollisionExit(other);
		}
		return;
	}
	
}

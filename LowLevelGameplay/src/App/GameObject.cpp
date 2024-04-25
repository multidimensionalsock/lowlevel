#include "Core/GameObject.h"

void LLGP::GameObject::Colliding(bool isColliding, GameObject* other)
{
	bool currentlyCollidingWith = false;
	int collidingwithindex = -1;
	if (_collidingWith.size() > 0)
	{
		for (int i = 0; i < m_Components.size(); i++)
		{
			if (_collidingWith[i] = &other->uuid)
			{
				currentlyCollidingWith = true;
				collidingwithindex = i;
				break;
			}
		}
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
		for (int i = 0; i < m_Components.size(); i++)
		{
			m_Components[i]->OnCollisionEnter(other);
		}
		_collidingWith.push_back(&other->uuid);
	}
	else if (currentlyCollidingWith && !isColliding) 
	{
		for (int i = 0; i < m_Components.size(); i++)
		{
			m_Components[i]->OnCollisionExit(other);
			//m_Components.erase(m_Components.begin() + i);
		}
		_collidingWith.erase(_collidingWith.begin() + collidingwithindex);
		
	}
	
}

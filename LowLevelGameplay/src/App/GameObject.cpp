#include "Core/GameObject.h"

void LLGP::GameObject::Colliding(bool isColliding, GameObject* other)
{
	if (_colliding && isColliding) 
	{
		for (int i = 0; i < m_Components.size(); i++)
		{
			m_Components[i]->OnCollisionStay(other);
		}
	}
	if (_colliding && !(isColliding))
	{
		for (int i = 0; i < m_Components.size(); i++)
		{
			m_Components[i]->OnCollisionExit();
		}
		_colliding = false;
	}
	if (!_colliding && isColliding)
	{
		for (int i = 0; i < m_Components.size(); i++)
		{
			m_Components[i]->OnCollisionEnter(other);
		}
		_colliding = true;
	}
	
}

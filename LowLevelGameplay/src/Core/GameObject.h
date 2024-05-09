#pragma once
#include "Core/Object.h"
#include "Core/component_concept.h"
#include "Core/Structs.h"

//#include "Core/MonoBehaviour.h"

class MonoBehaviour;



namespace LLGP 
{
	class GameObject : public Object
	{
	public:
		//GameObject();
		//GameObject(std::string name, std::string tag) { m_Name = name; m_Tag = tag; }
		GameObject(SceneManager* _sceneManager) { sceneManager = _sceneManager; }
		GameObject(const GameObject&) = default;
		~GameObject();
		Transform transform;
		inline void SetName(std::string newName) { m_Name = newName; }
		inline std::string GetName() { return m_Name; }

		void SetActive(bool newActive) { m_Active == newActive; };
		inline bool GetActive() { return m_Active; }

		inline void SetTag(std::string newTag) { m_Tag = newTag; }
		inline std::string GetTag() { return m_Tag; }
		inline bool CompareTag(std::string comp) { return m_Tag == comp; }

		void Colliding(bool isColliding, GameObject* other);

		SceneManager* sceneManager;

		template<class T> requires isComponent<T> T* GetComponent()
		{
			T* component;
			for (int i = 0; i < m_Components.size(); i++)
			{
				component = dynamic_cast<T*>(m_Components[i]);
				if (component != nullptr)
				{
					return component;
				}
			}
			return nullptr;
		}

		template<class T> requires isComponent<T> T* AddComponent()
		{
			{
				T* newComp = new T(this);
				m_Components.push_back(newComp);
				return newComp;
			}
		}

		template<class T> requires isComponent<T> bool RemoveComponent(T* comp)
		{
			T* component;
			for (int i = 0; i < m_Components.size(); i++)
			{
				component = dynamic_cast<T*>(m_Components[i]);
				if (component != nullptr)
				{
					m_Components.erase(m_Components.begin() + i);
					return true;
				}
			}
			return false;
		};

		std::vector<GameObject*> _collidingWith;

	private:
		std::string m_Name;
		bool m_Active;
		std::string m_Tag;
		std::vector<LLGP::MonoBehaviour*> m_Components;
		bool _colliding;

		

	public:
		inline bool operator==(const GameObject& other) { return this->uuid == other.uuid; }
		inline bool operator!=(const GameObject& other) { return !(*this == other); }
	};

}

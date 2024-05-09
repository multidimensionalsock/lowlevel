#pragma once
#include <Core/arithmetic_concept.h>
#include <SFML/Graphics.hpp>

namespace LLGP 
{
	template<typename T> requires arithmetic<T>
	struct Vector2 
	{
	public:
		T x, y;

#pragma region constructors
		Vector2() : x(0), y(0) {}
		Vector2(const Vector2&) = default;
		Vector2(T _x, T _y) : x(_x), y(_y) {}

		template<typename U> requires arithmetic<U>
		explicit Vector2(const Vector2<U>& in) : x(static_cast<T>(in.x)), y(static_cast<T>(in.y)) {}

		template<typename U> requires arithmetic<U>
		operator sf::Vector2<U>() { return sf::Vector2<U>(static_cast<U>(x), static_cast<U>(y)); }

#pragma endregion

#pragma region functionality
		float GetSqrMagnitude() 
		{ 
			return x * x + y + y;
		}

		float GetMagnitude() 
		{
			return sqrt(GetSqrMagnitude()); 
		}

		Vector2<T>& Normalise() 
		{ 
			float mag = this->GetMagnitude();
			this->x = x / mag;
			this->y = y / mag; 
			return this;
		}
		Vector2<T> Normalised() 
		{ 
			Vector2<float> temp = Vector2<float>::zero;
			float mag = this->GetMagnitude();
			temp->x = x / mag;
			temp->y = y / mag;

			return temp; 
		}

		float Distance(Vector2<T> rhs, Vector2<T> lhs) 
		{
			float x = rhs.x - lhs.x;
			float y = rhs.y - lhs.y;
			float distance = sqrt((x * x) + (y * y));
			return distance;
		}

		//static = only storedin memory one time even if theres 100000 vector2s
		static float Dot(const Vector2<T>& lhs, const Vector2<T>& rhs) { return (float)(lhs.x * rhs.x + lhs.y * rhs.y); }
		static float Angle(const Vector2<T>& lhs, const Vector2<T>& rhs) { return acos(Dot(lhs.Normalised(), rhs.Normalised())); }

		static const Vector2 zero;
		static const Vector2 one;
		static const Vector2 left;
		static const Vector2 right;
		static const Vector2 up;
		static const Vector2 down;

#pragma endregion
	};

	template<typename T> requires arithmetic<T>
	Vector2<T> operator - (Vector2<T>& lhs, const Vector2<T>& rhs) { return Vector2<T>(lhs.x -= rhs.x, lhs.y -= rhs.y); }

	template<typename T> requires arithmetic<T>
	Vector2<T>& operator -= (Vector2<T>& lhs, const Vector2<T>& rhs) { lhs.x -= rhs.x; lhs.y -= rhs.y; return *this; }

	template<typename T> requires arithmetic<T>
	Vector2<T>& operator += (Vector2<T>& lhs, const Vector2<T> rhs) { lhs.x += rhs.x; lhs.y += rhs.y; return lhs; }

	template<typename T> requires arithmetic<T>
	Vector2<T> operator + (const Vector2<T>& lhs, const Vector2<T>& rhs)
	{
		Vector2<T> result(lhs);
		result.x += rhs.x;
		result.y += rhs.y;
		return result;
	}

	template<typename T, typename U> requires arithmetic<T> and arithmetic<U>
	Vector2<T>& operator *= (Vector2<T> v, const U a) { v.x *= a; v.y *= a; return v; }


	template<typename T, typename U> requires arithmetic<T> and arithmetic<U>
	Vector2<T> operator * (Vector2<T> lhs, const U a) { return lhs *= a; }

	template<typename T, typename U> requires arithmetic<T> and arithmetic<U>
	Vector2<T> operator * (const U a, Vector2<T> v) { return v *= a; }

	

	//to do:
	//make /= and / versions 
	template<typename T, typename U> requires arithmetic<T> and arithmetic<U>
	Vector2<T>& operator /= (Vector2<T>& v, const U a) { v.x / a; v.y / a; return v; }

	template<typename T, typename U> requires arithmetic<T> and arithmetic<U>
	Vector2<T> operator / (Vector2<T> v, const U a) 
	{ 
		v.x / a;
		v.y / a;

		return v; 
	}

	template<typename T> requires arithmetic<T>
	inline bool operator == (Vector2<T>& lhs, const Vector2<T>& rhs) { Vector2<T> dist = lhs - rhs; float mag = dist.x * dist.x + dist.y * dist.y; return mag < 9.99999944E-11f; }

	template<typename T> requires arithmetic<T>
	inline bool operator != (Vector2<T>& lhs, const Vector2<T>& rhs) { return !(lhs == rhs); }

	template<typename T> requires arithmetic<T>
	const Vector2<T> Vector2<T>::zero(static_cast<T>(0), static_cast<T>(0));

	//implement other static const values 
	template<typename T> requires arithmetic<T>
	const Vector2<T> Vector2<T>::one(static_cast<T>(1), static_cast<T>(1));

	template<typename T> requires arithmetic<T>
	const Vector2<T> Vector2<T>::left(static_cast<T>(-1), static_cast<T>(0));

	template<typename T> requires arithmetic<T>
	const Vector2<T> Vector2<T>::right(static_cast<T>(1), static_cast<T>(0));

	template<typename T> requires arithmetic<T>
	const Vector2<T> Vector2<T>::up(static_cast<T>(0), static_cast<T>(1));

	template<typename T> requires arithmetic<T>
	const Vector2<T> Vector2<T>::down(static_cast<T>(0), static_cast<T>(-1));

	typedef Vector2<int>				Vector2i;
	typedef Vector2<unsigned int>		Vector2u;
	typedef Vector2<double>				Vector2d;

}

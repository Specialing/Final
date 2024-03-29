#ifndef __VECTORS__
#define __VECTORS__

#include <math.h>

class Vector
{
public:
	Vector(){}
	~Vector(){}

	Vector(float x, float y) : m_x(x), m_y(y){}

	const float getX() const { return m_x; }
	const float getY() const { return m_y; }

	void setX(float x) { m_x = x; }
	void setY(float y) { m_y = y; }

	float length() { return sqrt(m_x*m_x + m_y*m_y); }
	
	Vector operator+(const Vector& v2) const 
	{
		return Vector(m_x + v2.m_x, m_y + v2.m_y);
	}
	friend Vector& operator+=(Vector& v1, const Vector& v2)
	{
		v1.m_x += v2.m_x;
		v1.m_y += v2.m_y;

		return v1;
	}

	Vector operator*(float scalar)
	{
		return Vector(m_x*scalar, m_y*scalar);
	}
	Vector operator*=(float scalar)
	{
		m_x *= scalar;
		m_y *= scalar;

		return *this;
	}

	Vector operator-(const Vector& v2) const
	{
		return Vector(m_x - v2.m_x, m_y - v2.m_y);
	}
	friend Vector& operator-=(Vector& v1, const Vector& v2)
	{
		v1.m_x -= v2.m_x;
		v1.m_y -= v2.m_y;
	
		return v1;
	}

	Vector operator/(float scalar)
	{
		return Vector(m_x / scalar, m_y/scalar);
	}
	Vector operator/=(float scalar)
	{
		m_x /= scalar;
		m_y /= scalar;

		return *this;
	}

	void normalise()
	{
		float l = length();

		if(l > 0)
			(*this) *= 1/l;
	}

private:
	float m_x, m_y;
};
#endif
#include <cstdlib>
#include <cmath>
#include "Vector3D.h"
#include "assert.h"

Vector3D::Vector3D()
{
}

Vector3D::Vector3D(float x, float y, float z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

Vector3D & Vector3D::operator+(Vector3D & vct)
{
	m_x = vct.m_x;
	m_y = vct.m_y;
	m_z = vct.m_z;

	return *this;
}

float Vector3D::x()
{
	return m_x;
}

float Vector3D::y()
{
	return m_y;
}

float Vector3D::z()
{
	return m_z;
}

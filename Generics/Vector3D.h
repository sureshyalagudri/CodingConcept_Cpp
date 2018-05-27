#ifndef XFDDOM_VECTOR3D_H
#define XFDDOM_VECTOR3D_H

#include <vector>

/// 3D vector class
class Vector3D
{
public:
    Vector3D();
	Vector3D(float x_in, float y_in, float z_in);
	Vector3D & operator+(Vector3D & vct);
	float x();
	float y();
	float z();

private:
	// x location/direction
	float m_x=0;
    // y location/direction
    float m_y=0;
    // z location/direction
    float m_z=0;
};

#endif

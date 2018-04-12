#ifndef MATHOPT_H
#define MATHOPT_H
#define NDEBUG

#include "Vector3d.h"
#include "Matrix33d.h"

#ifndef ZERO
#define ZERO 0.0
#endif  //ZERO

namespace ly
{
	// Vector3d
	Vector3d operator+(const Vector3d&);
	Vector3d operator-(const Vector3d&);

	Vector3d operator+(const Vector3d&, const Vector3d&);
	Vector3d operator-(const Vector3d&, const Vector3d&);

	Vector3d operator*(const Vector3d&, double);
	Vector3d operator/(const Vector3d&, double);
	Vector3d operator^(const Vector3d&, double);

	Vector3d operator*(double, const Vector3d&);

	double DotProd(const Vector3d&, const Vector3d&);
	Vector3d Cross(const Vector3d&, const Vector3d&);
	double Norm(const Vector3d&);

	// Matrix33d
	Matrix33d operator+(const Matrix33d&);
	Matrix33d operator-(const Matrix33d&);

	Matrix33d operator+(const Matrix33d&, const Matrix33d&);
	Matrix33d operator-(const Matrix33d&, const Matrix33d&);

	Matrix33d operator*(const Matrix33d&, double);
	Matrix33d operator/(const Matrix33d&, double);
	Matrix33d operator^(const Matrix33d&, double);

	Matrix33d operator*(double, const Matrix33d&);

	Matrix33d operator*(const Matrix33d&, const Matrix33d&);
	Vector3d operator*(const Matrix33d&, const Vector3d&);

	Matrix33d Transform(const Matrix33d&);
	double Det(const Matrix33d&);
	Matrix33d Inv(const Matrix33d&);
}

#endif  //MATHOPT_H

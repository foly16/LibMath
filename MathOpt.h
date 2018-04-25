#ifndef MATHOPT_H
#define MATHOPT_H
#define NDEBUG

#include <algorithm>
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
	Vector3d Diag(const Matrix33d&);

	#define F1_DECLARE(math_func, param1)\
	param1 math_func(const param1&);

	#define F2_DECLARE(math_func, param1, param2)\
	param1 math_func(const param1&, param2);

	F1_DECLARE(sin, Vector3d)
	F1_DECLARE(cos, Vector3d)
	F1_DECLARE(tan, Vector3d)
	F1_DECLARE(sqrt, Vector3d)

	F1_DECLARE(sin, Matrix33d)
	F1_DECLARE(cos, Matrix33d)
	F1_DECLARE(tan, Matrix33d)
	F1_DECLARE(sqrt, Matrix33d)

	F2_DECLARE(pow, Vector3d, double)

	F2_DECLARE(pow, Matrix33d, double)

	#undef F2_DECLARE
	#undef F1_DECLARE

}

#endif  //MATHOPT_H

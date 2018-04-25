#include "MathOpt.h"
#include <cmath>

namespace ly
{
	// Vector3d
	Vector3d operator+(const Vector3d& _rhs)
	{
		return _rhs;
	}

	Vector3d operator-(const Vector3d& _rhs)
	{
		return Vector3d(-_rhs(0), -_rhs(1), -_rhs(2));
	}

	Vector3d operator+(const Vector3d& _lhs, const Vector3d& _rhs)
	{
		Vector3d result(_lhs);
		result += _rhs;
		return result;
	}

	Vector3d operator-(const Vector3d& _lhs, const Vector3d& _rhs)
	{
		Vector3d result(_lhs);
		result -= _rhs;
		return result;
	}

	Vector3d operator*(const Vector3d& _lhs, double _rhs)
	{
		Vector3d result(_lhs);
		result *= _rhs;
		return result;
	}

	Vector3d operator/(const Vector3d& _lhs, double _rhs)
	{
		Vector3d result(_lhs);
		result /= _rhs;
		return result;
	}

	Vector3d operator^(const Vector3d& _lhs, double _rhs)
	{
		Vector3d result(_lhs);
		result ^= _rhs;
		return result;
	}

	Vector3d operator*(double _lhs, const Vector3d& _rhs)
	{
		return _rhs * _lhs;
	}

	double DotProd(const Vector3d& _lhs, const Vector3d& _rhs)
	{
		return _lhs(0)*_rhs(0) + _lhs(1)*_rhs(1) + _lhs(2)*_rhs(2);
	}

	Vector3d Cross(const Vector3d& _lhs, const Vector3d& _rhs)
	{
		return Vector3d(_lhs(1)*_rhs(2) - _lhs(2)*_rhs(1),
			_lhs(2)*_rhs(0) - _lhs(0)*_rhs(2),
			_lhs(0)*_rhs(1) - _lhs(1)*_rhs(0));
	}

	double Norm(const Vector3d& _lhs)
	{
		return ::sqrt(_lhs(0)*_lhs(0) + _lhs(1)*_lhs(1) + _lhs(2)*_lhs(2));
	}

	// Matrix33d
	Matrix33d operator+(const Matrix33d& _rhs)
	{
		return _rhs;
	}

	Matrix33d operator-(const Matrix33d& _rhs)
	{
		return Matrix33d(-_rhs(0, 0), -_rhs(0, 1), -_rhs(0, 2),
			-_rhs(1, 0), -_rhs(1, 1), -_rhs(1, 2),
			-_rhs(2, 0), -_rhs(2, 1), -_rhs(2, 2));
	}

	Matrix33d operator+(const Matrix33d& _lhs, const Matrix33d& _rhs)
	{
		Matrix33d result(_lhs);
		result += _rhs;
		return result;
	}

	Matrix33d operator-(const Matrix33d& _lhs, const Matrix33d& _rhs)
	{
		Matrix33d result(_lhs);
		result -= _rhs;
		return result;
	}

	Matrix33d operator*(const Matrix33d& _lhs, double _rhs)
	{
		Matrix33d result(_lhs);
		result *= _rhs;
		return result;
	}

	Matrix33d operator/(const Matrix33d& _lhs, double _rhs)
	{
		Matrix33d result(_lhs);
		result /= _rhs;
		return result;
	}

	Matrix33d operator^(const Matrix33d& _lhs, double _rhs)
	{
		Matrix33d result(_lhs);
		result ^= _rhs;
		return result;
	}

	Matrix33d operator*(double _lhs, const Matrix33d& _rhs)
	{
		return _rhs*_lhs;
	}

	Matrix33d operator*(const Matrix33d& _lhs, const Matrix33d& _rhs)
	{
		return Matrix33d(_lhs(0, 0)*_rhs(0, 0) + _lhs(0, 1)*_rhs(1, 0) + _lhs(0, 2)*_rhs(2, 0),
			_lhs(0, 0)*_rhs(0, 1) + _lhs(0, 1)*_rhs(1, 1) + _lhs(0, 2)*_rhs(2, 1),
			_lhs(0, 0)*_rhs(0, 2) + _lhs(0, 1)*_rhs(1, 2) + _lhs(0, 2)*_rhs(2, 2),
			_lhs(1, 0)*_rhs(0, 0) + _lhs(1, 1)*_rhs(1, 0) + _lhs(1, 2)*_rhs(2, 0),
			_lhs(1, 0)*_rhs(0, 1) + _lhs(1, 1)*_rhs(1, 1) + _lhs(1, 2)*_rhs(2, 1),
			_lhs(1, 0)*_rhs(0, 2) + _lhs(1, 1)*_rhs(1, 2) + _lhs(1, 2)*_rhs(2, 2),
			_lhs(2, 0)*_rhs(0, 0) + _lhs(2, 1)*_rhs(1, 0) + _lhs(2, 2)*_rhs(2, 0),
			_lhs(2, 0)*_rhs(0, 1) + _lhs(2, 1)*_rhs(1, 1) + _lhs(2, 2)*_rhs(2, 1),
			_lhs(2, 0)*_rhs(0, 2) + _lhs(2, 1)*_rhs(1, 2) + _lhs(2, 2)*_rhs(2, 2));
	}

	Vector3d operator*(const Matrix33d& _lhs, const Vector3d& _rhs)
	{
		return Vector3d(_lhs(0, 0)*_rhs(0) + _lhs(0, 1)*_rhs(1) + _lhs(0, 2)*_rhs(2),
			_lhs(1, 0)*_rhs(0) + _lhs(1, 1)*_rhs(1) + _lhs(1, 2)*_rhs(2),
			_lhs(2, 0)*_rhs(0) + _lhs(2, 1)*_rhs(1) + _lhs(2, 2)*_rhs(2));
	}

	Matrix33d Transform(const Matrix33d& _lhs)
	{
		return Matrix33d(_lhs(0, 0), _lhs(1, 0), _lhs(2, 0),
			_lhs(0, 1), _lhs(1, 1), _lhs(2, 1),
			_lhs(0, 2), _lhs(1, 2), _lhs(2, 2));
	}

	double Det(const Matrix33d& _lhs)
	{
		return _lhs(0, 0)*_lhs(1, 1)*_lhs(2, 2) +
		_lhs(0, 1)*_lhs(1, 2)*_lhs(2, 0) +
		_lhs(0, 2)*_lhs(1, 0)*_lhs(2, 1) -
		_lhs(0, 0)*_lhs(1, 2)*_lhs(2, 1) -
		_lhs(0, 1)*_lhs(1, 0)*_lhs(2, 2) -
		_lhs(0, 2)*_lhs(1, 1)*_lhs(2, 0);
	}

	Matrix33d Inv(const Matrix33d& _lhs)
	{
		double rdet = 1.0/Det(_lhs);

		return Matrix33d(rdet*(_lhs(1, 1)*_lhs(2, 2) - _lhs(1, 2)*_lhs(2, 1)),
			rdet*(_lhs(0, 2)*_lhs(2, 1) - _lhs(0, 1)*_lhs(2, 2)),
			rdet*(_lhs(0, 1)*_lhs(1, 2) - _lhs(0, 2)*_lhs(1, 1)),
			rdet*(_lhs(1, 2)*_lhs(2, 0) - _lhs(1, 0)*_lhs(2, 2)),
			rdet*(_lhs(0, 0)*_lhs(2, 2) - _lhs(0, 2)*_lhs(2, 0)),
			rdet*(_lhs(0, 2)*_lhs(1, 0) - _lhs(0, 0)*_lhs(1, 2)),
			rdet*(_lhs(1, 0)*_lhs(2, 1) - _lhs(1, 1)*_lhs(2, 0)),
			rdet*(_lhs(0, 1)*_lhs(2, 0) - _lhs(0, 0)*_lhs(2, 1)),
			rdet*(_lhs(0, 0)*_lhs(1, 1) - _lhs(0, 1)*_lhs(1, 0)));
	}

	Vector3d Diag(const Matrix33d& _lhs)
	{
	    return Vector3d(_lhs(0, 0), _lhs(1, 1), _lhs(2, 2));
	}

	#define F1_DEFINE(math_func, param1)\
	param1 math_func(const param1& _lhs)\
	{\
        param1 result(_lhs);\
        std::for_each(std::begin(result), \
                      std::end(result), \
                      [](double& _x) { using ::math_func; _x = math_func(_x); }\
                      );\
        return result;\
	}

	#define F2_DEFINE(math_func, param1, param2)\
	param1 math_func(const param1& _lhs, param2 k)\
	{\
        param1 result(_lhs);\
        std::for_each(std::begin(result), \
                      std::end(result), \
                      [&k](double& _x) { using ::math_func; _x = math_func(_x, k); }\
                      );\
        return result;\
	}

	F1_DEFINE(sin, Vector3d)
	F1_DEFINE(cos, Vector3d)
	F1_DEFINE(tan, Vector3d)
	F1_DEFINE(sqrt, Vector3d)

	F1_DEFINE(sin, Matrix33d)
	F1_DEFINE(cos, Matrix33d)
	F1_DEFINE(tan, Matrix33d)
	F1_DEFINE(sqrt, Matrix33d)

	F2_DEFINE(pow, Vector3d, double)

	F2_DEFINE(pow, Matrix33d, double)

	#undef F2_DEFINE
	#undef F1_DEFINE
}

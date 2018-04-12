//#include "Matrix33d.h"
#include "MathOpt.h"
#include <stdexcept>
#include <cmath>

namespace ly
{
	Matrix33d::Matrix33d(const Matrix33d& _other)
	{
		m_v[0][0] = _other.m_v[0][0];
		m_v[0][1] = _other.m_v[0][1];
		m_v[0][2] = _other.m_v[0][2];
		m_v[1][0] = _other.m_v[1][0];
		m_v[1][1] = _other.m_v[1][1];
		m_v[1][2] = _other.m_v[1][2];
		m_v[2][0] = _other.m_v[2][0];
		m_v[2][1] = _other.m_v[2][1];
		m_v[2][2] = _other.m_v[2][2];
	}

	Matrix33d& Matrix33d::operator=(const Matrix33d& _rhs)
	{
		if(&_rhs == this)
			return *this;

		m_v[0][0] = _rhs.m_v[0][0];
		m_v[0][1] = _rhs.m_v[0][1];
		m_v[0][2] = _rhs.m_v[0][2];
		m_v[1][0] = _rhs.m_v[1][0];
		m_v[1][1] = _rhs.m_v[1][1];
		m_v[1][2] = _rhs.m_v[1][2];
		m_v[2][0] = _rhs.m_v[2][0];
		m_v[2][1] = _rhs.m_v[2][1];
		m_v[2][2] = _rhs.m_v[2][2];

		return *this;
	}

	Matrix33d& Matrix33d::operator+=(const Matrix33d& _rhs)
	{
		m_v[0][0] += _rhs.m_v[0][0];
		m_v[0][1] += _rhs.m_v[0][1];
		m_v[0][2] += _rhs.m_v[0][2];
		m_v[1][0] += _rhs.m_v[1][0];
		m_v[1][1] += _rhs.m_v[1][1];
		m_v[1][2] += _rhs.m_v[1][2];
		m_v[2][0] += _rhs.m_v[2][0];
		m_v[2][1] += _rhs.m_v[2][1];
		m_v[2][2] += _rhs.m_v[2][2];

		return *this;
	}

	Matrix33d& Matrix33d::operator-=(const Matrix33d& _rhs)
	{
		m_v[0][0] -= _rhs.m_v[0][0];
		m_v[0][1] -= _rhs.m_v[0][1];
		m_v[0][2] -= _rhs.m_v[0][2];
		m_v[1][0] -= _rhs.m_v[1][0];
		m_v[1][1] -= _rhs.m_v[1][1];
		m_v[1][2] -= _rhs.m_v[1][2];
		m_v[2][0] -= _rhs.m_v[2][0];
		m_v[2][1] -= _rhs.m_v[2][1];
		m_v[2][2] -= _rhs.m_v[2][2];

		return *this;
	}

	Matrix33d& Matrix33d::operator*=(const Matrix33d& _rhs)
	{
		m_v[0][0] -= _rhs.m_v[0][0];
		m_v[0][1] -= _rhs.m_v[0][1];
		m_v[0][2] -= _rhs.m_v[0][2];
		m_v[1][0] -= _rhs.m_v[1][0];
		m_v[1][1] -= _rhs.m_v[1][1];
		m_v[1][2] -= _rhs.m_v[1][2];
		m_v[2][0] -= _rhs.m_v[2][0];
		m_v[2][1] -= _rhs.m_v[2][1];
		m_v[2][2] -= _rhs.m_v[2][2];

		return *this;
	}

	Matrix33d& Matrix33d::operator*=(double _k)
	{
		m_v[0][0] *= _k;
		m_v[0][1] *= _k;
		m_v[0][2] *= _k;
		m_v[1][0] *= _k;
		m_v[1][1] *= _k;
		m_v[1][2] *= _k;
		m_v[2][0] *= _k;
		m_v[2][1] *= _k;
		m_v[2][2] *= _k;

		return *this;
	}

	Matrix33d& Matrix33d::operator/=(double _k)
	{
		if (::fabs(_k) <= ZERO)
		{
			throw std::overflow_error("divide by zero");
		}

		double inv_k = 1/_k;
		operator*=(inv_k);

		return *this;
	}

	Matrix33d& Matrix33d::operator^=(double _k)
	{
		using ::pow;

		m_v[0][0] = pow(m_v[0][0], _k);
		m_v[0][1] = pow(m_v[0][1], _k);
		m_v[0][2] = pow(m_v[0][2], _k);
		m_v[1][0] = pow(m_v[0][0], _k);
		m_v[1][1] = pow(m_v[0][1], _k);
		m_v[1][2] = pow(m_v[0][2], _k);
		m_v[2][0] = pow(m_v[0][0], _k);
		m_v[2][1] = pow(m_v[0][1], _k);
		m_v[2][2] = pow(m_v[0][2], _k);

		return *this;
	}
}

#include "Vector3d.h"
#include <stdexcept>
#include <cmath>

namespace ly
{
	Vector3d::Vector3d(const Vector3d& _other)
	{
		m_v[0] = _other.m_v[0];
		m_v[1] = _other.m_v[1];
		m_v[2] = _other.m_v[2];
	}

	Vector3d& Vector3d::operator=(const Vector3d& _rhs)
	{
		if (&_rhs == this)
			return *this;

		m_v[0] = _rhs.m_v[0];
		m_v[1] = _rhs.m_v[1];
		m_v[2] = _rhs.m_v[2];

		return *this;
	}

	Vector3d& Vector3d::operator+=(const Vector3d& _rhs)
	{
		m_v[0] += _rhs.m_v[0];
		m_v[1] += _rhs.m_v[1];
		m_v[2] += _rhs.m_v[2];

		return *this;
	}

	Vector3d& Vector3d::operator-=(const Vector3d& _rhs);
	{
		m_v[0] -= _rhs.m_v[0];
		m_v[1] -= _rhs.m_v[1];
		m_v[2] -= _rhs.m_v[2];

		return *this;
	}

	Vector3d& Vector3d::operator*=(double _k)
	{
		m_v[0] *= _k;
		m_v[1] *= _k;
		m_v[2] *= _k;

		return *this;
	}

	Vector3d& Vector3d::operator/=(double _k)
	{
		if (::fabs(_k) <= ZERO)
		{
			std::throw std::overflow_error("divide by zero");
		}

		double inv_k = 1/k;
		operator*= inv_k;

		return *this;
	}

	Vector3d& Vector3d::operator^=(double _k)
	{
		using ::pow;

		m_v[0] = pow(m_v[0], _k);
		m_v[1] = pow(m_v[1], _k);
		m_v[2] = pow(m_v[2], _k);

		return *this;
	}
}
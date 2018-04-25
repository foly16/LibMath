#include "MathOpt.h"
#include <stdexcept>
#include <cmath>

namespace ly
{
	Matrix33d::Matrix33d(const Matrix33d& _other)
	{
		m_v[0] = _other.m_v[0];
		m_v[1] = _other.m_v[1];
		m_v[2] = _other.m_v[2];
		m_v[3] = _other.m_v[3];
		m_v[4] = _other.m_v[4];
		m_v[5] = _other.m_v[5];
		m_v[6] = _other.m_v[6];
		m_v[7] = _other.m_v[7];
		m_v[8] = _other.m_v[8];
	}

	Matrix33d& Matrix33d::operator=(const Matrix33d& _rhs)
	{
		if(&_rhs == this)
			return *this;

		m_v[0] = _rhs.m_v[0];
		m_v[1] = _rhs.m_v[1];
		m_v[2] = _rhs.m_v[2];
		m_v[3] = _rhs.m_v[3];
		m_v[4] = _rhs.m_v[4];
		m_v[5] = _rhs.m_v[5];
		m_v[6] = _rhs.m_v[6];
		m_v[7] = _rhs.m_v[7];
		m_v[8] = _rhs.m_v[8];

		return *this;
	}

	Matrix33d& Matrix33d::operator+=(const Matrix33d& _rhs)
	{
		m_v[0] += _rhs.m_v[0];
		m_v[1] += _rhs.m_v[1];
		m_v[2] += _rhs.m_v[2];
		m_v[3] += _rhs.m_v[3];
		m_v[4] += _rhs.m_v[4];
		m_v[5] += _rhs.m_v[5];
		m_v[6] += _rhs.m_v[6];
		m_v[7] += _rhs.m_v[7];
		m_v[8] += _rhs.m_v[8];

		return *this;
	}

	Matrix33d& Matrix33d::operator-=(const Matrix33d& _rhs)
	{
		m_v[0] -= _rhs.m_v[0];
		m_v[1] -= _rhs.m_v[1];
		m_v[2] -= _rhs.m_v[2];
		m_v[3] -= _rhs.m_v[3];
		m_v[4] -= _rhs.m_v[4];
		m_v[5] -= _rhs.m_v[5];
		m_v[6] -= _rhs.m_v[6];
		m_v[7] -= _rhs.m_v[7];
		m_v[8] -= _rhs.m_v[8];

		return *this;
	}

	Matrix33d& Matrix33d::operator*=(const Matrix33d& _rhs)
	{
		m_v[0] -= _rhs.m_v[0];
		m_v[1] -= _rhs.m_v[1];
		m_v[2] -= _rhs.m_v[2];
		m_v[3] -= _rhs.m_v[3];
		m_v[4] -= _rhs.m_v[4];
		m_v[5] -= _rhs.m_v[5];
		m_v[6] -= _rhs.m_v[6];
		m_v[7] -= _rhs.m_v[7];
		m_v[8] -= _rhs.m_v[8];

		return *this;
	}

	Matrix33d& Matrix33d::operator*=(double _k)
	{
		m_v[0] *= _k;
		m_v[1] *= _k;
		m_v[2] *= _k;
		m_v[3] *= _k;
		m_v[4] *= _k;
		m_v[5] *= _k;
		m_v[6] *= _k;
		m_v[7] *= _k;
		m_v[8] *= _k;

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

		m_v[0] = pow(m_v[0], _k);
		m_v[1] = pow(m_v[1], _k);
		m_v[2] = pow(m_v[2], _k);
		m_v[3] = pow(m_v[3], _k);
		m_v[4] = pow(m_v[4], _k);
		m_v[5] = pow(m_v[5], _k);
		m_v[6] = pow(m_v[6], _k);
		m_v[7] = pow(m_v[7], _k);
		m_v[8] = pow(m_v[8], _k);

		return *this;
	}

	std::ostream& operator<<(std::ostream& _os, const Matrix33d& _lhs)
	{
	    for(unsigned int i = 0; i < _lhs.m_nrow; ++i)
        {
            std::cout << "| ";
            for(unsigned int j = 0; j < _lhs.m_ncol - 1; ++j)
            {
                std::cout << _lhs.m_v[i * _lhs.m_ncol + j] << ", ";
            }

            std::cout << _lhs.m_v[i * _lhs.m_ncol + _lhs.m_ncol - 1] << " |" << std::endl;
        }
	    return _os;
	}
}

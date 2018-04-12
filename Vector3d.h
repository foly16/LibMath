#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <cstdlib>
#include <iterator>
#include <cassert>

#ifndef MATHOPT_H
#error "cannot use Vector3d.h directly"
#endif  //MATHOPT_H

namespace ly
{
	class Vector3d
	{
	public:
		Vector3d() : Vector3d(0.0, 0.0, 0.0) {}
		explicit Vector3d(double _a) : Vector3d(_a, _a, _a) {}
		Vector3d(double, double, double);
		Vector3d(double *_A) : Vector3d(_A[0], _A[1], _A[2]) {}
		Vector3d(const Vector3d&);

		virtual ~Vector3d() {}

		Vector3d& operator=(const Vector3d&);
		double& operator()(int _i);
		const double& operator()(int _i) const;

		double* begin() { return std::begin(m_v); }
		double* end() { return std::end(m_v); }

		std::size_t Len() const { return m_len; }

		// math operation
		Vector3d& operator+=(const Vector3d&);
		Vector3d& operator-=(const Vector3d&);

		Vector3d& operator*=(double);
		Vector3d& operator/=(double);
		Vector3d& operator^=(double);

	private:
		static const std::size_t m_len = 3;
		double m_v[3];
	};

	inline Vector3d::Vector3d(double _a0, double _a1, double _a2)
	{
		m_v[0] = _a0, m_v[1] = _a1, m_v[2] = _a2;
	}

	inline double& Vector3d::operator()(int _i)
	{
		assert(_i >= 0 && _i < m_len);
		return m_v[_i];
	}

	inline const double& Vector3d::operator()(int _i) const
	{
		assert(_i >= 0 && _i < m_len);
		return m_v[_i];
	}

}

#endif  //VECTOR3D_H

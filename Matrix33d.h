#ifndef MATRIX33D_H
#define MATRIX33D_H

#ifndef MATHOPT_H
#error "cannot use Matrix33d.h directly"
#endif  //MATHOPT_H

#include "Vector3d.h"

namespace ly
{
	class Matrix33d
	{
	public:
		Matrix33d() : Matrix33d(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0) {}
		explicit Matrix33d(double _a) : Matrix33d(_a, _a, _a, _a, _a, _a, _a, _a, _a) {}
		Matrix33d(double, double, double,
			double, double, double,
			double, double, double);
		Matrix33d(double* _A) : Matrix33d(_A[0], _A[1], _A[2], _A[3], _A[4], _A[5], _A[6], _A[7], _A[8]) {}
		Matrix33d(const Vector3d&, const Vector3d&, const Vector3d&);
		Matrix33d(const Matrix33d&);

		virtual ~Matrix33d() {}

		Matrix33d& operator=(const Matrix33d&);
		double& operator()(int _i, int _j);
		const double& operator()(int _i, int _j) const;

		double* begin() { return &m_v[0][0]; }
		double* end() { return &m_v[m_nrow][m_ncol]; }

		std::size_t Rows() const { return m_nrow; }
		std::size_t Cols() const { return m_ncol; }

		// math operation
		Matrix33d& operator+=(const Matrix33d&);
		Matrix33d& operator-=(const Matrix33d&);
		Matrix33d& operator*=(const Matrix33d&);

		Matrix33d& operator*=(double);
		Matrix33d& operator/=(double);
		Matrix33d& operator^=(double);

	private:
		static const std::size_t m_nrow = 3;
		static const std::size_t m_ncol = 3;
		double m_v[m_nrow][m_ncol];
	};

	inline Matrix33d::Matrix33d(double _a00, double _a01, double _a02,
			double _a10, double _a11, double _a12,
			double _a20, double _a21, double _a22)
	{
		m_v[0][0] = _a00, m_v[0][1] = _a01, m_v[0][2] = _a02;
		m_v[1][0] = _a10, m_v[1][1] = _a11, m_v[1][2] = _a12;
		m_v[2][0] = _a20, m_v[2][1] = _a21, m_v[2][2] = _a22;
	}

	inline Matrix33d::Matrix33d(const Vector3d& _V0, const Vector3d& _V1, const Vector3d& _V2)
	{
		m_v[0][0] = _V0(0), m_v[0][1] = _V1(0), m_v[0][2] = _V2(0);
		m_v[1][0] = _V0(1), m_v[1][1] = _V1(1), m_v[1][2] = _V2(1);
		m_v[2][0] = _V0(2), m_v[2][1] = _V1(2), m_v[2][2] = _V2(2);
	}

	inline double& Matrix33d::operator()(int _i, int _j)
	{
		assert(_i >= 0 && _i < m_nrow);
		assert(_j >= 0 && _j < m_ncol);
		return m_v[_i][_j];
	}

	inline const double& Matrix33d::operator()(int _i, int _j) const
	{
		assert(_i >= 0 && _i < m_nrow);
		assert(_j >= 0 && _j < m_ncol);
		return m_v[_i][_j];
	}
}

#endif  //MATRIX33D_H

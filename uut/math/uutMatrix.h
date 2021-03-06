#pragma once
#include "uutRect.h"
#include "uutVector3.h"
#include "uutQuaternion.h"

namespace uut
{
	class Matrix4
	{
	public:
		union {
			struct {
				float _11, _12, _13, _14;
				float _21, _22, _23, _24;
				float _31, _32, _33, _34;
				float _41, _42, _43, _44;
			};
			float m[4][4];
			float data[16];
		};

		Matrix4();
		Matrix4(
			float m11, float m12, float m13, float m14,
			float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34,
			float m41, float m42, float m43, float m44);
		explicit Matrix4(const float* mat);

		Matrix4& operator+=(const Matrix4& mat);
		Matrix4& operator-=(const Matrix4& mat);
		Matrix4& operator*=(float val);
		Matrix4& operator/=(float val);

		Matrix4 operator-() const;

		Matrix4 operator+ (const Matrix4& mat) const;
		Matrix4 operator- (const Matrix4& mat) const;

		Matrix4 operator*(float val) const;
		Matrix4 operator/(float val) const;

		Vector3f Transform(const Vector3f& vec) const;

		static Matrix4 MakeIdentity();
		static Matrix4 MakeTranslate(const Vector3f& vec);
		static Matrix4 MakeRotateX(float angle);
		static Matrix4 MakeRotateY(float angle);
		static Matrix4 MakeRotateZ(float angle);
		static Matrix4 MakeScaling(const Vector3f& scale);
		static Matrix4 MakeQuaternion(const Quaternion& quaternion);

		static Matrix4 MakePerspective(float fovy, float aspect,
			float znear, float zfar);
		static Matrix4 MakeLookAt(const Vector3f& eye, const Vector3f& at, const Vector3f& up);

		static const Matrix4 EMPTY;
		static const Matrix4 IDENTITY;
	};
}
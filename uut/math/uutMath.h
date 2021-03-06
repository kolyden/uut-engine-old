#pragma once
#include "core/uutDefs.h"

namespace uut
{
	namespace Math
	{
		static const float M_PI = 3.14159265358979323846264338327950288f;
		static const float M_HALF_PI = M_PI * 0.5f;
		static const float M_EPSILON = 0.000001f;
		static const float M_DEGTORAD = (float)M_PI / 180.0f;
		static const float M_DEGTORAD_2 = (float)M_PI / 360.0f; // M_DEGTORAD / 2.f
		static const float M_RADTODEG = 1.0f / M_DEGTORAD;

		extern float Deg2Rad(float deg);
		extern float Rad2Deg(float rad);

		extern bool Equals(float lhs, float rhs);

		extern float Floor(float val);
		extern float Ceil(float val);
		extern float Round(float val);
		extern int FloorToInt(float val);
		extern int CeilToInt(float val);
		extern int RoundToInt(float val);

		template<typename T>
		extern const T& Max(const T& a, const T& b) { return (a > b ? a : b); }

		template<typename T>
		extern const T& Min(const T& a, const T& b) { return (a < b ? a : b); }

	}
}
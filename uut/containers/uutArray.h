#pragma once
#include "core/uutDefs.h"

namespace game
{
	template<class T, int numElements>
	class UUT_API Array
	{
	public:
		unsigned Count() const { return numElements; }
		T& GetAt(unsigned index) { return _data[index]; }
		const T& GetAt(unsigned index) const { return _data[index]; }

		void Zero() { memset(_data, 0, sizeof(_data)); }
		T* GetData() { return _data; }
		const T* GetData() const { return _data; }

		T& operator[] (int index) { return _data[index]; }
		const T& operator[] (int index) const { return _data[index]; }

	protected:
		T _data[numElements];
	};
}
#include "uutInput.h"
#include "application/uutWindow.h"

namespace uut
{
	Input::Input()
		: _mousePos(0)
		, _mouseWheel(0)
	{
		_keys.reset();
	}

	//////////////////////////////////////////////////////////////////////////
	void Input::OnKeyDown(EKeycode code)
	{
		_keys[code] = true;
	}

	void Input::OnKeyUp(EKeycode code)
	{
		_keys[code] = false;
	}

	void Input::OnMouseDown(int button)
	{
		_mouseButton[button] = true;
	}

	void Input::OnMouseUp(int button)
	{
		_mouseButton[button] = false;
	}

	void Input::OnMouseMove(const Vector2i& pos)
	{
		_mousePos = pos;
	}

	void Input::OnMouseWheel(float delta)
	{
		_mouseWheel = delta;
	}
}
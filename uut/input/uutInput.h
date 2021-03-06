#pragma once
#include "core/uutObject.h"
#include "containers/uutDictionary.h"
#include "application/uutEventListener.h"
#include <bitset>

namespace uut
{
	class Window;

	class Input : public Object, public EventListener
	{
	public:
		Input();

		bool IsKey(EKeycode key) const { return _keys[key]; }
		bool IsMouseButton(int button) const { return _mouseButton[button]; }
		const Vector2i& GetMousePos() const { return _mousePos; }
		float GetMouseWheel() const { return _mouseWheel; }

	protected:
		static const int KEYS_COUNT = 256;
		std::bitset<KEYS_COUNT> _keys;
		Vector2i _mousePos;
		float _mouseWheel;
		std::bitset<3> _mouseButton;

		virtual void OnKeyDown(EKeycode code) override;
		virtual void OnKeyUp(EKeycode code) override;

		virtual void OnMouseDown(int button) override;
		virtual void OnMouseUp(int button) override;
		virtual void OnMouseMove(const Vector2i& pos) override;
		virtual void OnMouseWheel(float delta) override;
	};
}
#pragma once
#include "uutRenderBuffer.h"

namespace uut
{
	class IndexBuffer : public RenderBuffer
	{
		OBJECT(IndexBuffer, RenderBuffer)
	public:
		IndexBuffer();
		virtual ~IndexBuffer();

		virtual void* Lock() override;
		virtual void Unlock() override;

	protected:
		LPDIRECT3DINDEXBUFFER9 _data;
		EIndexFormat _format;

		friend class Render;
	};
}
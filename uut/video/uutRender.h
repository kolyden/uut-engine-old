#pragma once
#include "core/uutModule.h"
#include "containers/uutList.h"
#include "math/uutVector2.h"
#include "math/uutMatrix.h"
#include "uutColor.h"
#include "uutVideoDefs.h"

namespace uut
{
	class Window;
	class VertexBuffer;
	class VertexLayout;
	class IndexBuffer;
	class Texture;

	class Render : public Module
	{
		OBJECT(Render, Module)
	public:
		Render();
		virtual ~Render();

		LPDIRECT3DDEVICE9 GetDevice() const { return _d3dDevice; }

		bool Init(Window* window);
		void Clear(const Color4b& color);
		bool BeginScene();
		void EndScene();
		void Present();

		SharedPtr<VertexBuffer> CreateVertexBuffer(BufferUsage usage, unsigned int size);
		SharedPtr<IndexBuffer> CreateIndexBuffer(BufferUsage usage, unsigned int size, IndexFormat format);

		SharedPtr<VertexLayout> CreateVertexLayout(const List<VertexDeclare>& declare);
		SharedPtr<VertexLayout> CreateVertexLayout(const VertexDeclare* declare, uint8_t count);

		SharedPtr<Texture> CreateTexture(const Vector2i& size);
		SharedPtr<Texture> LoadTexture(const String& path);

		void SetRenderState(RenderState state, bool val);
		void SetTransform(TransformType transform, const Matrix4& mat);
		bool SetTexture(uint8_t stage, Texture* texture);
		bool SetVertexLayout(VertexLayout* layout);
		bool SetVertexBuffer(uint8_t stream, VertexBuffer* buffer, uint32_t offset, uint32_t stride);
		bool SetIndexBuffer(IndexBuffer* buffer);

		void DrawPrimitive(VertexTopology type, uint32_t start, uint32_t primitiveCount);
		void DrawIndexedPrimitive(VertexTopology type, int vertexStart,
			uint32_t minIndex, uint32_t numVertices, uint32_t startIndex, uint32_t primitiveCount);

	protected:
		SharedPtr<Window> _window;
		LPDIRECT3D9 _d3d;
		LPDIRECT3DDEVICE9 _d3dDevice;

		static D3DPRIMITIVETYPE ConvertPrimitiveType(VertexTopology type);
		static DWORD ConvertBufferUsage(BufferUsage usage);
		static D3DTRANSFORMSTATETYPE ConvertTransformType(TransformType transform);
		static D3DRENDERSTATETYPE ConvertRenderState(RenderState state);
		static D3DDECLUSAGE ConvertUsage(DeclareUsage usage);
		static D3DDECLTYPE ConvertVertexType(DeclareType type, uint8_t count);
	};
}
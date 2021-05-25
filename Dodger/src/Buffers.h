#ifndef BUFFERS_H
#define BUFFERS_H

class VertexBuffer
{
public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();
	
	void Bind() const;
	void UnBind() const;
	
	VertexBuffer(const VertexBuffer&) = delete;
	VertexBuffer& operator=(const VertexBuffer&) = delete;
	
private:
	unsigned int m_Vbo{};
};

class IndexBuffer
{
public:
	IndexBuffer(const unsigned int* data, unsigned int size);
	~IndexBuffer();
	
	void Bind() const;
	void UnBind() const;
	unsigned int GetCount() const { return m_Count; }
	
	IndexBuffer(const IndexBuffer&) = delete;
	IndexBuffer& operator=(const IndexBuffer&) = delete;
	
private:
	unsigned int m_Ibo{};
	unsigned int m_Count;
};

#endif // BUFFERS_H

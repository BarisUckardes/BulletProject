#include "Mesh.h"
#include <GL/glew.h>
#include <Graphics/Mesh/MeshVertex.h>
#include <Graphics/Mesh/SphereGenerator.h>
Mesh::Mesh(const Array<MeshVertex>& vertexes, const Array<int>& indexes)
{
    /*
    * Create handles
    */
    glGenVertexArrays(1, &m_VertexArrayIndex);
    glGenBuffers(1, &m_VertexBufferIndex);
    glGenBuffers(1, &m_IndexBufferIndex);

    /*
    * Bind vertex array and vertex buffer
    */
    glBindVertexArray(m_VertexArrayIndex);
    glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferIndex);

    /*
    * Create vertex array layout
    */
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE, sizeof(MeshVertex),nullptr);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), (const void*)(sizeof(float) * 3));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), (const void*)(sizeof(float) * (3 + 3)));

    /*
    * Update mesh vertex data to gpu
    */
    glBufferData(GL_ARRAY_BUFFER, sizeof(MeshVertex) * vertexes.GetCursor(), vertexes.GetData(), GL_STATIC_DRAW);

    /*
    * Unbind vertex buffers
    */
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    /*
    * Bind index buffer
    */
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferIndex);

    /*
    * Set index buffer data
    */
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * indexes.GetCursor(), indexes.GetData(), GL_STATIC_DRAW);

    /*
    * Unbind index buffer
    */
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    /*
    * Store index count
    */
    m_IndexCount = indexes.GetCursor();
}

Mesh::~Mesh()
{
}

unsigned int Mesh::GetVertexArrayIndex() const
{
    return m_VertexArrayIndex;
}

unsigned int Mesh::GetVertexBufferIndex() const
{
    return m_VertexBufferIndex;
}

unsigned int Mesh::GetIndexBufferIndex() const
{
    return m_IndexBufferIndex;
}

unsigned int Mesh::GetIndexCount() const
{
    return m_IndexCount;
}

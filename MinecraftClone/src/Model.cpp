#include "Model.h"

Model::Model(const std::vector<GLfloat>& vertexPositions)
{
    glGenVertexArrays(1, &m_vao);

    this->bind();
    this->addVBO(2, vertexPositions);
    this->unbind();

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Model::~Model()
{
    glDeleteVertexArrays(1, &m_vao);
    glDeleteBuffers(this->m_buffers.size(), this->m_buffers.data());
}

void Model::bind()
{
    glBindVertexArray(m_vao);
}

void Model::unbind()
{
    glBindVertexArray(0);
}

void Model::addVBO(int dim, const std::vector<GLfloat>& data)
{
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER,
                 data.size() * sizeof(data[0]),
                 data.data(),
                 GL_STATIC_DRAW);

    glVertexAttribPointer(vboCount,
                          dim,
                          GL_FLOAT,
                          GL_FALSE,
                          0,
                          (GLvoid*)0);
    glEnableVertexAttribArray(vboCount++);

    this->m_buffers.push_back(vbo);
}

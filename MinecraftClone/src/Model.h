#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include <vector>
#include <GL/glew.h>

class Model
{

public:
    Model(const std::vector<GLfloat> &vertexPositions);

    void bind();
    void unbind();

    ~Model();

private:
    GLuint m_vao        = 0;
    GLuint vboCount   = 0;
    std::vector<GLuint> m_buffers;


    void addVBO(int dim, const std::vector<GLfloat> &data);

};

#endif // MODEL_H_INCLUDED

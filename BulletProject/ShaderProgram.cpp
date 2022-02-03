#include "ShaderProgram.h"
#include <GLEW/glew.h>
ShaderProgram::ShaderProgram(const String& vertexSource, const String& fragmentSource)
{
    /*
    * Create shaders
    */
    const unsigned int vertexShaderIndex = glCreateShader(GL_VERTEX_SHADER);
    const unsigned int fragmentShaderIndex = glCreateShader(GL_FRAGMENT_SHADER);

    /*
    * Update shader sources
    */
    const char* vertexSourcePtr = vertexSource.GetSource();
    const char* fragmentSourcePtr = fragmentSource.GetSource();
    glShaderSource(vertexShaderIndex, 1, &vertexSourcePtr, 0);
    glShaderSource(fragmentShaderIndex, 1, &fragmentSourcePtr, 0);

    /*
    * Compile shaders
    */
    glCompileShader(vertexShaderIndex);
    glCompileShader(fragmentShaderIndex);

    /*
    * Create shader program
    */
    m_ProgramIndex = glCreateProgram();

    /*
    * Attach shaders to program
    */
    glAttachShader(m_ProgramIndex, vertexShaderIndex);
    glAttachShader(m_ProgramIndex, fragmentShaderIndex);

    /*
    * Link program
    */
    glLinkProgram(m_ProgramIndex);
}

ShaderProgram::~ShaderProgram()
{

}

unsigned int ShaderProgram::GetProgramIndex()
{
    return 0;
}

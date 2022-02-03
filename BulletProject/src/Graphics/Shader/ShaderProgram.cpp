#include "ShaderProgram.h"
#include <GL/glew.h>


void LogShader(unsigned int shaderID)
{
    GLint state = 0;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &state);
    if (state == GL_FALSE)
    {
        GLint maxLength = 255;
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);

        char* errorLog = new char[maxLength];
        glGetShaderInfoLog(shaderID, maxLength, &maxLength, errorLog);

        printf("Shader error: %s\n", errorLog);
    }
    else
    {
        LOG("Vertex create okey.");
    }
}

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
    LogShader(vertexShaderIndex);
    LogShader(fragmentShaderIndex);
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

unsigned int ShaderProgram::GetProgramIndex() const
{
    return m_ProgramIndex;
}

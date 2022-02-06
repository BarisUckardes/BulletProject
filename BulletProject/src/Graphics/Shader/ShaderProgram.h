#pragma once
#include <Memory/String.h>

/// <summary>
/// Contains the opengl handles for shader programs
/// </summary>
class EXPORT ShaderProgram
{
public:
	/// <summary>
	/// Takes in vertex and fragment sources and generates shaders and creates a program handle
	/// </summary>
	/// <param name="vertexSource"></param>
	/// <param name="fragmentSource"></param>
	ShaderProgram(const String& vertexSource, const String& fragmentSource);
	~ShaderProgram();

	/// <summary>
	/// Returns the program index
	/// </summary>
	/// <returns></returns>
	FORCEINLINE unsigned int GetProgramIndex() const;
private:
	unsigned int m_ProgramIndex;
};


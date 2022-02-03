#pragma once
#include <Memory/String.h>

/// <summary>
/// Wrapper class for openGL shader handles
/// 
/// </summary>
class EXPORT ShaderProgram
{
public:
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


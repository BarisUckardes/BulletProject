#pragma once
#include <Memory/String.h>

/// <summary>
/// Base object for world related objects
/// </summary>
class EXPORT Object
{
public:
	Object() = default;

	/// <summary>
	/// Returns the name
	/// </summary>
	/// <returns></returns>
	FORCEINLINE String GetName() const;

	/// <summary>
	/// Sets the object name
	/// </summary>
	/// <param name="name"></param>
	void SetName(const String& name);
protected:
	virtual ~Object() = 0;
private:
	String m_Name;
};


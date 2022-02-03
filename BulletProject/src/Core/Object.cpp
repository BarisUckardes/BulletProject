#include "Object.h"

String Object::GetName() const
{
    return m_Name;
}

void Object::SetName(const String& name)
{
    m_Name = name;
}

Object::~Object()
{

}
#pragma once

/*
* It just holds simple shaders
*/

const char g_SphereVertexSource[] = R"glsl(
#version 450 core
layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTextureCoordinate;

out vec3 f_Normal;
out vec2 f_TextureCoordinate;

uniform mat4 v_Mvp;
void main()
{
	gl_Position = v_Mvp*vec4(aPosition,1.0f);
	f_Normal = aNormal;
	f_TextureCoordinate = aTextureCoordinate;
}
)glsl";

const char g_SphereFragmentSource[] = R"glsl(
#version 450 core

out vec4 f_ColorOut;
in vec3 f_Normal;
in vec2 f_TextureCoordinate;
uniform vec4 f_Color;
void main()
{
	float diffusePower = (dot(f_Normal,vec3(0,1,0)) + 1) /2.0f;
	vec4 finalColor = diffusePower*f_Color;
	f_ColorOut = vec4(finalColor.rgb,1.0f);
}
)glsl";
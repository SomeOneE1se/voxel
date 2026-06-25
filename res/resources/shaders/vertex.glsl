#version 460

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec2 vertexTexCoord;

out vec4 color;
out vec2 a_texCoord;

void main() {
	color		= vec4(1.0f, 1.0f, 1.0f, 1.0f);
	a_texCoord	= vertexTexCoord;
	gl_Position = vec4(vertexPosition, 1.0);
}

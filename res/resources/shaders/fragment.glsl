#version 460

in	vec4	color;
in	vec2	a_texCoord;
out vec4	fragColor;

uniform sampler2D u_texture0;

void main() {
	fragColor = color * texture(u_texture0, a_texCoord);
}

#version 150
precision highp float;

#define LIGHT vec3(0.36, 0.80, 0.48)

//Inputs
uniform sampler2D tex;
in vec2 ex_uv;
in vec3 ex_normal;

//Outputs
out vec4 fragColor;

void main(void) {
	float s = dot(ex_normal, LIGHT)*0.5 + 0.5;
	vec3 color = vec3(0.3098, 0.5843, 0.2902) + vec3(0.1922, 0.1608, 0.191) * fract(floor(ex_uv.x*2.)*.5 + floor(ex_uv.y*2.)*.5) * 2.;
	fragColor = vec4(color * s, 1.0);
}

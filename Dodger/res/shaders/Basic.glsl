#type vertex
#version 120

attribute vec3 a_Position;

uniform mat4 u_Model;

void main()
{
    gl_Position = u_Model * vec4(a_Position, 1.0);
}

#type fragment
#version 120

void main()
{
    gl_FragColor = vec4(1.0, 1.0, 0.0, 1.0);
}


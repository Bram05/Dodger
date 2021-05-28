#type vertex
#version 120

attribute vec3 a_Position;
attribute vec2 a_TexCoord;

uniform mat4 u_VM;
varying vec2 v_TexCoord;

void main()
{
    gl_Position = u_VM * vec4(a_Position, 1.0);
    v_TexCoord = a_TexCoord;
}

#type fragment
#version 120

uniform sampler2D u_Texture;
varying vec2 v_TexCoord;

void main()
{
    gl_FragColor = texture2D(u_Texture, v_TexCoord);
}


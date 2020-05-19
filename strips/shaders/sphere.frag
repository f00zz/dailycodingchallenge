#version 450 core

in vec3 vs_position;
in vec3 vs_normal;
in vec2 vs_uv;

out vec4 fragColor;

uniform vec3 lightPosition;
uniform vec3 color;
uniform vec2 vRange;

void main(void)
{
    float vStart = vRange.x;
    float vEnd = vRange.y;
    if (vEnd > vStart)
    {
        if (vs_uv.y < vStart || vs_uv.y > vEnd)
            discard;
    }
    else
    {
        if (vs_uv.y > vEnd && vs_uv.y < vStart)
            discard;
    }
    float intensity = max(dot(vs_normal, normalize(lightPosition - vs_position)), 0.0);
    if (vs_uv.x < 0.2 || vs_uv.x > 0.8)
        intensity *= 0.8;
    fragColor = vec4(intensity * color, 1.0);
}

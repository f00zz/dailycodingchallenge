#pragma once

#include "noncopyable.h"

#include <GL/glew.h>

#include <array>
#include <vector>
#include <string_view>

#include <glm/glm.hpp>

namespace gl {

class shader_program : private noncopyable
{
public:
    shader_program();

    void add_shader(GLenum type, const char *path);
    void link();

    void bind() const;

    int uniform_location(std::string_view name) const;

    void set_uniform(int location, int v) const;
    void set_uniform(int location, float v) const;
    void set_uniform(int location, const glm::vec2 &v) const;
    void set_uniform(int location, const glm::vec3 &v) const;
    void set_uniform(int location, const glm::vec4 &v) const;

    void set_uniform(int location, const std::vector<float> &v) const;
    void set_uniform(int location, const std::vector<glm::vec2> &v) const;
    void set_uniform(int location, const std::vector<glm::vec3> &v) const;
    void set_uniform(int location, const std::vector<glm::vec4> &v) const;

    void set_uniform(int location, const glm::mat3 &mat) const;
    void set_uniform(int location, const glm::mat4 &mat) const;

    template<typename T>
    void set_uniform(std::string_view name, const T &value) const
    {
        set_uniform(uniform_location(name), value);
    }

    GLuint handle() const
    {
        return id_;
    }

private:
    GLuint id_;
};

} // namespace gl

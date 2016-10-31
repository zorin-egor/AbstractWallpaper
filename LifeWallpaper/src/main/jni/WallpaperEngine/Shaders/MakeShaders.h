#ifndef LIFEWALLPAPERTREE_MAKESHADERS_H
#define LIFEWALLPAPERTREE_MAKESHADERS_H

#include <GLES2/gl2.h>
#include <string>

class MakeShaders {

    public :
        // Shaders for draw star points
        const static char * f_star_shader;
        const static char * v_star_shader;

        // Shader for draw ellipse points
        const static char * f_ellipse_shader;
        const static char * v_ellipse_shader;

        // Shader for draw snow points
        const static char * f_snow_shader;
        const static char * v_snow_shader;

        // For compiling shader program
        static GLuint compileShader(GLenum shaderType, const char* pSource);

        // For create shader program
        static GLuint createProgram(const char* pVertexSource, const char* pFragmentSource);
};

#endif //LIFEWALLPAPERTREE_MAKESHADERS_H

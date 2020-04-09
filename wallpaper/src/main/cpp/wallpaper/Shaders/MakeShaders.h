#ifndef MAKE_SHADERS_H
#define MAKE_SHADERS_H

#include <GLES2/gl2.h>
#include <string>
#include <stdlib.h>

#include "../Common/LogGL.h"


class MakeShaders {

    public :

        // Shaders for draw star points
        const static char * F_GRAPHIC_SHADER;
        const static char * V_GRAPHIC_SHADER;

        // For compiling shader program
        static GLuint compileShader(GLenum shaderType, const char* pSource);

        // For create shader program
        static GLuint createProgram(const char* pVertexSource, const char* pFragmentSource);
};

#endif

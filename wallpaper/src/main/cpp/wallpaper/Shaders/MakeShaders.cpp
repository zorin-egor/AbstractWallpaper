#include "MakeShaders.h"

const char * MakeShaders::V_GRAPHIC_SHADER = "attribute float a_ArrayAngle;"
                                             "attribute vec4 a_ArrayColor;"
                                             "uniform vec2 u_Center;"
                                             "uniform vec2 u_Radius;"
                                             "uniform vec4 u_Arguments;"
                                             "uniform float u_PointSize;"
                                             "uniform float u_TotalDeltaSpeed;"
                                             "varying vec4 v_Color;"
                                             "void main() {"
                                             "   float x_coord = u_Center.x + u_Radius.x * (cos(a_ArrayAngle + u_TotalDeltaSpeed) + cos(u_Arguments.x * (a_ArrayAngle + u_TotalDeltaSpeed)) / u_Arguments.y);"
                                             "   float y_coord = u_Center.y + u_Radius.y * (sin(a_ArrayAngle + u_TotalDeltaSpeed) - sin(u_Arguments.z * (a_ArrayAngle + u_TotalDeltaSpeed)) / u_Arguments.w);"
                                             "   v_Color = a_ArrayColor;"
                                             "   gl_PointSize = u_PointSize;"
                                             "   gl_Position = vec4(x_coord, y_coord, 1.0, 1.0);"
                                             "}";

const char * MakeShaders::F_GRAPHIC_SHADER = "precision mediump float;"
                                             "varying vec4 v_Color;"
                                             "uniform sampler2D t_texture;"
                                             "void main() {"
                                             "    gl_FragColor = v_Color * texture2D(t_texture, gl_PointCoord);"
                                             "}";

GLuint MakeShaders::compileShader(GLenum shaderType, const char* pSource) {
    // Create shared and get it link
    GLuint shader = glCreateShader(shaderType);

    if (shader) {
        // Bind the shader to the source
        glShaderSource(shader, 1, &pSource, NULL);
        // Compile shared
        glCompileShader(shader);
        GLint compiled = 0;
        // Check shader compile status
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

        // If it was not possible to compile, then display the full log and delete the shader that was created
        if (compiled == 0) {
            GLint infoLen = 0;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);

            if (infoLen) {
                char * buf = (char *) malloc(infoLen);

                if (buf) {
                    glGetShaderInfoLog(shader, infoLen, NULL, buf);
                    LOGE("Could not compile shader %d:\n%s\n", shaderType, buf);
                    free(buf);
                }

                glDeleteShader(shader);
                shader = 0;
            }
        }
    }
    return shader;
}

GLuint MakeShaders::createProgram(const char* pVertexSource, const char* pFragmentSource) {
    // Compile a couple of vertex and fragment shaders
    // Compile the "vertex" shader
    GLuint vertexShader = compileShader(GL_VERTEX_SHADER, pVertexSource);
    if (vertexShader == 0) {
        return 0;
    }

    // Compile the fragment shader
    GLuint pixelShader = compileShader(GL_FRAGMENT_SHADER, pFragmentSource);
    if (pixelShader == 0) {
        return 0;
    }

    // Create a program and get a link to it
    GLuint program = glCreateProgram();
    if (program) {
        // Bind shaders to the program
        glAttachShader(program, vertexShader);
        glAttachShader(program, pixelShader);

        // Link the program
        glLinkProgram(program);
        GLint linkStatus = GL_FALSE;
        glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);

        // If it was not possible to link, get the status and delete the program
        if (linkStatus != GL_TRUE) {
            GLint bufLength = 0;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &bufLength);

            if (bufLength) {
                char * buf = (char*) malloc(bufLength);

                if (buf) {
                    glGetProgramInfoLog(program, bufLength, NULL, buf);
                    LOGE("Could not link program: \n%s\n", buf);
                    free(buf);
                }
            }

            glDeleteProgram(program);
            program = 0;
        }
    }

    return program;
}
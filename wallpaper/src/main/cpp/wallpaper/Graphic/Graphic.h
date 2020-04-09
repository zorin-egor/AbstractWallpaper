#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <mutex>
#include <GLES2/gl2.h>
#include "../AbstractClasses/Render.h"
#include "../Common/Methods.h"
#include "../Common/LogGL.h"

class Graphic : public Render {

    public:

        static const enum FUNCTION_TYPE {
            DYNAMIC_UNIFORM = 0,
            DYNAMIC_RANDOM = 1,
            STATIC_RANDOM = 2,
            HYPOCYCLOID = 3,
            EPICYCLOID = 4
        };

        static const enum COLOR_TYPE {
            RAND = 0,
            RED = 1,
            GREEN = 2,
            BLUE = 3
        };

        static const GLuint SIZE_ARRAYS = 4;
        static const GLfloat STATIC_FIGURES[107][4];
        static const GLfloat STRICT_SPEED_MAX;
        static const GLfloat STRICT_SPEED_MIN;
        static const GLfloat STRICT_ARGUMENTS_MAX;
        static const GLfloat STRICT_ARGUMENTS_MIN;
        static const GLfloat ARGUMENT_ARRAY_SPEED;
        static const GLfloat STRICT_TOUCH_CHANGE;
        static const GLfloat SIZE_POINT;


    private:

        std::mutex m_oDrawMutex;

        // For shader
        const GLuint m_nTextureId;
        const GLuint m_nProgramId;
        const GLuint m_nStarsAngle;
        const GLuint m_nStarColor;
        const GLuint m_nStarCenter;
        const GLuint m_nStarRadius;
        const GLuint m_nStarArguments;
        const GLuint m_nStarSize;
        const GLuint m_nStarTotalDeltaSpeed;

        // For data
        const GLuint m_nCount;
        const GLfloat m_fCenterX;
        const GLfloat m_fCenterY;
        const GLfloat m_fRadiusX;
        const GLfloat m_fRadiusY;

        // For dynamic change
        GLfloat m_fPreviousActionX;
        GLfloat m_fPreviousActionY;
        GLfloat m_fArguments[SIZE_ARRAYS];
        GLfloat m_fMaxStrictArgument[SIZE_ARRAYS];
        GLfloat m_fMinStrictArgument[SIZE_ARRAYS];
        GLfloat m_fArgumentsTransformSpeed[SIZE_ARRAYS];
        GLfloat m_fTotalDeltaSpeed;
        GLfloat m_fParticlesSpeed;
        GLfloat * m_pArrayColor;
        GLfloat * m_pArrayPosition;

        // For type of function for output
        FUNCTION_TYPE m_oType;
        // For figure color
        COLOR_TYPE m_oColor;

        // For visibility
        bool m_bIsVisible;
        // Change dynamically or not?
        bool m_bIsChange;


    public:

        Graphic(FUNCTION_TYPE type,
                COLOR_TYPE color,
                bool isChange,
                GLuint count,
                GLfloat centerX,
                GLfloat centerY,
                GLfloat radiusX,
                GLfloat radiusY,
                GLuint programID,
                GLuint textureID,
                GLuint starsAngle,
                GLuint starColor,
                GLuint starCenter,
                GLuint starRadius,
                GLuint starArguments,
                GLuint starSize,
                GLuint starTotalDeltaSpeed);

        virtual ~Graphic();


    public:

        void render();

        void setCoords(GLfloat x, GLfloat y);

        void setSettings(COLOR_TYPE color, FUNCTION_TYPE type);

        void setIsChange(bool isChange);

        void setVisible(bool isVisible) {
            m_bIsVisible = isVisible;
        }

        bool getVisible() {
            return m_bIsVisible;
        }


    private:

        void init();

        void setValues();

};

#endif

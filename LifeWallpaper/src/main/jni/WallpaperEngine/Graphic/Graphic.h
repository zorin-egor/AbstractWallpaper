#ifndef LIFEWALLPAPERABSTRACT_STAR_H
#define LIFEWALLPAPERABSTRACT_STAR_H

#include <GLES2/gl2.h>
#include <LogGL.h>
#include <WallpaperEngine/AbstractClasses/Render.h>
#include <WallpaperEngine/Common/Methods.h>

class Graphic : public Render {
    public:
        static const enum FUNCTION_TYPE { DYNAMIC_UNIFORM = 0, DYNAMIC_RANDOM = 1, STATIC_RANDOM = 2, HYPOCYCLOID = 3, EPICYCLOID = 4 };
        static const enum COLOR_TYPE { RAND = 0, RED = 1, GREEN = 2, BLUE = 3 };

        Graphic(FUNCTION_TYPE _type,
                COLOR_TYPE _color,
                bool _isChange,
                GLuint _count,
                GLfloat _centerX,
                GLfloat _centerY,
                GLfloat _radiusX,
                GLfloat _radiusY,
                GLuint _programID,
                GLuint _textureID,
                GLuint _starsAngle,
                GLuint _starColor,
                GLuint _starCenter,
                GLuint _starRadius,
                GLuint _starArguments,
                GLuint _starSize,
                GLuint _starTotalDeltaSpeed) : type(_type),
                                               color(_color),
                                               isChange(_isChange),
                                               count(_count),
                                               centerX(_centerX),
                                               centerY(_centerY),
                                               radiusX(_radiusX),
                                               radiusY(_radiusY),
                                               programID(_programID),
                                               textureID(_textureID),
                                               starsAngle(_starsAngle),
                                               starColor(_starColor),
                                               starCenter(_starCenter),
                                               starRadius(_starRadius),
                                               starArguments(_starArguments),
                                               starSize(_starSize),
                                               starTotalDeltaSpeed(_starTotalDeltaSpeed),
                                               previousActionX(0.0f),
                                               previousActionY(0.0f),
                                               STRICT_ARGUMENTS_MAX(5.0f),
                                               STRICT_ARGUMENTS_MIN(1.1f),
                                               STRICT_SPEED_MAX(10000.0f),
                                               STRICT_SPEED_MIN(0.0f),
                                               SIZE_POINT(5.0f),
                                               DARGUMENT_ARRAY_SPEED(0.000001f),
                                               STRICT_TOUCH_CHANGE(5000.0f)
    {
        LOGI("Graphic::Graphic()");
        isVisible = true;
        isProgramWork = false;
        init();
    }

    virtual ~Graphic(){
        LOGI("Graphic::~Graphic()");
        delete [] arrayPosition;
        delete [] arrayColor;
    }

    void render();
    void setCoords(GLfloat x, GLfloat y);
    void setSettings(COLOR_TYPE color, FUNCTION_TYPE type);
    void setIsChange(bool isChange);

    void setVisible(bool _isVisible){
        isVisible = _isVisible;
    }

    bool getVisible(){
        return isVisible;
    }

private:

    void init();
    void setValues();

    // For type of function for output
    FUNCTION_TYPE type;
    // For figure color
    COLOR_TYPE color;

    // For shader
    const GLuint textureID;
    const GLuint programID;
    const GLuint starsAngle;
    const GLuint starColor;
    const GLuint starCenter;
    const GLuint starRadius;
    const GLuint starArguments;
    const GLuint starSize;
    const GLuint starTotalDeltaSpeed;

    // For data
    static const GLuint SIZE_ARRAYS = 4;
    const GLuint count;
    const GLfloat centerX;
    const GLfloat centerY;
    const GLfloat radiusX;
    const GLfloat radiusY;

    // For intervals strict
    const GLfloat STRICT_SPEED_MAX;
    const GLfloat STRICT_SPEED_MIN;
    const GLfloat STRICT_ARGUMENTS_MAX;
    const GLfloat STRICT_ARGUMENTS_MIN;
    static const GLfloat STATIC_FIGURES[106][4];

    // For dynamic change
    GLfloat previousActionX;
    GLfloat previousActionY;
    GLfloat arguments[SIZE_ARRAYS];
    GLfloat maxStrictArgument[SIZE_ARRAYS];
    GLfloat minStrictArgument[SIZE_ARRAYS];
    GLfloat dArgumentsTransformSpeed[SIZE_ARRAYS];
    GLfloat * arrayColor;
    GLfloat * arrayPosition;
    GLfloat totalDeltaSpeed;
    GLfloat dParticlesSpeed;
    const GLfloat DARGUMENT_ARRAY_SPEED;
    const GLfloat STRICT_TOUCH_CHANGE;
    const GLfloat SIZE_POINT;

    // For visibility
    bool isVisible;
    // Program work
    bool isProgramWork;
    // Change dynamically or not?
    bool isChange;
};

#endif

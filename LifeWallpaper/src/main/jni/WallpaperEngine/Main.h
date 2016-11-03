#ifndef LIFEWALLPAPERABSTRACT_MAIN_H
#define LIFEWALLPAPERABSTRACT_MAIN_H

#include <WallpaperEngine/Shaders/MakeShaders.h>
#include <WallpaperEngine/Textures/ManageTexture.h>
#include <WallpaperEngine/Graphic/Graphic.h>
#include <WallpaperEngine/Common/Intersect.h>
#include <vector>
#include <LogGL.h>

class Main {

    public:
        Main(   JNIEnv * _env, jobject _assetManager, jobject _pngManager, jint _width, jint _height, jint _color, jint _form, jboolean _isChange) :
                env(_env),
                assetManager(_assetManager),
                pngManager(_pngManager),
                WIDTH(_width),
                HEIGHT(_height),
                COLOR(_color),
                FORM(_form),
                isChange(_isChange),
                COEFFICIENT((GLfloat)_width / (GLfloat)_height),
                POINTS_COUNT(10000),
                SHAPE_RADIUS(0.35f),
                pGraphic(NULL),
                pTextures(NULL)
        {
                LOGI("Main();");
                init();
                createObjects();
        }

        ~Main(){
                LOGI("~Main();");
                //glUseProgram(0);
                //glDeleteProgram(programGraphic);
                delete pGraphic;
                delete pTextures;
        }

        void step();
        void setSettings(int color, int form);
        void setIsChange(bool isChange);
        void action(GLfloat x, GLfloat y);

    private:
        bool init();
        void createObjects();

        // Java references
        JNIEnv * env;
        jobject pngManager;
        jobject assetManager;

        // Screen
        const int WIDTH;
        const int HEIGHT;
        const int COLOR;
        const int FORM;
        const int POINTS_COUNT;
        const GLfloat SHAPE_RADIUS;
        const GLfloat COEFFICIENT;

        // For get the texture
        ManageTexture * pTextures;
        // Programs
        GLuint programGraphic;
        // Sprites
        // Graphic
        GLint graphicAngle;
        GLint graphicColor;
        GLint graphicCenter;
        GLint graphicRadius;
        GLint graphicArguments;
        GLint graphicSize;
        GLint graphicTotalDeltaSpeed;

        // Snow objects for change angle
        Graphic * pGraphic;
        // Dynamically change
        bool isChange;
};

#endif

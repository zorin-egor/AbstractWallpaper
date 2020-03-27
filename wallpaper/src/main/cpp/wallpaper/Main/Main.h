#ifndef LIFEWALLPAPERABSTRACT_MAIN_H
#define LIFEWALLPAPERABSTRACT_MAIN_H

#include <vector>

#include "../Shaders/MakeShaders.h"
#include "../Textures/ManageTexture.h"
#include "../Graphic/Graphic.h"
#include "../Common/Intersect.h"
#include "../Common/LogGL.h"

class Main {

    public:
        Main(   JNIEnv * _env, jobject _assetManager, jobject _pngManager) :
                env(_env),
                assetManager(_assetManager),
                pngManager(_pngManager),
                POINTS_COUNT(100),
                SHAPE_RADIUS(0.35f),
                pGraphic(NULL),
                pTextures(NULL),
                isRenderNow(false)
        {
                LOGI("Main();");
                init();
        }

        ~Main();
        void onChange(int width, int height, int color, int form, bool isChange, int count);
        void step();
        void setSettings(int color, int form);
        void setIsChange(bool isChange);
        void action(GLfloat x, GLfloat y);

    private:
        bool init();
        void createObjects();
        void deleteObjects();

        // Java references
        JNIEnv * env;
        jobject pngManager;
        jobject assetManager;

        // Screen
        int width;
        int height;
        int color;
        int form;
        int count;
        float coefficient;
        // Object settings
        const int POINTS_COUNT;
        const GLfloat SHAPE_RADIUS;

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
        // For check render now or not
        bool isRenderNow;
};

#endif

#ifndef WALLPAPER_H
#define WALLPAPER_H

#include <vector>
#include <mutex>

#include "../Shaders/MakeShaders.h"
#include "../Textures/TexturesManager.h"
#include "../Graphic/Graphic.h"
#include "../Common/Intersect.h"
#include "../Common/LogGL.h"

class Wallpaper {

    private:

        static const int POINTS_COUNT;
        static const GLfloat SHAPE_RADIUS;


    private:

        // TODO temporary solution
        std::mutex m_oDrawMutex;

        // For get the texture
        TexturesManager * m_pTextures;
        // Snow objects for change angle
        Graphic * m_pGraphic;
        // Dynamically change
        bool m_bIsChange;

        Graphic::COLOR_TYPE m_oColorType;
        Graphic::FUNCTION_TYPE m_oFuncType;

        int m_nWidth;
        int m_nHeight;
        int m_nCount;
        float m_fCoefficient;
        float m_nX;
        float m_nY;

        GLuint m_nProgramGraphic;
        GLint m_nGraphicAngle;
        GLint m_nGraphicColor;
        GLint m_nGraphicCenter;
        GLint m_nGraphicRadius;
        GLint m_nGraphicArguments;
        GLint m_nGraphicSize;
        GLint m_nGraphicTotalDeltaSpeed;


    public:

        Wallpaper(JNIEnv * env, jobject assetManager, jobject bitmapManager);

        ~Wallpaper();


    public:

        void screen(int width, int height);

        void step();

        void setSettings(int color, int form);

        void setParticles(int count);

        void setIsChange(bool isChange);

        void action(GLfloat x, GLfloat y);


    private:

        bool init(JNIEnv* env, jobject assetManager, jobject bitmapManager);

        void createObjects();

        void deleteObjects();

};

#endif

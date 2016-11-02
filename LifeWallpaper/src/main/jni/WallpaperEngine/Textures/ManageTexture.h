#ifndef LIFEWALLPAPERTREE_LOADTEXTURES_H
#define LIFEWALLPAPERTREE_LOADTEXTURES_H

#include <jni.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include <string>
#include <LogGL.h>

class ManageTexture {

    public:

        static const enum TEXTURE_TYPE  {
                                            SIZE = 1,
                                            PARTICLES = 0
                                        };

        ManageTexture(JNIEnv* _env, jobject _pngManager, jobject _assetsManager) :
                env(_env),
                pngManager(_pngManager),
                assetsManager(_assetsManager)
            {
                init();
                loadTexture();
                createPackTexture();
            }

        ~ManageTexture(){
            LOGI("ManageTexture::~ManageTexture");
            for(int i = 0; i < TEXTURE_TYPE::SIZE; i++)
                delete arrayTextures[i];

            delete [] texturesIDs;
            delete [] arrayTextures;
        }

        struct Texture {
            char * pixels;
            int width;
            int height;
            Texture() : pixels(NULL), width(0), height(0){}
            Texture(char * p, int w, int h) : pixels(p), width(w), height(h){}
            ~Texture(){
                LOGI("Texture::~Texture");
                if(pixels){
                    delete [] pixels;
                    pixels = NULL;
                }
            }
        };

        Texture ** getTexturePack() const {
            return arrayTextures;
        }

        GLuint getTexturesPackIDs(ManageTexture::TEXTURE_TYPE texture){
            return texturesIDs[texture];
        }

    private:

        Texture * loadPNG(const char * filename);
        void loadTexture();
        void init();
        char * argb2rgba(unsigned int * pixels, int w, int h);
        GLuint createGLTexture(Texture * texture);
        void createPackTexture();

        AAssetManager * aAssetManager;
        jobject assetsManager;
        jobject pngManager;
        JNIEnv * env;

        jmethodID pmOpenId;
        jmethodID pmCloseId;
        jmethodID pmGetWidthId;
        jmethodID pmGetHeightId;
        jmethodID pmGetPixelsId;

        Texture ** arrayTextures;
        const char * TEXTURE_PATH = "pTextures/";
        GLuint * texturesIDs;
};

#endif //GAME_LOADTEXTURES_H

#include "TexturesManager.h"

TexturesManager::TexturesManager(JNIEnv *env, jobject assetsManager, jobject bitmapManager) {
    LOGI("TexturesManager::TexturesManager()");
    init(env, assetsManager, bitmapManager);
    loadTextures(env, bitmapManager);
    createTextures();
}

TexturesManager::~TexturesManager() {
    LOGI("TexturesManager::~TexturesManager()");
    std::for_each(m_oTextures.begin(), m_oTextures.end(), [](std::map<TEXTURE_TYPE, Texture*>::value_type &item) {
        delete item.second;
    });
    m_oTextures.clear();
}

void TexturesManager::init(JNIEnv *env, jobject assetManager, jobject bitmapManager) {
    jclass managerClass = env->GetObjectClass(bitmapManager);
    m_pOpenId = env->GetMethodID(managerClass, "open", "(Ljava/lang/String;)Landroid/graphics/Bitmap;");
    m_pCloseId = env->GetMethodID(managerClass, "close", "(Landroid/graphics/Bitmap;)V");
    m_pGetWidthId = env->GetMethodID(managerClass, "getWidth", "(Landroid/graphics/Bitmap;)I");
    m_pGetHeightId = env->GetMethodID(managerClass, "getHeight", "(Landroid/graphics/Bitmap;)I");
    m_pGetPixelsId = env->GetMethodID(managerClass, "getPixels", "(Landroid/graphics/Bitmap;[I)V");
    m_pAssetManager = AAssetManager_fromJava(env, assetManager);
}

u_char * TexturesManager::argb2rgba(unsigned int * pixels, int w, int h) {
    u_char * result = new u_char[w * h * 4];

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w * 4; j += 4) {
            uint pixel = pixels[i * w + j / 4];
            result[i * w * 4 + j] 	   = (pixel >> 16) & 0xff;  // R
            result[i * w * 4 + j + 1]  = (pixel >> 8) & 0xff;   // G
            result[i * w * 4 + j + 2]  = (pixel & 0xff);        // B
            result[i * w * 4 + j + 3]  = (pixel >> 24) & 0xff;  // A
        }
    }

    return result;
}

Texture * TexturesManager::loadTexture(JNIEnv * env, jobject bitmapManager, const char* filename) {
    LOGI("TexturesManager::loadTexture(%s)", filename);

    Texture * texture = new Texture();

    jstring name = env->NewStringUTF(filename);
    jobject png = env->CallObjectMethod(bitmapManager, m_pOpenId, name);

    // Get bitmap pixels
    jint width = env->CallIntMethod(bitmapManager, m_pGetWidthId, png);
    jint height = env->CallIntMethod(bitmapManager, m_pGetHeightId, png);
    jintArray array = env->NewIntArray(width * height);
    env->CallVoidMethod(bitmapManager, m_pGetPixelsId, png, array);
    jint * pixels = env->GetIntArrayElements(array, NULL);

    // Set texture content
    texture->pixels = argb2rgba((unsigned int *) pixels, width, height);
    texture->width = width;
    texture->height = height;

    // Release bitmap
    env->CallVoidMethod(bitmapManager, m_pCloseId, png);

    // Release jvm references
    env->ReleaseIntArrayElements(array, pixels, 0);
    env->DeleteLocalRef(name);
    env->DeleteLocalRef(array);

    return texture;
}

void TexturesManager::loadTextures(JNIEnv * env, jobject bitmapManager) {
    LOGI("TexturesManager::loadTextures");
    m_oTextures[TexturesManager::PARTICLES] = loadTexture(env, bitmapManager, "textures/particles.png");
}

GLuint TexturesManager::createTexture(Texture * texture) {
    GLuint textureId;
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture->width, texture->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture->pixels);
    return textureId;
}

void TexturesManager::createTextures() {
    std::for_each(m_oTextures.begin(), m_oTextures.end(), [&](std::map<TEXTURE_TYPE, Texture*>::value_type &item) {
        item.second->textureId = createTexture(item.second);
    });
}
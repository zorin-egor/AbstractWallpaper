#include "ManageTexture.h"

void ManageTexture::init() {
    jobject refPNGManager = env->NewGlobalRef(pngManager);
    jclass pmClass = env->GetObjectClass(refPNGManager);
    pmOpenId = env->GetMethodID(pmClass, "open", "(Ljava/lang/String;)Landroid/graphics/Bitmap;");
    pmCloseId = env->GetMethodID(pmClass, "close", "(Landroid/graphics/Bitmap;)V");
    pmGetWidthId = env->GetMethodID(pmClass, "getWidth", "(Landroid/graphics/Bitmap;)I");
    pmGetHeightId = env->GetMethodID(pmClass, "getHeight", "(Landroid/graphics/Bitmap;)I");
    pmGetPixelsId = env->GetMethodID(pmClass, "getPixels", "(Landroid/graphics/Bitmap;[I)V");
    aAssetManager = AAssetManager_fromJava(env, assetsManager);
}

void ManageTexture::loadTexture(){
    // LOGI("ManageTexture::loadTexture");
    arrayTextures = new Texture * [ManageTexture::SIZE];
    arrayTextures[ManageTexture::PARTICLES] = loadPNG("textures/particles.png");
}

ManageTexture::Texture * ManageTexture::loadPNG(const char* filename){
    //LOGI("ManageTexture::loadPNG(%s)", filename);

    Texture * result = new Texture();
    jstring name = env->NewStringUTF(filename);
    jobject png = env->CallObjectMethod(pngManager, pmOpenId, name);
    env->DeleteLocalRef(name);
    env->NewGlobalRef(png);

    jint width = env->CallIntMethod(pngManager, pmGetWidthId, png);
    jint height = env->CallIntMethod(pngManager, pmGetHeightId, png);

    jintArray array = env->NewIntArray(width * height);
    env->NewGlobalRef(array);
    env->CallVoidMethod(pngManager, pmGetPixelsId, png, array);
    jint * pixels = env->GetIntArrayElements(array, 0);

    result->pixels = argb2rgba((unsigned int *) pixels, width, height);
    result->width = width;
    result->height = height;

    env->ReleaseIntArrayElements(array, pixels, 0);
    env->CallVoidMethod(pngManager, pmCloseId, png);
    return result;
}

char * ManageTexture::argb2rgba(unsigned int * pixels, int w, int h){
    char * result = new char[w * h * 4];
    unsigned int pixel;
    int i, j, offset;

    for(i = 1; i < h; i++){
        offset = i * w * 4;
        for(j = 0; j < w * 4; j += 4){
            pixel = pixels[i * w + j / 4];
            result[offset + j] 		= (pixel >> 16) & 0xff;
            result[offset + j + 1]  = (pixel >> 8) & 0xff;
            result[offset + j + 2]  = (pixel & 0xff);
            result[offset + j + 3]  = (pixel >> 24) & 0xff;
        }
    }

    return result;
}

GLuint ManageTexture::createGLTexture(Texture * texture){
    GLuint textureId;
    // Генерим ИД для текстуры
    glGenTextures(1, &textureId);
    // Биндим текстуру с ИД
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);
    // Загружаем текстуру
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture->width, texture->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture->pixels);
    return textureId;
}

void ManageTexture::createPackTexture(){
    texturesIDs = new GLuint[ManageTexture::SIZE];
    for(int i = 0; i < ManageTexture::SIZE; i++){
        texturesIDs[i] = createGLTexture(arrayTextures[i]);
    }
}
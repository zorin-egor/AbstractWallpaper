#ifndef LOG_GL_H
#define LOG_GL_H

#include <android/log.h>
#include <GLES2/gl2.h>

#define  LOG_TAG    "AbstractWallpaper"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define  LOGW(...)  __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

static void checkGLError(const char * from) {
    GLint error;
    while ((error = glGetError()) != GL_NO_ERROR) {
        LOGE("After %s glGetError (0x%x)\n", from, error);
    }
}

#endif

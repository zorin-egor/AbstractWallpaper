#include <jni.h>
#include <map>
#include <Main/Wallpaper.h>
#include <Common/LogGL.h>

#define JNI_METHOD(RTYPE, NAME) JNIEXPORT RTYPE JNICALL Java_ru_testsimpleapps_lifewallpaperabstract_WallpaperLib_##NAME

std::map<long, Wallpaper*> oWallpapers;

extern "C" {

    JNI_METHOD(void, init)(JNIEnv * env, jclass type, jint id, jobject assetManager, jobject bitmapManager) {
        LOGI("JNI::INIT(%i)", 0);
        if (oWallpapers.count(id) <= 0) {
            oWallpapers[id] = new Wallpaper(env, assetManager, bitmapManager);
        }
    }

    JNI_METHOD(void, destroy)(JNIEnv * env, jclass type, jint id) {
        LOGI("JNI::DESTROY(%i)", id);
        if (oWallpapers.count(id) > 0) {
            delete oWallpapers[id];
            oWallpapers.erase(id);
        }
    }

    JNI_METHOD(void, screen)(JNIEnv * env, jclass type, jint id, jint width, jint height) {
        LOGI("JNI::SCREEN(%i, %i)", height, width);
        if (oWallpapers.count(id) > 0) {
            oWallpapers[id]->screen(width, height);
        }
    }

    JNI_METHOD(void, step)(JNIEnv * env, jclass type, jint id) {
        if (oWallpapers.count(id) > 0) {
            oWallpapers[id]->step();
        }
    }

    JNI_METHOD(void, action)(JNIEnv *env, jclass type, jint id, jfloat x, jfloat y) {
        std::for_each(oWallpapers.begin(), oWallpapers.end(), [&](std::map<long, Wallpaper*>::value_type &item) {
            item.second->action(x, y);
        });
    }

    JNI_METHOD(void, setSettings)(JNIEnv *env, jclass type, jint color, jint form) {
        std::for_each(oWallpapers.begin(), oWallpapers.end(), [&](std::map<long, Wallpaper*>::value_type &item) {
            item.second->setSettings(color, form);
        });
    }

    JNI_METHOD(void, setParticles)(JNIEnv *env, jclass type, jint count) {
        std::for_each(oWallpapers.begin(), oWallpapers.end(), [&](std::map<long, Wallpaper*>::value_type &item) {
            item.second->setParticles(count);
        });
    }

    JNI_METHOD(void, setIsChange)(JNIEnv *env, jclass type, jboolean isChange) {
        std::for_each(oWallpapers.begin(), oWallpapers.end(), [&](std::map<long, Wallpaper*>::value_type &item) {
            item.second->setIsChange(isChange);
        });
    }
}
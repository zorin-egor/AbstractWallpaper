#include <jni.h>
#include <queue>
#include <WallpaperEngine/Main.h>
#include <LogGL.h>

Main * wallpaper = NULL;
std::queue<Main *> wallpapersObjects;

extern "C" {

    JNIEXPORT void JNICALL Java_ru_testsimpleapps_lifewallpaperabstract_WallpaperLib_init(JNIEnv * env, jclass type,
                                                                                          jobject assetManager, jobject pngManager,
                                                                                          jint width, jint height, jint color, jint form, jboolean isChange){
        LOGI("INIT: H: %d; W: %d; C: %d; F: %d;", height, width, color, form);
        wallpaper = new Main(env, assetManager, pngManager, width, height, color, form, isChange);
        wallpapersObjects.push(wallpaper);
    }

    JNIEXPORT void JNICALL Java_ru_testsimpleapps_lifewallpaperabstract_WallpaperLib_setSettings(JNIEnv *env, jclass type, jint color, jint form){
        wallpaper->setSettings(color, form);
    }

    JNIEXPORT void JNICALL Java_ru_testsimpleapps_lifewallpaperabstract_WallpaperLib_setIsChange(JNIEnv *env, jclass type, jboolean isChange){
        wallpaper->setIsChange(isChange);
    }

    JNIEXPORT void JNICALL Java_ru_testsimpleapps_lifewallpaperabstract_WallpaperLib_step(JNIEnv * env, jclass type){
        if(wallpaper != NULL)
            wallpaper->step();
    }

    JNIEXPORT void JNICALL Java_ru_testsimpleapps_lifewallpaperabstract_WallpaperLib_action(JNIEnv *env, jclass type, jfloat x, jfloat y) {
        if(wallpaper != NULL)
            wallpaper->action(x, y);
    }

    JNIEXPORT void JNICALL Java_ru_testsimpleapps_lifewallpaperabstract_WallpaperLib_destroyPrevious(JNIEnv * env, jclass type){
        LOGI("DESTROY_PREVIOUS; SIZE: %d;", wallpapersObjects.size());
        if(wallpapersObjects.size() > 1){
            delete wallpapersObjects.front();
            wallpapersObjects.pop();
        }
    }

    JNIEXPORT void JNICALL Java_ru_testsimpleapps_lifewallpaperabstract_WallpaperLib_exit(JNIEnv *env, jclass type) {
        LOGI("EXIT; SIZE: %d;", wallpapersObjects.size());
        while(!wallpapersObjects.empty()) {
            delete wallpapersObjects.front();
            wallpapersObjects.pop();
        }
    }
}
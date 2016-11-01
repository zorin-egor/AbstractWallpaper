#include <jni.h>
#include <queue>
#include <WallpaperEngine/Main.h>
#include <LogGL.h>

Main * wallpaper = NULL;
std::queue<Main *> wallpapersObjects;

extern "C" {

    JNIEXPORT void JNICALL Java_ru_testsimpleapps_lifewallpaperabstract_WallpaperLib_init(JNIEnv * env, jobject obj,
                                                                                          jobject assetManager, jobject pngManager,
                                                                                          jint width, jint height, jint color, jint form, jboolean isChange){
        LOGI("INIT: H: %d; W: %d; C: %d; F: %d;", height, width, color, form);
        wallpaper = new Main(env, assetManager, pngManager, width, height, color, form, isChange);
        wallpapersObjects.push(wallpaper);
    }

    JNIEXPORT void JNICALL Java_ru_testsimpleapps_lifewallpaperabstract_WallpaperLib_setSettings(JNIEnv *env, jclass type, jint color, jint form, jboolean isChange){
        wallpaper->setSettings(color, form, isChange);
    }

    JNIEXPORT void JNICALL Java_ru_testsimpleapps_lifewallpaperabstract_WallpaperLib_step(JNIEnv * env, jobject obj){
        if(wallpaper != NULL)
            wallpaper->step();
    }

    JNIEXPORT void JNICALL Java_ru_testsimpleapps_lifewallpaperabstract_WallpaperLib_action(JNIEnv *env, jclass type, jfloat x, jfloat y) {
        if(wallpaper != NULL)
            wallpaper->action(x, y);
    }

    JNIEXPORT void JNICALL Java_ru_testsimpleapps_lifewallpaperabstract_WallpaperLib_destroyPrevious(JNIEnv * env, jobject obj){
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
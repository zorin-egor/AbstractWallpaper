package ru.testsimpleapps.lifewallpaperabstract;

import android.opengl.GLSurfaceView;
import android.util.Log;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class WallpaperGLRender implements GLSurfaceView.Renderer {

    private static volatile boolean isNeedChange = false;

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        Log.d(WallpaperLib.TAG, this.getClass().toString() + " - onSurfaceCreated; THREAD: " + Thread.currentThread().getId());
        WallpaperLib.destroyPrevious();
        WallpaperLib.init(  WallpaperApplication.getAppContext().getAssets(),
                            new PNGManager(WallpaperApplication.getAppContext().getAssets()));
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        Log.d(WallpaperLib.TAG, this.getClass().toString() + " - onSurfaceChanged; THREAD: " + Thread.currentThread().getId());
        WallpaperLib.onChange(  width,
                                height,
                                WallpaperApplication.getApplication().getColors(),
                                WallpaperApplication.getApplication().getForms(),
                                WallpaperApplication.getApplication().isChange(),
                                WallpaperApplication.getApplication().getParticlesCount());
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        //Log.d(WallpaperLib.TAG, "RENDER THREAD: " + Thread.currentThread().getId());
        WallpaperLib.step();
        if(isNeedChange){
            WallpaperLib.onChange(  -1, -1, -1, -1,
                                    WallpaperApplication.getApplication().isChange(),
                                    WallpaperApplication.getApplication().getParticlesCount());
            isNeedChange = false;
        }
    }

    public static void setIsNeedChange(){
        isNeedChange = true;
    }
}
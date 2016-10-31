package ru.testsimpleapps.lifewallpaperabstract;

import android.opengl.GLSurfaceView;
import android.util.Log;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class WallpaperGLRender implements GLSurfaceView.Renderer {

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        Log.d(WallpaperLib.TAG, this.getClass().toString() + " - onSurfaceCreated");
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        Log.d(WallpaperLib.TAG, this.getClass().toString() + " - onSurfaceChanged");
        WallpaperLib.destroyPrevious();
        WallpaperLib.init(  WallpaperApplication.getAppContext().getAssets(),
                            new PNGManager(WallpaperApplication.getAppContext().getAssets()),
                            width,
                            height,
                            WallpaperApplication.getApplication().getColors(),
                            WallpaperApplication.getApplication().getForms());
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        //Log.d(WallpaperLib.TAG, "RENDER THREAD: " + Thread.currentThread().getId());
        WallpaperLib.step();
    }
}
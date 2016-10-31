package ru.testsimpleapps.lifewallpaperabstract;

import android.opengl.GLSurfaceView;
import android.util.Log;

public class WallpaperService extends GLWallpaperOpenService {

    @Override
    GLSurfaceView.Renderer getNewRenderer() {
        Log.d(WallpaperLib.TAG, this.getClass().toString() + " - getNewRenderer");
        return new WallpaperGLRender();
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        Log.d(WallpaperLib.TAG, this.getClass().toString() + " - onDestroy");
        WallpaperLib.exit();
        openGLES2Engine = null;
    }
}

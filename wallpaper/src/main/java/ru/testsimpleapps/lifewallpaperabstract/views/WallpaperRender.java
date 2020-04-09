package ru.testsimpleapps.lifewallpaperabstract.views;

import android.content.Context;
import android.opengl.GLSurfaceView;

import java.lang.ref.WeakReference;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import ru.testsimpleapps.lifewallpaperabstract.WallpaperLib;
import ru.testsimpleapps.lifewallpaperabstract.managers.BitmapManager;
import ru.testsimpleapps.lifewallpaperabstract.managers.PreferenceManager;

public class WallpaperRender implements GLSurfaceView.Renderer {

    private WeakReference<Context> mContext;

    public WallpaperRender(Context context) {
        mContext = new WeakReference<>(context);
    }

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        final Context context = mContext.get();
        if (context != null) {
            WallpaperLib.init(hashCode(), context.getAssets(), new BitmapManager(context.getAssets()));
            WallpaperLib.setIsChange(PreferenceManager.getInstance(context).isChange());
            WallpaperLib.setParticles(PreferenceManager.getInstance(context).getParticles());
            WallpaperLib.action(
                    hashCode(),
                    PreferenceManager.getInstance(context).getCoordinates().x,
                    PreferenceManager.getInstance(context).getCoordinates().y
            );
            WallpaperLib.setSettings(
                    PreferenceManager.getInstance(context).getColor(),
                    PreferenceManager.getInstance(context).getForm()
            );
        } else {
            throw new IllegalStateException("Context must be set!");
        }
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        WallpaperLib.screen(hashCode(), width, height);
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        WallpaperLib.step(hashCode());
    }

}
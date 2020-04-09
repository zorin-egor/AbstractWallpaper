package ru.testsimpleapps.lifewallpaperabstract;

import android.content.res.AssetManager;

import ru.testsimpleapps.lifewallpaperabstract.managers.BitmapManager;

public class WallpaperLib {

    static {
        System.loadLibrary(BuildConfig.LIB_WALLPAPER);
    }

    public static native void init(int id, AssetManager assetManager, BitmapManager bitmapManager);

    public static native void screen(int id, int width, int height);

    public static native void step(int id);

    public static native void action(int id, float x, float y);

    public static native void setSettings(int color, int form);

    public static native void setParticles(int count);

    public static native void setIsChange(boolean isChange);

    public static native void destroy(int id);

}

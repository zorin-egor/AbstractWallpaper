package ru.testsimpleapps.lifewallpaperabstract;

import android.app.Application;
import android.content.Context;
import android.content.SharedPreferences;
import android.util.Log;


public class WallpaperApplication extends Application {

    // For colors
    public static final int RAND = 0;
    public static final int RED = 1;
    public static final int GREEN = 2;
    public static final int BLUE = 3;

    // For forms
    public static final int DYNAMIC_UNIFORM = 0;
    public static final int DYNAMIC_RANDOM = 1;
    public static final int STATIC_RANDOM = 2;

    // Default particlees
    public static final int DEFAULT_PARTICLES = 15000;
    public static final int DEFAULT_UP = 50000;
    public static final int DEFAULT_DOWN = 5000;
    public static final int DEFAULT_STEP = 1000;

    // Preferences
    public static final String PREFERENCES = "PREFERENCES";
    public static final String COLORS = "COLORS";
    public static final String FORMS = "FORMS";
    public static final String CHANGE = "CHANGE";
    public static final String PARTICLES = "PARTICLES";

    private static int CURRENT_COLOR = GREEN;
    private static int CURRENT_FORM = DYNAMIC_UNIFORM;
    private static boolean IS_CHANGE = true;
    private static int PARTICLES_COUNT = DEFAULT_PARTICLES;

    private static Context context;
    private static WallpaperApplication wallpaperApplication;
    private SharedPreferences sharedPreferences;

    public void onCreate() {
        super.onCreate();
        WallpaperApplication.context = getApplicationContext();
        WallpaperApplication.wallpaperApplication = this;
        loadPreferences();
    }

    private void loadPreferences() {
        Log.d(WallpaperLib.TAG, this.getClass().getName().toString() + " - loadPreferences");
        sharedPreferences = getSharedPreferences(PREFERENCES, MODE_PRIVATE);
        setColor(sharedPreferences.getInt(COLORS, RAND));
        setForms(sharedPreferences.getInt(FORMS, STATIC_RANDOM));
        setIsChange(sharedPreferences.getBoolean(CHANGE, false));
        setParticlesCount(sharedPreferences.getInt(PARTICLES, DEFAULT_PARTICLES));
    }

    public void savePreferences() {
        Log.d(WallpaperLib.TAG, this.getClass().getName().toString() + " - savePreferences");
        sharedPreferences.edit().putInt(COLORS, getColors()).commit();
        sharedPreferences.edit().putInt(FORMS, getForms()).commit();
        sharedPreferences.edit().putBoolean(CHANGE, isChange()).commit();
        sharedPreferences.edit().putInt(PARTICLES, getParticlesCount()).commit();
    }

    public static Context getAppContext() {
        return WallpaperApplication.context;
    }

    public static WallpaperApplication getApplication() {
        return WallpaperApplication.wallpaperApplication;
    }

    public static int getColors() {
        return CURRENT_COLOR;
    }

    public static void setColor(int color) {
        WallpaperApplication.CURRENT_COLOR = color;
    }

    public static int getForms() {
        return CURRENT_FORM;
    }

    public static void setForms(int form) {
        WallpaperApplication.CURRENT_FORM = form;
    }

    public static boolean isChange() {
        return IS_CHANGE;
    }

    public static void setIsChange(boolean isChange) {
        IS_CHANGE = isChange;
    }

    public static void setIsChange() {
        IS_CHANGE = IS_CHANGE? false : true;
    }

    public static int getParticlesCount() {
        return PARTICLES_COUNT;
    }

    private static void setParticlesCount(int particlesCount) {
        PARTICLES_COUNT = particlesCount;
    }

    public static boolean increaseParticlesCount(){
        if(PARTICLES_COUNT < DEFAULT_UP) {
            PARTICLES_COUNT += DEFAULT_STEP;
            return true;
        }
        return false;
    }

    public static boolean decreaseParticlesCount(){
        if(PARTICLES_COUNT > DEFAULT_DOWN) {
            PARTICLES_COUNT -= DEFAULT_STEP;
            return true;
        }
        return false;
    }
}
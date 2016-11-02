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

    // Preferences
    public static final String PREFERENCES = "PREFERENCES";
    public static final String COLORS = "COLORS";
    public static final String FORMS = "FORMS";
    public static final String CHANGE = "CHANGE";

    private static int CURRENT_COLOR = GREEN;
    private static int CURRENT_FORM = DYNAMIC_UNIFORM;
    private static boolean IS_CHANGE = true;

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
        setForms(sharedPreferences.getInt(FORMS, DYNAMIC_UNIFORM));
        setIsChange(sharedPreferences.getBoolean(CHANGE, true));
    }

    public void savePreferences() {
        Log.d(WallpaperLib.TAG, this.getClass().getName().toString() + " - savePreferences");
        sharedPreferences.edit().putInt(COLORS, getColors()).commit();
        sharedPreferences.edit().putInt(FORMS, getForms()).commit();
        sharedPreferences.edit().putBoolean(CHANGE, isChange()).commit();
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
}
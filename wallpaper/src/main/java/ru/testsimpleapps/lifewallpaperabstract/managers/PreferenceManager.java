package ru.testsimpleapps.lifewallpaperabstract.managers;

import android.content.Context;
import android.content.SharedPreferences;
import android.graphics.PointF;

public class PreferenceManager {

    public static final String TAG = PreferenceManager.class.getSimpleName();

    private static volatile PreferenceManager sInstance;

    public static PreferenceManager getInstance(Context context) {
        PreferenceManager localInstance = sInstance;
        if (localInstance == null) {
            synchronized (PreferenceManager.class) {
                localInstance = sInstance;
                if (localInstance == null) {
                    sInstance = localInstance = new PreferenceManager(context);
                }
            }
        }
        return localInstance;
    }

    private static final int COLOR_RAND = 0;
    private static final int COLOR_RED = 1;
    private static final int COLOR_GREEN = 2;
    private static final int COLOR_BLUE = 3;

    private static final int FORM_UNIFORM = 0;
    private static final int FORM_DYNAMIC = 1;
    private static final int FORM_STATIC = 2;

    private static final int PARTICLES_DEFAULT = 15000;
    private static final int PARTICLES_MAX = 50000;
    private static final int PARTICLES_MIN = 5000;
    private static final int PARTICLES_STEP = 1000;

    private final SharedPreferences mSharedPreferences;

    private final String KEY_1 = "KEY_1";
    private final String KEY_2 = "KEY_2";
    private final String KEY_3 = "KEY_3";
    private final String KEY_4 = "KEY_4";
    private final String KEY_5_1 = "KEY_5_1";
    private final String KEY_5_2 = "KEY_5_2";

    public PreferenceManager(Context context) {
        mSharedPreferences = context.getSharedPreferences(TAG, Context.MODE_PRIVATE);
    }

    private void setParticles(int particles) {
        mSharedPreferences.edit().putInt(KEY_1, particles).apply();
    }

    public int getParticles() {
        return mSharedPreferences.getInt(KEY_1, PARTICLES_DEFAULT);
    }

    public int increaseParticles() {
        final int particles = getParticles();
        final int particlesNew = particles + PARTICLES_STEP;
        final int next = particlesNew > PARTICLES_MAX? PARTICLES_MAX : particlesNew;
        setParticles(next);
        return next;
    }

    public int decreaseParticles() {
        final int particles = getParticles();
        final int particlesNew = particles - PARTICLES_STEP;
        final int next = particlesNew < PARTICLES_MIN? PARTICLES_MIN : particlesNew;
        setParticles(next);
        return next;
    }

    private void setColor(int color) {
        mSharedPreferences.edit().putInt(KEY_2, color > COLOR_BLUE || color < COLOR_RAND? COLOR_RAND : color).apply();
    }

    public int getColor() {
        return mSharedPreferences.getInt(KEY_2, COLOR_RAND);
    }

    public int setColorRed() {
        setColor(COLOR_RED);
        return COLOR_RED;
    }

    public int setColorGreen() {
        setColor(COLOR_GREEN);
        return COLOR_GREEN;
    }

    public int setColorBlue() {
        setColor(COLOR_BLUE);
        return COLOR_BLUE;
    }

    public int setColorRand() {
        setColor(COLOR_RAND);
        return COLOR_RAND;
    }

    private void setForm(int form) {
        mSharedPreferences.edit().putInt(KEY_3, form).apply();
    }

    public int getForm() {
        return mSharedPreferences.getInt(KEY_3, FORM_DYNAMIC);
    }

    public int setFormUniform() {
        setForm(FORM_UNIFORM);
        return FORM_UNIFORM;
    }

    public int setFormDynamic() {
        setForm(FORM_DYNAMIC);
        return FORM_DYNAMIC;
    }

    public int setFormStatic() {
        setForm(FORM_STATIC);
        return FORM_STATIC;
    }

    public void setIsChange(boolean isChange) {
        mSharedPreferences.edit().putBoolean(KEY_4, isChange).apply();
    }

    public boolean isChange() {
        return mSharedPreferences.getBoolean(KEY_4, true);
    }

    public boolean setIsChange() {
        final boolean isChange = !isChange();
        setIsChange(isChange);
        return isChange;
    }

    public void setCoordinates(float x, float y) {
        mSharedPreferences.edit().putFloat(KEY_5_1, x).apply();
        mSharedPreferences.edit().putFloat(KEY_5_2, y).apply();
    }

    public PointF getCoordinates() {
        final float x = mSharedPreferences.getFloat(KEY_5_1, 0);
        final float y = mSharedPreferences.getFloat(KEY_5_2, 0);
        return new PointF(x, y);
    }

}

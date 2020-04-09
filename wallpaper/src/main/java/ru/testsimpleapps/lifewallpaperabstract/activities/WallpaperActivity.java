package ru.testsimpleapps.lifewallpaperabstract.activities;

import android.app.Activity;
import android.app.WallpaperManager;
import android.content.ComponentName;
import android.content.Intent;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import androidx.annotation.Nullable;

import ru.testsimpleapps.lifewallpaperabstract.R;
import ru.testsimpleapps.lifewallpaperabstract.managers.PreferenceManager;
import ru.testsimpleapps.lifewallpaperabstract.services.WallpaperGLService;
import ru.testsimpleapps.lifewallpaperabstract.views.WallpaperSurface;

public class WallpaperActivity extends Activity implements Button.OnClickListener {

    private WallpaperSurface mWallpaperSurface;
    private Button mIncreaseParticlesButton;
    private Button mDecreaseParticlesButton;
    private Button mSetRedButton;
    private Button mSetGreenButton;
    private Button mSetBlueButton;
    private Button mSetRandomButton;
    private Button mSetDynamicUniformButton;
    private Button mSetDynamicRandomButton;
    private Button mSetStaticRandomButton;
    private Button mSetWallpaperButton;
    private Button mChangeShapeButton;
    private Button mExitButton;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.wallpaper_activity);
        init(savedInstanceState);
        setButtons();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        mWallpaperSurface.onDestroy();
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        if (mWallpaperSurface.touch(event)) {
            final float x = event.getX(event.getActionIndex());
            final float y = event.getY(event.getActionIndex());
            PreferenceManager.getInstance(getApplicationContext()).setCoordinates(x, y);
            return true;
        }

        return super.onTouchEvent(event);
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.particles_increase_button:
                mWallpaperSurface.setParticles(PreferenceManager.getInstance(getApplicationContext()).increaseParticles());
                break;
            case R.id.particles_decrease_button:
                mWallpaperSurface.setParticles(PreferenceManager.getInstance(getApplicationContext()).decreaseParticles());
                break;
            case R.id.set_red_button:
                mWallpaperSurface.setSettings(
                        PreferenceManager.getInstance(getApplicationContext()).setColorRed(),
                        PreferenceManager.getInstance(getApplicationContext()).getForm()
                );
                break;
            case R.id.set_green_button:
                mWallpaperSurface.setSettings(
                        PreferenceManager.getInstance(getApplicationContext()).setColorGreen(),
                        PreferenceManager.getInstance(getApplicationContext()).getForm()
                );
                break;
            case R.id.set_blue_button:
                mWallpaperSurface.setSettings(
                        PreferenceManager.getInstance(getApplicationContext()).setColorBlue(),
                        PreferenceManager.getInstance(getApplicationContext()).getForm()
                );
                break;
            case R.id.set_random_button:
                mWallpaperSurface.setSettings(
                        PreferenceManager.getInstance(getApplicationContext()).setColorRand(),
                        PreferenceManager.getInstance(getApplicationContext()).getForm()
                );
                break;
            case R.id.set_dynamic_uniform_button:
                mWallpaperSurface.setSettings(
                        PreferenceManager.getInstance(getApplicationContext()).getColor(),
                        PreferenceManager.getInstance(getApplicationContext()).setFormUniform()
                );
                break;
            case R.id.set_dynamic_random_button:
                mWallpaperSurface.setSettings(
                        PreferenceManager.getInstance(getApplicationContext()).getColor(),
                        PreferenceManager.getInstance(getApplicationContext()).setFormDynamic()
                );
                break;
            case R.id.set_static_random_button:
                mWallpaperSurface.setSettings(
                        PreferenceManager.getInstance(getApplicationContext()).getColor(),
                        PreferenceManager.getInstance(getApplicationContext()).setFormStatic()
                );
                break;
            case R.id.set_change_button:
                mWallpaperSurface.setIsChange(PreferenceManager.getInstance(getApplicationContext()).setIsChange());
                break;
            case R.id.set_wallpaper_button:
                setWallpaper();
                break;
            case R.id.exit_button:
                finish();
                break;
        }
    }

    private void init(@Nullable Bundle savedInstanceState) {
        mWallpaperSurface = findViewById(R.id.wallpaper_surfaces);
        setButtons();
    }

    private void setButtons() {
        mIncreaseParticlesButton = findViewById(R.id.particles_increase_button);
        mIncreaseParticlesButton.setOnClickListener(this);
        mDecreaseParticlesButton = findViewById(R.id.particles_decrease_button);
        mDecreaseParticlesButton.setOnClickListener(this);
        mSetRedButton = findViewById(R.id.set_red_button);
        mSetRedButton.setOnClickListener(this);
        mSetGreenButton = findViewById(R.id.set_green_button);
        mSetGreenButton.setOnClickListener(this);
        mSetBlueButton = findViewById(R.id.set_blue_button);
        mSetBlueButton.setOnClickListener(this);
        mSetRandomButton = findViewById(R.id.set_random_button);
        mSetRandomButton.setOnClickListener(this);
        mSetDynamicUniformButton = findViewById(R.id.set_dynamic_uniform_button);
        mSetDynamicUniformButton.setOnClickListener(this);
        mSetDynamicRandomButton = findViewById(R.id.set_dynamic_random_button);
        mSetDynamicRandomButton.setOnClickListener(this);
        mSetStaticRandomButton = findViewById(R.id.set_static_random_button);
        mSetStaticRandomButton.setOnClickListener(this);
        mSetWallpaperButton = findViewById(R.id.set_wallpaper_button);
        mSetWallpaperButton.setOnClickListener(this);
        mChangeShapeButton = findViewById(R.id.set_change_button);
        mChangeShapeButton.setOnClickListener(this);
        mExitButton = findViewById(R.id.exit_button);
        mExitButton.setOnClickListener(this);
    }

    private void setWallpaper() {
        try {
            Intent intent = new Intent();
            intent.setAction(WallpaperManager.ACTION_CHANGE_LIVE_WALLPAPER);
            intent.putExtra(
                    WallpaperManager.EXTRA_LIVE_WALLPAPER_COMPONENT,
                    new ComponentName(this, WallpaperGLService.class)
            );
            startActivityForResult(intent, 0);
        } catch (Exception e) {
            Toast.makeText(this, getResources().getString(R.string.message_button_install_error), Toast.LENGTH_LONG).show();
        }
    }
}

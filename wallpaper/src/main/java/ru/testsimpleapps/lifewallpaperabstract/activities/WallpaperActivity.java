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

    private WallpaperSurface wallpaperSurface;

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
        wallpaperSurface.onDestroy();
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        if (wallpaperSurface.touch(event)) {
            final float x = event.getX(event.getActionIndex());
            final float y = event.getY(event.getActionIndex());
            PreferenceManager.getInstance(getApplicationContext()).setCoordinates(x, y);
            return true;
        }

        return super.onTouchEvent(event);
    }

    @Override
    public void onClick(View view) {
        final int id = view.getId();
        if (id == R.id.particles_increase_button) {
            wallpaperSurface.setParticles(PreferenceManager.getInstance(getApplicationContext()).increaseParticles());
        } else if (id == R.id.particles_decrease_button) {
            wallpaperSurface.setParticles(PreferenceManager.getInstance(getApplicationContext()).decreaseParticles());
        } else if (id == R.id.set_red_button) {
            wallpaperSurface.setSettings(
                    PreferenceManager.getInstance(getApplicationContext()).setColorRed(),
                    PreferenceManager.getInstance(getApplicationContext()).getForm()
            );
        } else if (id == R.id.set_green_button) {
            wallpaperSurface.setSettings(
                    PreferenceManager.getInstance(getApplicationContext()).setColorGreen(),
                    PreferenceManager.getInstance(getApplicationContext()).getForm()
            );
        } else if (id == R.id.set_blue_button) {
            wallpaperSurface.setSettings(
                    PreferenceManager.getInstance(getApplicationContext()).setColorBlue(),
                    PreferenceManager.getInstance(getApplicationContext()).getForm()
            );
        } else if (id == R.id.set_random_button) {
            wallpaperSurface.setSettings(
                    PreferenceManager.getInstance(getApplicationContext()).setColorRand(),
                    PreferenceManager.getInstance(getApplicationContext()).getForm()
            );
        } else if (id == R.id.set_dynamic_uniform_button) {
            wallpaperSurface.setSettings(
                    PreferenceManager.getInstance(getApplicationContext()).getColor(),
                    PreferenceManager.getInstance(getApplicationContext()).setFormUniform()
            );
        } else if (id == R.id.set_dynamic_random_button) {
            wallpaperSurface.setSettings(
                    PreferenceManager.getInstance(getApplicationContext()).getColor(),
                    PreferenceManager.getInstance(getApplicationContext()).setFormDynamic()
            );
        } else if (id == R.id.set_static_random_button) {
            wallpaperSurface.setSettings(
                    PreferenceManager.getInstance(getApplicationContext()).getColor(),
                    PreferenceManager.getInstance(getApplicationContext()).setFormStatic()
            );
        } else if (id == R.id.set_change_button) {
            wallpaperSurface.setIsChange(PreferenceManager.getInstance(getApplicationContext()).setIsChange());
        } else if (id == R.id.set_wallpaper_button) {
            setWallpaper();
        } else if (id == R.id.exit_button) {
            finish();
        }
    }

    private void init(@Nullable Bundle savedInstanceState) {
        wallpaperSurface = findViewById(R.id.wallpaper_surfaces);
        setButtons();
    }

    private void setButtons() {
        findViewById(R.id.particles_increase_button).setOnClickListener(this);
        findViewById(R.id.particles_decrease_button).setOnClickListener(this);
        findViewById(R.id.set_red_button).setOnClickListener(this);
        findViewById(R.id.set_green_button).setOnClickListener(this);
        findViewById(R.id.set_blue_button).setOnClickListener(this);
        findViewById(R.id.set_random_button).setOnClickListener(this);
        findViewById(R.id.set_dynamic_uniform_button).setOnClickListener(this);
        findViewById(R.id.set_dynamic_random_button).setOnClickListener(this);
        findViewById(R.id.set_static_random_button).setOnClickListener(this);
        findViewById(R.id.set_wallpaper_button).setOnClickListener(this);
        findViewById(R.id.set_change_button).setOnClickListener(this);
        findViewById(R.id.exit_button).setOnClickListener(this);
    }

    private void setWallpaper() {
        try {
            final Intent intent = new Intent();
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

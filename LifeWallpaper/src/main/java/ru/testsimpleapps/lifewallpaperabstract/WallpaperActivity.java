package ru.testsimpleapps.lifewallpaperabstract;

import android.app.Activity;
import android.app.ActivityManager;
import android.app.WallpaperManager;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.pm.ConfigurationInfo;
import android.os.Build;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import java.lang.reflect.Method;

public class WallpaperActivity extends Activity implements Button.OnClickListener{

    // Hold a reference to our GLSurfaceView
    private static WallpaperGLSurfaceViewActivity wallpaperGLSurfaceViewActivity = null;
    private Button increaseParticles;
    private Button decreaseParticles;
    private Button installRed;
    private Button installGreen;
    private Button installBlue;
    private Button installRandom;
    private Button installDynamicUniform;
    private Button installDynamicRandom;
    private Button installStaticRandom;
    private Button installWallpaper;
    private Button changeShape;
    private Button exit;
    public static Toast TOAST_OBJ;

    @Override
    public void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        setContentView(R.layout.life_wallpaper_activity);
        // Surface
        wallpaperGLSurfaceViewActivity = (WallpaperGLSurfaceViewActivity) findViewById(R.id.gl_surfaces_view);
        // Actions
        setButtonActions();
        // Advice
        TOAST_OBJ = Toast.makeText(this, "Live Wallpaper", Toast.LENGTH_SHORT);

        // Check if the system supports OpenGL ES 2.0.
        final ActivityManager activityManager = (ActivityManager) getSystemService(Context.ACTIVITY_SERVICE);
        final ConfigurationInfo configurationInfo = activityManager.getDeviceConfigurationInfo();
        final boolean supportsEs2 = configurationInfo.reqGlEsVersion >= 0x20000;

        if (supportsEs2){
            // Request an OpenGL ES 2.0 compatible context.
            wallpaperGLSurfaceViewActivity.setEGLContextClientVersion(2);
            // Set GLRender
            wallpaperGLSurfaceViewActivity.setRenderer(new WallpaperGLRender());
        } else {
            // This is where you could create an OpenGL ES 1.x compatible
            // renderer if you wanted to support both ES 1 and ES 2.
            return;
        }
    }

    @Override
    protected void onResume() {
        super.onResume();
        wallpaperGLSurfaceViewActivity.onResume();
    }

    @Override
    protected void onPause() {
        super.onPause();
        wallpaperGLSurfaceViewActivity.onPause();
    }

    @Override
    protected void onDestroy() {
        Log.d(WallpaperLib.TAG, this.getClass().toString() + " - onDestroy");
        super.onDestroy();
        WallpaperApplication.getApplication().savePreferences();
        if(!GLWallpaperOpenService.isWallpaperSet())
            WallpaperLib.exit();
        wallpaperGLSurfaceViewActivity = null;
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()){
            case R.id.button_particles_increase:
                WallpaperApplication.getApplication().increaseParticlesCount();
                TOAST_OBJ.setText(getResources().getString(R.string.message_button_particles) + " " + WallpaperApplication.getApplication().getParticlesCount());
                TOAST_OBJ.show();
                // Change ;)
                WallpaperGLRender.setIsNeedChange();
                break;
            case R.id.button_particles_decrease:
                WallpaperApplication.getApplication().decreaseParticlesCount();
                TOAST_OBJ.setText(getResources().getString(R.string.message_button_particles) + " " + WallpaperApplication.getApplication().getParticlesCount());
                TOAST_OBJ.show();
                // Change ;)
                WallpaperGLRender.setIsNeedChange();
                break;
            case R.id.button_install_red:
                WallpaperApplication.getApplication().setColor(WallpaperApplication.RED);
                WallpaperLib.setSettings(   WallpaperApplication.getApplication().getColors(),
                                            WallpaperApplication.getApplication().getForms());
                TOAST_OBJ.setText(getResources().getString(R.string.message_button_red));
                TOAST_OBJ.show();
                break;
            case R.id.button_install_green:
                WallpaperApplication.getApplication().setColor(WallpaperApplication.GREEN);
                WallpaperLib.setSettings(   WallpaperApplication.getApplication().getColors(),
                                            WallpaperApplication.getApplication().getForms());
                TOAST_OBJ.setText(getResources().getString(R.string.message_button_green));
                TOAST_OBJ.show();
                break;
            case R.id.button_install_blue:
                WallpaperApplication.getApplication().setColor(WallpaperApplication.BLUE);
                WallpaperLib.setSettings(   WallpaperApplication.getApplication().getColors(),
                                            WallpaperApplication.getApplication().getForms());
                TOAST_OBJ.setText(getResources().getString(R.string.message_button_blue));
                TOAST_OBJ.show();
                break;
            case R.id.button_install_random:
                WallpaperApplication.getApplication().setColor(WallpaperApplication.RAND);
                WallpaperLib.setSettings(   WallpaperApplication.getApplication().getColors(),
                                            WallpaperApplication.getApplication().getForms());
                TOAST_OBJ.setText(getResources().getString(R.string.message_button_random));
                TOAST_OBJ.show();
                break;
            case R.id.button_install_dynamic_uniform:
                WallpaperApplication.getApplication().setForms(WallpaperApplication.DYNAMIC_UNIFORM);
                WallpaperLib.setSettings(   WallpaperApplication.getApplication().getColors(),
                                            WallpaperApplication.getApplication().getForms());
                TOAST_OBJ.setText(getResources().getString(R.string.message_button_dynamic_uniform));
                TOAST_OBJ.show();
                break;
            case R.id.button_install_dynamic_random:
                WallpaperApplication.getApplication().setForms(WallpaperApplication.DYNAMIC_RANDOM);
                WallpaperLib.setSettings(   WallpaperApplication.getApplication().getColors(),
                                            WallpaperApplication.getApplication().getForms());
                TOAST_OBJ.setText(getResources().getString(R.string.message_button_dynamic_random));
                TOAST_OBJ.show();
                break;
            case R.id.button_install_static_random:
                WallpaperApplication.getApplication().setForms(WallpaperApplication.STATIC_RANDOM);
                WallpaperLib.setSettings(   WallpaperApplication.getApplication().getColors(),
                                            WallpaperApplication.getApplication().getForms());
                TOAST_OBJ.setText(getResources().getString(R.string.message_button_static_random));
                TOAST_OBJ.show();
                break;
            case R.id.button_set_change:
                WallpaperApplication.getApplication().setIsChange();
                WallpaperLib.setIsChange(WallpaperApplication.getApplication().isChange());
                TOAST_OBJ.setText(getResources().getString(R.string.message_button_set_change));
                TOAST_OBJ.show();
                break;
            case R.id.button_install_wallpaper:
                setWallpaper();
                TOAST_OBJ.setText(getResources().getString(R.string.message_button_wallpaper));
                TOAST_OBJ.show();
                break;
            case R.id.button_exit:
                TOAST_OBJ.setText(getResources().getString(R.string.message_button_exit));
                TOAST_OBJ.show();
                finish();
                break;
        }
    }


    private void setButtonActions(){
        // Buttons
        increaseParticles = (Button) findViewById(R.id.button_particles_increase);
        increaseParticles.setOnClickListener(this);
        decreaseParticles = (Button) findViewById(R.id.button_particles_decrease);
        decreaseParticles.setOnClickListener(this);
        installRed = (Button) findViewById(R.id.button_install_red);
        installRed.setOnClickListener(this);
        installGreen = (Button) findViewById(R.id.button_install_green);
        installGreen.setOnClickListener(this);
        installBlue = (Button) findViewById(R.id.button_install_blue);
        installBlue.setOnClickListener(this);
        installRandom = (Button) findViewById(R.id.button_install_random);
        installRandom.setOnClickListener(this);
        installDynamicUniform = (Button) findViewById(R.id.button_install_dynamic_uniform);
        installDynamicUniform.setOnClickListener(this);
        installDynamicRandom = (Button) findViewById(R.id.button_install_dynamic_random);
        installDynamicRandom.setOnClickListener(this);
        installStaticRandom = (Button) findViewById(R.id.button_install_static_random);
        installStaticRandom.setOnClickListener(this);
        installWallpaper = (Button) findViewById(R.id.button_install_wallpaper);
        installWallpaper.setOnClickListener(this);
        changeShape = (Button) findViewById(R.id.button_set_change);
        changeShape.setOnClickListener(this);
        exit = (Button) findViewById(R.id.button_exit);
        exit.setOnClickListener(this);
    }

    private void setWallpaper(){
        try {
            Intent intent = new Intent();
            if(Build.VERSION.SDK_INT > 15){
                intent.setAction(WallpaperManager.ACTION_CHANGE_LIVE_WALLPAPER);
                String p = WallpaperService.class.getPackage().getName();
                String c = WallpaperService.class.getCanonicalName();
                intent.putExtra(WallpaperManager.EXTRA_LIVE_WALLPAPER_COMPONENT, new ComponentName(p, c));
            } else {
                    intent.setAction(WallpaperManager.ACTION_LIVE_WALLPAPER_CHOOSER);
                }

            startActivityForResult(intent, 0);
        } catch(Exception e){
            e.printStackTrace();
            try {
                WallpaperManager manager = WallpaperManager.getInstance(this);
                Method method = WallpaperManager.class.getMethod("getIWallpaperManager", null);
                Object objIWallpaperManager = method.invoke(manager, null);
                Class[] param = new Class[1];
                param[0] = ComponentName.class;
                method = objIWallpaperManager.getClass().getMethod("setWallpaperComponent", param);

                // Get the intent of the desired wallpaper service. Note: I created my own
                // Custom wallpaper service. You'll need a class reference and package
                // Of the desired live wallpaper
                Intent intent = new Intent(WallpaperService.SERVICE_INTERFACE);
                intent.setClassName(this.getPackageName(), WallpaperService.class.getName());

                // Set the live wallpaper (throws security exception if you're not system-privileged app)
                method.invoke(objIWallpaperManager, intent.getComponent());
            } catch(Exception ex){
                ex.printStackTrace();
                Toast.makeText(this, getResources().getString(R.string.message_button_install_error), Toast.LENGTH_LONG).show();
            }
        }
    }

    public static boolean isActivity(){
        if(wallpaperGLSurfaceViewActivity != null)
            return true;
        return false;
    }
}

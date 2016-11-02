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

public class LifeWallpaperActivity extends Activity implements Button.OnClickListener{
    // Hold a reference to our GLSurfaceView
    private WallpaperGLSurfaceViewActivity wallpaperGLSurfaceViewActivity;
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
        // Buttons
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
        // Advice
        TOAST_OBJ = Toast.makeText(this, "Life Wallpaper", Toast.LENGTH_SHORT);

        // Check if the system supports OpenGL ES 2.0.
        final ActivityManager activityManager = (ActivityManager) getSystemService(Context.ACTIVITY_SERVICE);
        final ConfigurationInfo configurationInfo = activityManager.getDeviceConfigurationInfo();
        final boolean supportsEs2 = configurationInfo.reqGlEsVersion >= 0x20000;

        if (supportsEs2){
            // Request an OpenGL ES 2.0 compatible context.
            wallpaperGLSurfaceViewActivity.setEGLContextClientVersion(2);
            // Set the renderer to our wallpaper, defined below.
            wallpaperGLSurfaceViewActivity.setRenderer(new WallpaperGLRender());
        } else {
            // This is where you could create an OpenGL ES 1.x compatible
            // renderer if you wanted to support both ES 1 and ES 2.
            return;
        }
    }

    @Override
    protected void onResume(){
        // The activity must call the GL surface view's onResume() on activity onResume().
        super.onResume();
        Log.d(WallpaperLib.TAG, this.getClass().toString() + " - onResume");
        wallpaperGLSurfaceViewActivity.onResume();
    }

    @Override
    protected void onPause(){
        // The activity must call the GL surface view's onPause() on activity onPause().
        super.onPause();
        Log.d(WallpaperLib.TAG, this.getClass().toString() + " - onPause");
        wallpaperGLSurfaceViewActivity.onPause();
    }

    @Override
    protected void onStop() {
        super.onStop();
        Log.d(WallpaperLib.TAG, this.getClass().toString() + " - onPause");
        if(!GLWallpaperOpenService.isWallpaperSet())
            WallpaperLib.exit();
        WallpaperApplication.getApplication().savePreferences();
    }

    @Override
    public void onClick(View view) {
        //Log.d(WallpaperLib.TAG, "EVENT THREAD: " + Thread.currentThread().getId());
        switch (view.getId()){
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

    private void setWallpaper(){
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
    }
}

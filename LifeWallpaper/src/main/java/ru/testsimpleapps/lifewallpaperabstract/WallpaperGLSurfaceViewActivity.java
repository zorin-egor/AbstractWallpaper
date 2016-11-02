package ru.testsimpleapps.lifewallpaperabstract;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.util.AttributeSet;
import android.util.Log;
import android.view.MotionEvent;

public class WallpaperGLSurfaceViewActivity extends GLSurfaceView {

    private static int countTouch;
    private Context context;
    private static WallpaperGLSurfaceViewActivity wallpaperGLSurfaceViewActivity;

    public WallpaperGLSurfaceViewActivity(Context context, AttributeSet attrs){
        super(context, attrs);
        this.context = context;
        wallpaperGLSurfaceViewActivity = this;
        countTouch = 0;
    }

    public static WallpaperGLSurfaceViewActivity getWallpaperGLSurfaceViewActivity(){
        return WallpaperGLSurfaceViewActivity.wallpaperGLSurfaceViewActivity;
    }

    @Override
    public void onPause() {
        super.onPause();
        Log.d(WallpaperLib.TAG, this.getClass().toString() + " - onPause");
        WallpaperLib.destroyPrevious();
    }

    @Override
    public boolean onTouchEvent(final MotionEvent event) {
        getMove(event);
        return true;
    }

    public static void getMove(final MotionEvent event) {
        // Get actions DOWN and UP touch and count them
        switch (event.getActionMasked()) {
            case MotionEvent.ACTION_DOWN:
            case MotionEvent.ACTION_POINTER_DOWN:
                countTouch++;

                // Off/on dynamic change
                if (countTouch >= 3){
                    WallpaperApplication.getApplication().setIsChange();
                    WallpaperLib.setIsChange(WallpaperApplication.getApplication().isChange());
                    LifeWallpaperActivity.TOAST_OBJ.setText(WallpaperApplication.getAppContext().getResources().getString(R.string.message_button_set_change_points) + " " +
                                                            WallpaperApplication.getApplication().isChange());
                    LifeWallpaperActivity.TOAST_OBJ.show();
                }

                break;

            case MotionEvent.ACTION_UP:
            case MotionEvent.ACTION_POINTER_UP:
                countTouch--;
                break;
        }

        // If we have 2 touch points, then do action
        if (countTouch == 2)
            WallpaperLib.action(event.getX(event.getActionIndex()), event.getY(event.getActionIndex()));
    }
}
package ru.testsimpleapps.lifewallpaperabstract.views;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.os.Build;
import android.util.AttributeSet;
import android.view.MotionEvent;

import ru.testsimpleapps.lifewallpaperabstract.WallpaperLib;


public class WallpaperSurface extends GLSurfaceView {

    private WallpaperRender mWallpaperRender;

    public WallpaperSurface(Context context) {
        super(context);
        init();
    }

    public WallpaperSurface(Context context, AttributeSet attrs) {
        super(context, attrs);
        init();
    }

    public void onDestroy() {
        WallpaperLib.destroy(mWallpaperRender.hashCode());
        super.onDetachedFromWindow();
    }

    private void init() {
        mWallpaperRender = new WallpaperRender(getContext());
        setEGLContextClientVersion(2);
        setRenderer(mWallpaperRender);

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.HONEYCOMB) {
            setPreserveEGLContextOnPause(true);
        }
    }

    public void setParticles(int count) {
        WallpaperLib.setParticles(count);
    }

    public void setSettings(int color, int form) {
        WallpaperLib.setSettings(color, form);
    }

    public void setIsChange(boolean isChange) {
        WallpaperLib.setIsChange(isChange);
    }

    public boolean touch(final MotionEvent event) {
        switch (event.getActionMasked()) {
            case MotionEvent.ACTION_MOVE:
                if (event.getPointerCount() < 3) {
                    WallpaperLib.action(
                            mWallpaperRender.hashCode(),
                            event.getX(event.getActionIndex()),
                            event.getY(event.getActionIndex())
                    );
                }
                return true;
        }

        return false;
    }
}
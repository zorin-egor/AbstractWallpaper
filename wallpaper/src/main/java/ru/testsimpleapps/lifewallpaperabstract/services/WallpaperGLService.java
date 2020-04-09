package ru.testsimpleapps.lifewallpaperabstract.services;

import android.service.wallpaper.WallpaperService;
import android.view.MotionEvent;
import android.view.SurfaceHolder;

import ru.testsimpleapps.lifewallpaperabstract.views.WallpaperSurface;


public class WallpaperGLService extends WallpaperService {

    @Override
    public Engine onCreateEngine() {
        return new GLWallpaperEngine();
    }

    public class GLWallpaperEngine extends Engine {

        WallpaperSurface mWallpaperSurface;

        @Override
        public void onCreate(SurfaceHolder surfaceHolder) {
            super.onCreate(surfaceHolder);
            mWallpaperSurface = new WallpaperSurface(getApplicationContext()) {
                @Override
                public SurfaceHolder getHolder() {
                    return GLWallpaperEngine.this.getSurfaceHolder();
                }
            };
        }

        @Override
        public void onDestroy() {
            super.onDestroy();
            mWallpaperSurface.onDestroy();
        }

        @Override
        public void onVisibilityChanged(boolean visible) {
            super.onVisibilityChanged(visible);
            if (visible) {
                mWallpaperSurface.onResume();
            } else {
                mWallpaperSurface.onPause();
            }
        }

        @Override
        public void onTouchEvent(final MotionEvent event) {
//            mWallpaperSurface.touch(event);
        }
    }
}

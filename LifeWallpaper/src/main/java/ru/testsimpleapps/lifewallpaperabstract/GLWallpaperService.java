package ru.testsimpleapps.lifewallpaperabstract;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.opengl.GLSurfaceView.Renderer;
import android.os.Build;
import android.service.wallpaper.WallpaperService;
import android.util.Log;
import android.view.MotionEvent;
import android.view.SurfaceHolder;

public abstract class GLWallpaperService extends WallpaperService {

    public class GLEngine extends Engine {
        class WallpaperGLSurfaceView extends GLSurfaceView {

            WallpaperGLSurfaceView(Context context) {
                super(context);
            }

            @Override
            public void onPause() {
                super.onPause();
                Log.d(WallpaperLib.TAG, this.getClass().toString() + " - onPause");
                WallpaperLib.destroyPrevious();
            }

            @Override
            public SurfaceHolder getHolder() {
                Log.d(WallpaperLib.TAG, this.getClass().toString() + " - getHolder");
                return getSurfaceHolder();
            }

            public void onDestroy() {
                Log.d(WallpaperLib.TAG, this.getClass().toString() + " - onDestroy");
                super.onDetachedFromWindow();
            }
        }

        private WallpaperGLSurfaceView glSurfaceView;
        private boolean rendererHasBeenSet;

        @Override
        public void onCreate(SurfaceHolder surfaceHolder) {
            super.onCreate(surfaceHolder);
            Log.d(WallpaperLib.TAG, this.getClass().toString() + " - onCreate");
            glSurfaceView = new WallpaperGLSurfaceView(GLWallpaperService.this);
        }

        @Override
        public void onVisibilityChanged(boolean visible) {
            super.onVisibilityChanged(visible);
            Log.d(WallpaperLib.TAG, this.getClass().toString() + " - onVisibilityChanged - " + visible);
            if (rendererHasBeenSet) {
                if (visible) {
                    glSurfaceView.onResume();
                } else {
                    glSurfaceView.onPause();
                }
            }
        }

        @Override
        public void onDestroy() {
            super.onDestroy();
            Log.d(WallpaperLib.TAG, this.getClass().toString() + " - onDestroy");
            glSurfaceView.onDestroy();
        }

        @Override
        public void onTouchEvent(final MotionEvent event) {
            //Log.d(WallpaperLib.TAG, this.getClass().toString() + " - onTouchEvent; GetX: " + event.getX(event.getActionIndex()) + "; GetY: " + event.getY(event.getActionIndex()));
            WallpaperGLSurfaceViewActivity.getMove(event);
        }

        protected void setRenderer(Renderer renderer) {
            glSurfaceView.setRenderer(renderer);
            rendererHasBeenSet = true;
        }

        protected void setPreserveEGLContextOnPause(boolean preserve) {
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.HONEYCOMB) {
                glSurfaceView.setPreserveEGLContextOnPause(preserve);
            }
        }

        protected void setEGLContextClientVersion(int version) {
            glSurfaceView.setEGLContextClientVersion(version);
        }
    }
}

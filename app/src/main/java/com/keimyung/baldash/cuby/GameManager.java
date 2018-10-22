package com.keimyung.baldash.cuby;
import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.PointF;
import android.support.v4.view.GestureDetectorCompat;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

import com.keimyung.baldash.cuby.GameObjects.Platform;
import com.keimyung.baldash.cuby.GameObjects.Player;
import com.keimyung.baldash.cuby.Handlers.EntitiesHandler;
import com.keimyung.baldash.cuby.Handlers.InputManager;
import com.keimyung.baldash.cuby.Handlers.ResourcesHandler;
import com.keimyung.baldash.cuby.Misc.EPlatformType;

public class GameManager extends SurfaceView implements SurfaceHolder.Callback {

    private MainThread thread;
    private Player player;
    private Platform platform;
    private GestureDetectorCompat gestureDetectorCompat;
    private InputManager inputManager;

    public GameManager(Context context)
    {
        super(context);

        initResources();

        inputManager = new InputManager(this);
        gestureDetectorCompat = new GestureDetectorCompat(context, inputManager);

        getHolder().addCallback(this);
        thread = new MainThread(getHolder(), this);
        setFocusable(true);

        player = new Player(new PointF(300, 300));
        EntitiesHandler.getInstance().addEntity("player", player);

        platform = new Platform(EPlatformType.BASIC, new PointF(200, 200));
        EntitiesHandler.getInstance().addEntity("basicPlatform", platform);
    }

    ///// METHODS

    public void initResources()
    {
        ResourcesHandler.getInstance().addResource(R.drawable.cubypng, "cuby");
        ResourcesHandler.getInstance().addResource(R.drawable.basicplatform, "basicPlatform");
    }

    public void update()
    {
        EntitiesHandler.getInstance().updateAll();
    }

    public void draw(Canvas canvas)
    {
        super.draw(canvas);

        canvas.drawColor(Color.WHITE);
        EntitiesHandler.getInstance().drawAll(canvas);
    }

    ///// OVERRIDES

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {}

    @Override
    public void surfaceCreated(SurfaceHolder holder)
    {
        thread = new MainThread(getHolder(), this);

        thread.setRunning(true);
        thread.start();
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder)
    {
        boolean retry = true;

        while (true)
        {
            try {
                thread.setRunning(true);
                thread.join();
            } catch (Exception e) {
                e.printStackTrace();
            }
            retry = false;
        }
    }

    @Override
    public boolean onTouchEvent(MotionEvent event)
    {
        gestureDetectorCompat.onTouchEvent(event);

        return true;
        // return super.onTouchEvent(event);
    }

}

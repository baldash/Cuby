package com.keimyung.baldash.cuby;

import android.app.Activity;
import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.PointF;
import android.support.v4.view.GestureDetectorCompat;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.widget.TextView;

import com.keimyung.baldash.cuby.GameObjects.GameObject;
import com.keimyung.baldash.cuby.GameObjects.Player;
import com.keimyung.baldash.cuby.Handlers.EntitiesHandler;
import com.keimyung.baldash.cuby.Handlers.InputManager;
import com.keimyung.baldash.cuby.Handlers.PlatformHandler;
import com.keimyung.baldash.cuby.Handlers.ResourcesHandler;

import org.w3c.dom.Text;

import java.text.DecimalFormat;
import java.util.List;

import javax.vecmath.Vector2d;

public class GameManager extends SurfaceView implements SurfaceHolder.Callback {

    private MainThread thread;
    private GestureDetectorCompat gestureDetectorCompat;
    private InputManager inputManager;
    private PlatformHandler platformHandler;
    private Activity gameActivity;

    private Player player;

    private Vector2d gameSpeed;
    private double totalDistance = 0;
    private boolean bStarted = false;

    private TextView scoreText;
    private TextView cooldownText;

    public GameManager(Context context)
    {
        super(context);

        initResources();

        gameActivity = (Activity)context;

        // inputs
        inputManager = new InputManager(this);
        gestureDetectorCompat = new GestureDetectorCompat(context, inputManager);
        platformHandler = new PlatformHandler();

        // main thread
        getHolder().addCallback(this);
        thread = new MainThread(getHolder(), this);
        setFocusable(true);

        gameSpeed = new Vector2d(-80, 0);

        player = new Player(new PointF(250, 225));
        EntitiesHandler.getInstance().addEntity("player", player);
    }

    ///// GETTERS

    public Player getPlayer()
    {
        return player;
    }

    public boolean gameStarted()
    {
        return bStarted;
    }

    ///// SETTERS

    public void setHUDElements(TextView scoreText, TextView cooldownText)
    {
        this.scoreText = scoreText;
        this.cooldownText = cooldownText;
    }

    ///// METHODS

    public void initResources()
    {
        ResourcesHandler.getInstance().addResource(R.drawable.cubypng, "cuby");
        ResourcesHandler.getInstance().addResource(R.drawable.basicplatform, "basicPlatform");
    }

    public void update()
    {
        if (bStarted)
        {
            platformHandler.update();
            updateDistance();
            EntitiesHandler.getInstance().updateAll();
        }
    }

    public void draw(Canvas canvas)
    {
        super.draw(canvas);

        canvas.drawColor(Color.WHITE);
        EntitiesHandler.getInstance().drawAll(canvas);
    }

    public void onInputUp(PointF pos)
    {
        if (pos.x > 330)
            platformHandler.placePlatform(pos, gameSpeed);
    }

    private void updateDistance()
    {
        Vector2d scaledVelocity = new Vector2d();

        scaledVelocity.scale(MainThread.getDeltaTime(), gameSpeed);
        totalDistance += scaledVelocity.x * -1;

        if (totalDistance > 500 && gameSpeed.x > -130)
            updateGameSpeed(-130);
        else if (totalDistance > 1000 && gameSpeed.x > -180)
            updateGameSpeed(-180);
        else if (totalDistance > 2000 && gameSpeed.x > -230)
            updateGameSpeed(-230);
        else if (totalDistance > 3000 && gameSpeed.x > -300)
            updateGameSpeed(-300);

        updateScoreText();
    }

    public void updateGameSpeed(int newSpeed)
    {
        List<GameObject> platforms = EntitiesHandler.getInstance().getAllEntitiesOfName("platform");

        gameSpeed.x = newSpeed;

        if (!player.jumping())
            player.setVelocity(new Vector2d(newSpeed, 0));

        for (GameObject platform: platforms)
        {
            platform.setVelocity(new Vector2d(newSpeed, 0));
        }
    }

    public void updateScoreText()
    {
        gameActivity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                scoreText.setText(new DecimalFormat("#").format(totalDistance));
            }
        });
    }

    private void updateCooldownText()
    {
        gameActivity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                if (platformHandler.getCoolDown() == 0)
                    cooldownText.setVisibility(INVISIBLE);
                else
                {
                    cooldownText.setVisibility(VISIBLE);
                    cooldownText.setText(new DecimalFormat("#.#").format(platformHandler.getCoolDown()));
                }
            }
        });
    }

    public void startGame()
    {
        bStarted = true;
    }

    public void stopGame()
    {
        bStarted = false;
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
        if (bStarted)
        {
            gestureDetectorCompat.onTouchEvent(event);

            if (event.getAction() == MotionEvent.ACTION_UP)
                onInputUp(new PointF(event.getX(), event.getY()));
        }

        return true;
    }

}

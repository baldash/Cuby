package com.keimyung.baldash.cuby;

import android.app.Activity;
import android.content.Context;
import android.content.SharedPreferences;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.PointF;
import android.preference.PreferenceManager;
import android.support.v4.view.GestureDetectorCompat;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import com.keimyung.baldash.cuby.GameObjects.GameObject;
import com.keimyung.baldash.cuby.GameObjects.Player;
import com.keimyung.baldash.cuby.GameObjects.StartPlatform;
import com.keimyung.baldash.cuby.Handlers.EntitiesHandler;
import com.keimyung.baldash.cuby.Handlers.InputManager;
import com.keimyung.baldash.cuby.Handlers.PlatformHandler;
import com.keimyung.baldash.cuby.Handlers.ResourcesHandler;
import com.keimyung.baldash.cuby.Misc.Constants;
import com.keimyung.baldash.cuby.Misc.EPlatformType;

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
    private GameObject skyBackground;

    private Vector2d gameSpeed;
    private double totalDistance = 0;
    private boolean bStarted = false;
    private int personalBestScore = 0;

    private TextView scoreText;
    private TextView coolDownText;
    private ImageView platformIcon;
    private Button retryButton;
    private TextView bestScoreText;

    private Runnable scoreUiThread;
    private Runnable coolDownUiThread;
    private Runnable retryButtonUiThread;

    public GameManager(Context context)
    {
        super(context);

        initResources();

        gameActivity = (Activity)context;

        inputManager = new InputManager(this);
        gestureDetectorCompat = new GestureDetectorCompat(context, inputManager);
        platformHandler = new PlatformHandler();

        // main thread
        getHolder().addCallback(this);
        thread = new MainThread(getHolder(), this);
        setFocusable(true);

        scoreUiThread = new Runnable() {
            @Override
            public void run() {
                scoreText.setText(new DecimalFormat("#").format(totalDistance));
            }
        };

        coolDownUiThread = new Runnable() {
            @Override
            public void run() {
                if (platformHandler.getCoolDown() == 0)
                    coolDownText.setVisibility(INVISIBLE);
                else
                {
                    coolDownText.setVisibility(VISIBLE);
                    coolDownText.setText(new DecimalFormat("#.#").format(platformHandler.getCoolDown()));
                }
            }
        };

        retryButtonUiThread = new Runnable() {
            @Override
            public void run() {
                retryButton.setVisibility(VISIBLE);
                bestScoreText.setText("Personal best: " + personalBestScore);
                bestScoreText.setVisibility(VISIBLE);
            }
        };

        initGame();
        retrieveBestScore();
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

    public void setHUDElements(TextView scoreText, TextView coolDownText, ImageView platformIcon, Button retryButton, TextView bestScoreText)
    {
        this.scoreText = scoreText;
        this.coolDownText = coolDownText;
        this.platformIcon = platformIcon;
        this.retryButton = retryButton;
        this.bestScoreText = bestScoreText;
    }

    ///// METHODS

    public void initResources()
    {
        ResourcesHandler.getInstance().addResource(R.drawable.goodcubix, "cuby");
        ResourcesHandler.getInstance().addResource(R.drawable.basicplatform, "basic-platform");
        ResourcesHandler.getInstance().addResource(R.drawable.moving_v_platform, "moving-v-platform");
        ResourcesHandler.getInstance().addResource(R.drawable.ghost_platform, "ghost-platform");
        ResourcesHandler.getInstance().addResource(R.drawable.quick_platform, "quick-platform");
        ResourcesHandler.getInstance().addResource(R.drawable.jumping_platform, "jumping-platform");
    }

    public void update()
    {
        if (bStarted)
        {
            checkPlayerDeath();
            platformHandler.update();
            updateDistance();
            updateCoolDownText();
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
        if (pos.x > 330 && pos.x > (player.getSprite().getPos().x - 150))
        {
            platformHandler.placePlatform(pos, gameSpeed);
            updatePlatformIcon();
        }
    }

    private void updateDistance()
    {
        Vector2d scaledVelocity = new Vector2d();

        scaledVelocity.scale(MainThread.getDeltaTime(), gameSpeed);
        totalDistance += scaledVelocity.x * -1;

        if (totalDistance > 500 && gameSpeed.x > -150)
            updateGameSpeed(-150, false);
        else if (totalDistance > 1500 && gameSpeed.x > -200)
            updateGameSpeed(-200, true);
        else if (totalDistance > 3000 && gameSpeed.x > -250)
            updateGameSpeed(-250, true);
        else if (totalDistance > 7000 && gameSpeed.x > -300)
            updateGameSpeed(-300, true);
        else if (totalDistance > 15000 && gameSpeed.x > -370)
            updateGameSpeed(-370, true);
        else if (totalDistance > 25000 && gameSpeed.x > -450)
            updateGameSpeed(-450, true);

        updateScoreText();
    }

    public void updateGameSpeed(int newSpeed, boolean bUpgradeDifficulty)
    {
        List<GameObject> platforms = EntitiesHandler.getInstance().getAllEntitiesOfName("platform");

        gameSpeed.x = newSpeed;
        if (bUpgradeDifficulty)
            platformHandler.upgradeDifficulty();

        if (!player.jumping())
            player.setVelocity(new Vector2d(newSpeed, 0));

        for (GameObject platform: platforms)
        {
            platform.setVelocity(new Vector2d(newSpeed, 0));
        }
    }

    private void updateScoreText()
    {
        gameActivity.runOnUiThread(scoreUiThread);
    }

    private void updateCoolDownText()
    {
        gameActivity.runOnUiThread(coolDownUiThread);
    }

    private void updatePlatformIcon()
    {
        gameActivity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                EPlatformType nextPlatformType = platformHandler.getNextPlatformType();

                if (platformIcon.getVisibility() == INVISIBLE)
                    togglePlatformIcon(true);

                switch (nextPlatformType)
                {
                    case BASIC:
                        platformIcon.setImageResource(R.drawable.basicplatform);
                        break;
                    case MOVING_V:
                        platformIcon.setImageResource(R.drawable.moving_v_platform);
                        break;
                    case QUICK:
                        platformIcon.setImageResource(R.drawable.quick_platform);
                        break;
                    case GHOST:
                        platformIcon.setImageResource(R.drawable.ghost_platform);
                        break;
                    case JUMPING:
                        platformIcon.setImageResource(R.drawable.jumping_platform);
                        break;
                    case NONE:
                        togglePlatformIcon(false);
                }
            }
        });
    }

    public void startGame()
    {
        bStarted = true;
        scoreText.setVisibility(VISIBLE);
        platformHandler.generateNextPlatformType();
        updatePlatformIcon();
        togglePlatformIcon(true);
    }

    public void stopGame()
    {
        bStarted = false;
    }

    public void togglePlatformIcon(boolean visible)
    {
        platformIcon.setVisibility(visible ? VISIBLE : INVISIBLE);
    }

    private void gameOver()
    {
        stopGame();
        platformHandler.resetCoolDown();
        scoreText.setVisibility(INVISIBLE);
        EntitiesHandler.getInstance().reset();
        if ((int)totalDistance > personalBestScore)
        {
            personalBestScore = (int)totalDistance;
            saveBestScore();
        }
        gameActivity.runOnUiThread(retryButtonUiThread);
    }

    public void initGame()
    {
        gameSpeed = new Vector2d(-120, 0);
        totalDistance = 0;

        // create player and start platform
        player = new Player(new PointF(75, 425));
        EntitiesHandler.getInstance().addEntity("player", player);

        StartPlatform startPlatform = new StartPlatform(new PointF(0, 500), new Vector2d(0, 0));
        EntitiesHandler.getInstance().addEntity("start-platform", startPlatform);

        if (scoreText != null)
            gameActivity.runOnUiThread(scoreUiThread);
    }

    private void checkPlayerDeath()
    {
        if ((player.getSprite().getPos().x + player.getSprite().getWidth()) < 0 ||
            player .getSprite().getPos().x > Constants.SCREEN_WIDTH ||
            player.getSprite().getPos().y > Constants.SCREEN_HEIGHT)
            gameOver();
    }

    private void saveBestScore()
    {
        SharedPreferences sp = PreferenceManager.getDefaultSharedPreferences(gameActivity);
        SharedPreferences.Editor editor = sp.edit();

        editor.putInt("best_score", personalBestScore);
        editor.apply();
    }

    private void retrieveBestScore()
    {
        SharedPreferences sp = PreferenceManager.getDefaultSharedPreferences(gameActivity);

        personalBestScore = sp.getInt("best_score", 0);
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

        while (retry)
        {
            try {
                thread.setRunning(false);
                thread.join();
            } catch (InterruptedException e) {
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

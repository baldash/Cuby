package com.keimyung.baldash.cuby;

import android.graphics.Canvas;
import android.view.SurfaceHolder;

public class MainThread extends Thread {

    public static final int MAX_FPS = 30;
    public static double averageFPS = 30;
    private SurfaceHolder holder;
    private GameManager gameManager;
    private boolean running;
    public static Canvas canvas;

    public MainThread(SurfaceHolder holder, GameManager gameManager)
    {
        super();
        this.holder = holder;
        this.gameManager = gameManager;
    }

    ///// GETTERS

    public boolean getRunning()
    {
        return running;
    }

    public static double getDeltaTime()
    {
        return (averageFPS == 0 ? -1 : 1 / averageFPS);
    }

    ///// SETTERS

    public void setRunning(boolean running)
    {
        this.running = running;
    }

    ///// OVERRIDES

    @Override
    public void run()
    {
        long startTime;
        long timeMillis = 1000/MAX_FPS;
        long waitTime;
        long totalTime = 0;
        int frameCount = 0;
        long targetTime = 1000/MAX_FPS;

        while (running)
        {
            startTime = System.nanoTime();
            canvas = null;

            try {
                canvas = holder.lockCanvas();
                synchronized (holder) {
                    gameManager.update();
                    gameManager.draw(canvas);
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
            finally {
                if (canvas != null)
                {
                    try {
                        holder.unlockCanvasAndPost(canvas);
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            }

            // Get elapsed time in ms to perform the sleep and correct the frame time
            timeMillis = (System.nanoTime() - startTime) / 1000000;
            waitTime = targetTime - timeMillis;

            try {
                if (waitTime > 0)
                    sleep(waitTime);
            } catch (Exception e) {
                e.printStackTrace();
            }

            totalTime += System.nanoTime() - startTime;
            frameCount++;

            if (frameCount == MAX_FPS)
            {
                averageFPS = 1000 / ((totalTime / frameCount) / 1000000);
                frameCount = 0;
                totalTime = 0;
                System.out.println("Average FPS: " + averageFPS);
            }
        }
    }
}

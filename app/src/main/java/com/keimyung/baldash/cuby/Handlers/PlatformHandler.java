package com.keimyung.baldash.cuby.Handlers;

import android.graphics.PointF;

import com.keimyung.baldash.cuby.GameObjects.GhostPlatform;
import com.keimyung.baldash.cuby.GameObjects.JumpingPlatform;
import com.keimyung.baldash.cuby.GameObjects.Platform;
import com.keimyung.baldash.cuby.GameObjects.QuickPlatform;
import com.keimyung.baldash.cuby.GameObjects.VerticalPlatform;
import com.keimyung.baldash.cuby.MainThread;
import com.keimyung.baldash.cuby.Misc.EPlatformType;

import java.util.Random;

import javax.vecmath.Vector2d;

public class PlatformHandler
{
    private float coolDown;
    private float maxCoolDown = 1.0f;

    private EPlatformType nextPlatformType;
    private EPlatformType previousPlatform = EPlatformType.NONE;
    private int platformID = 0;

    private int maxPlatformIdx = 1;
    private int minPlatformIdx = 1;

    ///// GETTERS

    public float getCoolDown()
    {
        return coolDown;
    }

    public EPlatformType getNextPlatformType()
    {
        return nextPlatformType;
    }

    ///// SETTERS

    public void setMaxCoolDown(float newCoolDown)
    {
        maxCoolDown = newCoolDown;
    }

    ///// METHODS

    public void update()
    {
        if (coolDown > 0)
            coolDown = ((coolDown - MainThread.getDeltaTime()) < 0) ? 0 : (float)(coolDown - MainThread.getDeltaTime());
    }

    public void placePlatform(PointF platPos, Vector2d platSpeed)
    {
        if (coolDown == 0)
        {
            createPlatform(nextPlatformType, platPos, platSpeed);
            previousPlatform = nextPlatformType;
            coolDown = maxCoolDown;
            generateNextPlatformType();
            platformID++;
        }
    }

    public void generateNextPlatformType()
    {
        Random random = new Random();

        nextPlatformType = EPlatformType.values()[minPlatformIdx + random.nextInt(maxPlatformIdx)];
        if (previousPlatform == EPlatformType.JUMPING && nextPlatformType == EPlatformType.JUMPING)
            nextPlatformType = EPlatformType.BASIC;
    }

    public void createPlatform(EPlatformType type, PointF pos, Vector2d speed)
    {
        switch (type)
        {
            case BASIC:
                EntitiesHandler.getInstance().addEntity("platform " + platformID, new Platform(nextPlatformType, pos, speed));
                break;
            case GHOST:
                EntitiesHandler.getInstance().addEntity("platform " + platformID, new GhostPlatform(pos, speed));
                break;
            case MOVING_V:
                EntitiesHandler.getInstance().addEntity("platform " + platformID, new VerticalPlatform(pos, speed));
                break;
            case QUICK:
                EntitiesHandler.getInstance().addEntity("platform " + platformID, new QuickPlatform(pos, speed));
                break;
            case JUMPING:
                EntitiesHandler.getInstance().addEntity("platform " + platformID, new JumpingPlatform(pos, speed));
                break;
        }
    }

    public void resetCoolDown()
    {
        coolDown = 0;
    }

    public void upgradeDifficulty()
    {
        if (maxPlatformIdx < (EPlatformType.values().length - 1))
            maxPlatformIdx++;
        else if (minPlatformIdx < 3)
            minPlatformIdx++;
    }
}

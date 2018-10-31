package com.keimyung.baldash.cuby.Handlers;

import android.graphics.PointF;

import com.keimyung.baldash.cuby.GameObjects.Platform;
import com.keimyung.baldash.cuby.MainThread;
import com.keimyung.baldash.cuby.Misc.EPlatformType;

import javax.vecmath.Vector2d;

public class PlatformHandler
{
    private float coolDown;
    private float maxCoolDown = 1.0f;
    private EPlatformType nextPlatformType;
    private int platformID = 0;

    ///// GETTERS

    public float getCoolDown()
    {
        return coolDown;
    }

    public EPlatformType getnextPlatformType()
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
            EntitiesHandler.getInstance().addEntity("platform " + platformID, new Platform(nextPlatformType, platPos, platSpeed));

            coolDown = maxCoolDown;
            generateNextPlatformType();
            platformID++;
        }
    }

    public void generateNextPlatformType()
    {
        // random to determine next platform type depending on difficulty
        nextPlatformType = EPlatformType.BASIC;
    }
}

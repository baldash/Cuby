package com.keimyung.baldash.cuby.GameObjects;

import android.graphics.PointF;

import com.keimyung.baldash.cuby.Handlers.EntitiesHandler;
import com.keimyung.baldash.cuby.Misc.EPlatformType;

import javax.vecmath.Vector2d;

public class StartPlatform extends Platform
{
    public StartPlatform(PointF pos, Vector2d velocity)
    {
        super(EPlatformType.BASIC, pos, velocity);

        bPlayerIsOn = true;
        playerInstance.onPlatform(this);
    }

    ///// OVERRIDES


    @Override
    public void update()
    {
        if (playerInstance.jumping())
        {
            visible = false;
            enabled = false;
            EntitiesHandler.getInstance().removeEntity(this);
        }
    }
}

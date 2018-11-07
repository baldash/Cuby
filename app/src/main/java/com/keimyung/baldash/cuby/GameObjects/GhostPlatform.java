package com.keimyung.baldash.cuby.GameObjects;

import android.graphics.PointF;

import com.keimyung.baldash.cuby.Handlers.EntitiesHandler;
import com.keimyung.baldash.cuby.MainThread;
import com.keimyung.baldash.cuby.Misc.EPlatformType;

import javax.vecmath.Vector2d;

public class GhostPlatform extends Platform
{

    private float lifeTime = 1.3f;

    public GhostPlatform(PointF p, Vector2d velocity)
    {
        super(EPlatformType.GHOST, p, velocity);
    }

    ///// METHODS

    @Override
    public void update()
    {
        super.update();

        if (lifeTime <= 0)
        {
            playerInstance.offPlatform();
            visible = false;
            enabled = false;
            EntitiesHandler.getInstance().removeEntity(this);
        }
        else if (bPlayerIsOn)
            lifeTime -= MainThread.getDeltaTime();
    }
}

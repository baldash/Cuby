package com.keimyung.baldash.cuby.GameObjects;

import android.graphics.PointF;

import com.keimyung.baldash.cuby.Misc.EPlatformType;

import javax.vecmath.Vector2d;

public class VerticalPlatform extends Platform
{
    public VerticalPlatform(PointF pos, Vector2d velocity)
    {
        super(EPlatformType.MOVING_V, pos, velocity);
    }

    @Override
    public void update()
    {
        super.update();

        if (bPlayerIsOn)
        {
            velocity.y = 130;
            playerInstance.velocity.y = velocity.y;
        }
        else
            velocity.y = 0;
    }
}

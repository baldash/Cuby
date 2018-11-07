package com.keimyung.baldash.cuby.GameObjects;

import android.graphics.PointF;

import com.keimyung.baldash.cuby.Misc.EPlatformType;

import javax.vecmath.Vector2d;

public class JumpingPlatform extends Platform
{
    public JumpingPlatform(PointF p, Vector2d velocity)
    {
        super(EPlatformType.JUMPING, p, velocity);
    }

    ///// OVERRIDES

    @Override
    public void update()
    {
        super.update();

        if (bPlayerIsOn)
            playerInstance.doJump();
    }
}

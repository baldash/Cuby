package com.keimyung.baldash.cuby.GameObjects;

import android.graphics.PointF;

import com.keimyung.baldash.cuby.Misc.EPlatformType;

import javax.vecmath.Vector2d;

public class QuickPlatform extends Platform
{

    public QuickPlatform(PointF pos, Vector2d velocity)
    {
        super(EPlatformType.QUICK, pos, velocity);
        double bonusVelocity = velocity.x / 4;

        setVelocity(new Vector2d(velocity.x + bonusVelocity, velocity.y));
        if (bPlayerIsOn)
            playerInstance.setVelocity(velocity);
    }

    ///// OVERRIDES

    @Override
    public void setVelocity(Vector2d newVelocity)
    {
        double bonusVelocity = newVelocity.x / 4;

        velocity = new Vector2d(newVelocity.x + bonusVelocity, newVelocity.y);
        if (bPlayerIsOn)
            playerInstance.setVelocity(velocity);
    }
}

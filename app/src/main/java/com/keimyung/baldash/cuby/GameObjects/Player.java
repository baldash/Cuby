package com.keimyung.baldash.cuby.GameObjects;

import android.graphics.Canvas;
import android.graphics.PointF;

public class Player extends GameObject
{

    private boolean bJumping = false;

    public Player(PointF p)
    {
        super("cuby", p);
    }

    ///// GETTERS

    public boolean getJumping()
    {
        return bJumping;
    }

    ///// METHODS

    public void doJump()
    {
        if (!bJumping)
        {
            velocity.set(40, -80);
            gravity.set(0, 50);

            bJumping = true;
        }
    }

    public void onPlatform(GameObject platform)
    {
        bJumping = false;

        gravity.set(0, 0);
        velocity.set(platform.getVelocity());
    }

    ///// OVERRIDES

    @Override
    public void draw(Canvas canvas)
    {
        canvas.drawBitmap(sprite.getBmp(), null, sprite.getSpriteRect(), null);
    }

    @Override
    public void update()
    {
        updatePos();
    }

}

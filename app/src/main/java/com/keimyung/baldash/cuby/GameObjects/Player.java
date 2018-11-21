package com.keimyung.baldash.cuby.GameObjects;

import android.graphics.Canvas;
import android.graphics.PointF;
import android.provider.Settings;

import com.keimyung.baldash.cuby.MainThread;

import javax.vecmath.Vector2d;

public class Player extends GameObject
{
    private boolean bJumping = false;
    private float jumpStrength = 4.0f;

    public Player(PointF p)
    {
        super(p);
        sprite.setSprite("cuby");
    }

    ///// GETTERS

    public boolean jumping()
    {
        return bJumping;
    }

    ///// METHODS

    public void doJump()
    {
        if (!bJumping)
        {
            System.out.println("player jumping");

            velocity.set(120, -250);
            gravity.set(0, 120);

            bJumping = true;
        }
    }

    public void onPlatform(GameObject platform)
    {
        bJumping = false;

        gravity.set(0, 0);
        velocity.set(platform.getVelocity());
    }

    public void offPlatform()
    {
        gravity.set(0, 120);
        velocity.set(0, 820);
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
        if (bJumping)
            updatePosJump();
        else
            updatePos();
    }

    public void updatePosJump()
    {
        PointF playerPos = sprite.getPos();
        Vector2d scaledVelocity = new Vector2d();
        Vector2d scaledGravity = new Vector2d();
        double dt = MainThread.getDeltaTime();

        prevPos = new PointF(playerPos.x, playerPos.y);
        scaledVelocity.scale(dt * jumpStrength, velocity);
        scaledGravity.scale(dt * jumpStrength, gravity);

        sprite.setPos((float)(playerPos.x + scaledVelocity.x), (float)(playerPos.y + scaledVelocity.y));
        velocity.add(velocity, scaledGravity);
    }

}

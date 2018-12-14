package com.keimyung.baldash.cuby.GameObjects;

import android.graphics.Canvas;
import android.graphics.PointF;
import android.provider.Settings;

import com.keimyung.baldash.cuby.Handlers.CollectableHandler;
import com.keimyung.baldash.cuby.Handlers.SoundManager;
import com.keimyung.baldash.cuby.MainThread;

import java.lang.reflect.Type;

import javax.vecmath.Vector2d;

public class Player extends GameObject
{
    private boolean bJumping = false;
    private float jumpStrength = 4.0f;

    private CollectableHandler collectableHandler;

    public Player(PointF p, CollectableHandler collectableHandler)
    {
        super(p);
        sprite.setSprite("cuby");
        this.collectableHandler = collectableHandler;
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
            SoundManager.getInstance().playSound("jump");

            velocity.set(120, -250);
            gravity.set(0, 120);

            bJumping = true;
        }
    }

    public void onPlatform(Platform platform)
    {
        bJumping = false;

        gravity.set(0, 0);
        velocity.set(platform.getVelocity());

        if (platform instanceof StartPlatform)
            return;

        switch (platform.getType())
        {
            case BASIC:
                collectableHandler.addBonusPoints(100);
                break;
            case QUICK:
                collectableHandler.addBonusPoints(150);
                break;
            case GHOST:
                collectableHandler.addBonusPoints(200);
                break;
            case MOVING_V:
                collectableHandler.addBonusPoints(300);
                break;
            case JUMPING:
                collectableHandler.addBonusPoints(500);
                break;
        }
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

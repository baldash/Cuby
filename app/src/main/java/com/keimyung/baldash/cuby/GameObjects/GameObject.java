package com.keimyung.baldash.cuby.GameObjects;

import android.graphics.Canvas;
import android.graphics.Point;
import android.graphics.PointF;
import android.view.VelocityTracker;

import com.keimyung.baldash.cuby.MainThread;
import com.keimyung.baldash.cuby.Sprite;

import javax.vecmath.Vector2d;

public abstract class GameObject {

    protected Sprite sprite;

    // toggle drawing of the game object
    protected boolean visible = true;
    // toggle update of the game object
    protected boolean enabled = true;

    protected Vector2d velocity;
    protected Vector2d gravity;

    public GameObject(String name, PointF p)
    {
        sprite = new Sprite(name, p);
        velocity = new Vector2d();
        gravity = new Vector2d();
    }

    ///// GETTERS

    public Sprite getSprite()
    {
        return sprite;
    }

    public boolean isEnabled()
    {
        return enabled;
    }

    public boolean isVisible()
    {
        return visible;
    }

    ///// SETTERS

    public void setVisible(boolean visible)
    {
        this.visible = visible;
    }

    public void setEnabled(boolean enabled)
    {
        this.enabled = enabled;
    }

    ///// ABSTRACTS

    public abstract void update();
    public abstract void draw(Canvas canvas);

    ///// METHODS

    public void updatePos()
    {
        PointF playerPos = sprite.getPos();
        Vector2d scaledVelocity = new Vector2d();
        Vector2d scaledGravity = new Vector2d();
        double dt = MainThread.getDeltaTime();

        scaledVelocity.scale(dt, velocity);
        scaledGravity.scale(dt, gravity);

        sprite.setPos((float)(playerPos.x + scaledVelocity.x), (float)(playerPos.y + scaledVelocity.y));
        velocity.add(velocity, scaledGravity);
    }

}

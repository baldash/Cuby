package com.keimyung.baldash.cuby.GameObjects;

import android.graphics.Canvas;
import android.graphics.Point;

import com.keimyung.baldash.cuby.Sprite;

public abstract class GameObject {

    protected Sprite sprite;

    // toggle drawing of the game object
    protected boolean visible = true;
    // toggle update of the game object
    protected boolean enabled = true;

    public GameObject(String name, Point p)
    {
        sprite = new Sprite(name, p);
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

}

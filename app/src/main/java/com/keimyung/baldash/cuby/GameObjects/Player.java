package com.keimyung.baldash.cuby.GameObjects;

import android.graphics.Canvas;
import android.graphics.Point;
import android.graphics.Rect;

import com.keimyung.baldash.cuby.Sprite;

public class Player extends GameObject {

    public Player(Point p)
    {
        super("cuby", p);
    }

    @Override
    public void draw(Canvas canvas)
    {
        canvas.drawBitmap(sprite.getBmp(), null, sprite.getSpriteRect(), null);
    }

    @Override
    public void update()
    {
    }

    public void update(Point p)
    {
        sprite.setPos(p);
    }

}

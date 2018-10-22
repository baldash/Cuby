package com.keimyung.baldash.cuby.GameObjects;

import android.graphics.Canvas;
import android.graphics.PointF;
import javax.vecmath.Vector2d;

public class Player extends GameObject
{

    public Player(PointF p)
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
        updatePos();
    }

}

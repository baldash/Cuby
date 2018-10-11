package com.keimyung.baldash.cuby;

import android.graphics.Canvas;
import android.graphics.Point;
import android.graphics.Rect;

public class Player implements GameObject {

    private Sprite playerSprite;

    public Player(Rect rect, int color)
    {
        playerSprite = new Sprite("cuby", new Point(100, 100));
    }

    @Override
    public void draw(Canvas canvas)
    {
        canvas.drawBitmap(playerSprite.getBmp(), null, playerSprite.getSpriteRect(), null);
    }

    @Override
    public void update()
    {

    }

    public void update(Point p)
    {
        playerSprite.setPos(p);
    }

}

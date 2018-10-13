package com.keimyung.baldash.cuby.GameObjects;

import android.graphics.Canvas;
import android.graphics.Point;
import android.graphics.Rect;

import com.keimyung.baldash.cuby.Misc.EPlatformType;
import com.keimyung.baldash.cuby.Handlers.EntitiesHandler;

public class Platform extends GameObject {

    private EPlatformType type;

    public Platform(EPlatformType type, Point p)
    {
        super("basicPlatform", p);

        this.type = type;
    }

    public EPlatformType getType()
    {
        return type;
    }

    public boolean collidePlayer()
    {
        return Rect.intersects(sprite.getSpriteRect(),
                EntitiesHandler.getInstance().getEntity("player").getSprite().getSpriteRect());
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

}

package com.keimyung.baldash.cuby.GameObjects;

import android.graphics.Canvas;
import android.graphics.PointF;
import android.graphics.RectF;

import com.keimyung.baldash.cuby.Misc.EPlatformType;
import com.keimyung.baldash.cuby.Handlers.EntitiesHandler;

import javax.vecmath.Vector2d;

public class Platform extends GameObject {

    private EPlatformType type;
    private Player playerInstance;

    public Platform(EPlatformType type, PointF p, Vector2d velocity)
    {
        super("basicPlatform", p);

        this.type = type;
        this.velocity.set(velocity);
        playerInstance = (Player)EntitiesHandler.getInstance().getEntity("player");
    }

    public EPlatformType getType()
    {
        return type;
    }

    public boolean collideObject(GameObject go)
    {
        return RectF.intersects(sprite.getSpriteRect(), go.getSprite().getSpriteRect());
    }

    public boolean objectIsOn(GameObject go)
    {
        PointF goPos = go.getSprite().getPos();
        PointF platPos = sprite.getPos();

        return ((goPos.x + go.getSprite().getWidth()) >= platPos.x &&
                goPos.x <= (platPos.x + sprite.getWidth()) &&
                (goPos.y + go.getSprite().getHeight()) == platPos.y);
    }

    @Override
    public void draw(Canvas canvas)
    {
        canvas.drawBitmap(sprite.getBmp(), null, sprite.getSpriteRect(), null);
    }

    @Override
    public void update()
    {
        if (/*playerInstance.getJumping() && */objectIsOn(playerInstance))
            playerInstance.onPlatform(this);

        updatePos();
    }

}

package com.keimyung.baldash.cuby.GameObjects;

import android.graphics.Canvas;
import android.graphics.Point;
import android.graphics.PointF;
import android.graphics.RectF;

import com.keimyung.baldash.cuby.Misc.EPlatformType;
import com.keimyung.baldash.cuby.Handlers.EntitiesHandler;

import javax.vecmath.Vector2d;

public class Platform extends GameObject {

    private EPlatformType type;
    private Player playerInstance;
    private boolean bPlayerIsOn = false;

    public Platform(EPlatformType type, PointF p, Vector2d velocity)
    {
        super("basicPlatform", p);

        this.type = type;
        this.velocity.set(velocity);
        playerInstance = (Player)EntitiesHandler.getInstance().getEntity("player");
    }

    ///// GETTERS

    public EPlatformType getType()
    {
        return type;
    }

    ///// METHODS

    public boolean collideObject(GameObject go)
    {
        return RectF.intersects(sprite.getSpriteRect(), go.getSprite().getSpriteRect());
    }

    public boolean objectIsOn(GameObject go)
    {
        Point goPos = new Point((int)go.getSprite().getPos().x, (int)go.getSprite().getPos().y);
        Point platPos = new Point((int)sprite.getPos().x, (int)sprite.getPos().y);

        if ((goPos.x + go.getSprite().getWidth()) >= platPos.x &&
                goPos.x <= (platPos.x + sprite.getWidth()) &&
                (goPos.y + go.getSprite().getHeight()) >= platPos.y - 5 &&
                (goPos.y + go.getSprite().getHeight()) <= platPos.y + 5)
        {
            go.getSprite().setPos(go.getSprite().getPos().x, sprite.getPos().y - go.getSprite().getHeight());
            return true;
        }
        return false;
    }

    private void checkScreenBounds()
    {
        if ((sprite.getPos().x + sprite.getWidth()) < 0)
        {
            visible = false;
            enabled = false;
            EntitiesHandler.getInstance().removeEntity(this);
        }
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
        checkScreenBounds();

        if (!bPlayerIsOn && playerInstance.jumping() && objectIsOn(playerInstance))
        {
            bPlayerIsOn = true;
            playerInstance.onPlatform(this);
        }

        updatePos();
    }

}

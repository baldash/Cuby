package com.keimyung.baldash.cuby.GameObjects;

import android.graphics.Canvas;
import android.graphics.Point;
import android.graphics.PointF;
import android.graphics.RectF;

import com.keimyung.baldash.cuby.Misc.EPlatformType;
import com.keimyung.baldash.cuby.Handlers.EntitiesHandler;

import javax.vecmath.Vector2d;

public class Platform extends GameObject {

    protected EPlatformType type;
    protected Player playerInstance;
    protected boolean bPlayerIsOn = false;

    public Platform(EPlatformType type, PointF p, Vector2d velocity)
    {
        super(p);

        this.type = type;
        initSprite();
        this.velocity.set(velocity);
        playerInstance = (Player)EntitiesHandler.getInstance().getEntity("player");
    }

    ///// GETTERS

    public EPlatformType getType()
    {
        return type;
    }

    ///// METHODS

    private void initSprite()
    {
        switch (type)
        {
            case BASIC:
                sprite.setSprite("basic-platform");
                break;
            case MOVING_V:
                sprite.setSprite("moving-v-platform");
                break;
            case GHOST:
                sprite.setSprite("ghost-platform");
                break;
            case QUICK:
                sprite.setSprite("quick-platform");
                break;
            case JUMPING:
                sprite.setSprite("jumping-platform");
                break;
        }
    }

    public boolean collideObject(GameObject go)
    {
        return RectF.intersects(sprite.getSpriteRect(), go.getSprite().getSpriteRect());
    }

    public boolean playerIsOn(GameObject go)
    {
        Point goPos = new Point((int)go.getSprite().getPos().x, (int)go.getSprite().getPos().y);
        Point goPrevPos = new Point((int)go.getPrevPos().x, (int)go.getPrevPos().y);
        int goHeight = playerInstance.sprite.getHeight();
        int goWidth = playerInstance.sprite.getWidth();
        Point platPos = new Point((int)sprite.getPos().x, (int)sprite.getPos().y);

        if ((goPos.x + goWidth) >= platPos.x && goPos.x <= (platPos.x + sprite.getWidth()) &&
                (goPrevPos.y + goHeight <= platPos.y && platPos.y <= goPos.y + goHeight))
        {
            go.getSprite().setPos(go.getSprite().getPos().x, sprite.getPos().y - goHeight);
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

        if (!bPlayerIsOn && playerInstance.jumping() && playerIsOn(playerInstance))
        {
            bPlayerIsOn = true;
            playerInstance.onPlatform(this);
        }

        if (playerInstance.jumping())
            bPlayerIsOn = false;

        updatePos();
    }

}

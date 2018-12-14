package com.keimyung.baldash.cuby.GameObjects;

import android.graphics.Canvas;
import android.graphics.PointF;
import android.graphics.RectF;

import com.keimyung.baldash.cuby.Handlers.CollectableHandler;
import com.keimyung.baldash.cuby.Handlers.EntitiesHandler;
import com.keimyung.baldash.cuby.Handlers.SoundManager;
import com.keimyung.baldash.cuby.Misc.ECollectableType;

import javax.vecmath.Vector2d;

public class Collectable extends GameObject
{
    private ECollectableType type;
    private GameObject playerInstance;
    private CollectableHandler handler;

    public Collectable(PointF pos, ECollectableType type, Vector2d velocity, CollectableHandler handler)
    {
        super(pos);

        this.velocity = velocity;
        this.type = type;
        playerInstance = EntitiesHandler.getInstance().getEntity("player");
        this.handler = handler;

        switch (type)
        {
            case BONUS:
                sprite.setSprite("normal-bonus-collectable");
                break;
            case BONUSL:
                sprite.setSprite("big-bonus-collectable");
                break;
            case MALUS:
                sprite.setSprite("malus-collectable");
                break;
        }
    }

    ///// GETTERS

    public ECollectableType getType()
    {
        return type;
    }

    ///// METHODS

    private void setSprite()
    {
    }

    private boolean playerCollides()
    {
        return RectF.intersects(sprite.getSpriteRect(), playerInstance.getSprite().getSpriteRect());
    }

    ///// OVERRIDES

    @Override
    public void update()
    {
        if (playerCollides())
        {
            switch (type)
            {
                case BONUS:
                    SoundManager.getInstance().playSound("bonus-collectable");
                    handler.addBonusPoints(1000);
                    break;
                case BONUSL:
                    SoundManager.getInstance().playSound("bonus-collectable");
                    handler.addBonusPoints(3500);
                    break;
                case MALUS:
                    SoundManager.getInstance().playSound("malus-collectable");
                    handler.addBonusPoints(-1500);
                    break;
            }

            enabled = false;
            visible = false;
        }

        updatePos();
    }

    @Override
    public void draw(Canvas canvas)
    {
        canvas.drawBitmap(sprite.getBmp(), null, sprite.getSpriteRect(), null);
    }
}

package com.keimyung.baldash.cuby.GameObjects;

import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.PointF;

import com.keimyung.baldash.cuby.Handlers.EntitiesHandler;
import com.keimyung.baldash.cuby.MainThread;
import com.keimyung.baldash.cuby.Misc.EPlatformType;

import javax.vecmath.Vector2d;

public class GhostPlatform extends Platform
{

    private float maxLifeTime = 1.3f;
    private float lifeTime;

    public GhostPlatform(PointF p, Vector2d velocity)
    {
        super(EPlatformType.GHOST, p, velocity);

        lifeTime = maxLifeTime;
    }

    ///// OVERRIDES

    @Override
    public void update()
    {
        super.update();

        if (lifeTime <= 0)
        {
            playerInstance.offPlatform();
            visible = false;
            enabled = false;
            EntitiesHandler.getInstance().removeEntity(this);
        }
        else if (bPlayerIsOn)
            lifeTime -= MainThread.getDeltaTime();
    }

    @Override
    public void draw(Canvas canvas)
    {
        Paint paint = new Paint();

        if (lifeTime != maxLifeTime)
        {
            paint.setAlpha((int)(lifeTime / maxLifeTime * 100));
            canvas.drawBitmap(sprite.getBmp(), null, sprite.getSpriteRect(), paint);
        }
        else
            canvas.drawBitmap(sprite.getBmp(), null, sprite.getSpriteRect(), null);
    }
}

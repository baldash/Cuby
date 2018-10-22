package com.keimyung.baldash.cuby;

import android.graphics.Bitmap;
import android.graphics.PointF;
import android.graphics.RectF;

import com.keimyung.baldash.cuby.Handlers.ResourcesHandler;

public class Sprite {

    private Bitmap bmp;
    private PointF pos;
    private RectF dstRect;

    public Sprite(String name, PointF pos)
    {
        bmp = ResourcesHandler.getInstance().getResourceByName(name);
        this.pos = pos;
        dstRect = new RectF(pos.x, pos.y, bmp.getWidth() + pos.x, bmp.getHeight() + pos.y);
    }

    ///// GETTERS

    public PointF getPos()
    {
        return pos;
    }

    public int getWidth()
    {
        return bmp.getWidth();
    }

    public int getHeight()
    {
        return bmp.getHeight();
    }

    public Bitmap getBmp()
    {
        return bmp;
    }

    public RectF getSpriteRect()
    {
        return dstRect;
    }

    ///// SETTERS

    public void setPos(PointF newPos)
    {
        pos = newPos;
        dstRect.set(pos.x, pos.y, bmp.getWidth() + pos.x, bmp.getHeight() + pos.y);
    }

    public void setPos(float x, float y)
    {
        pos = new PointF(x, y);
        dstRect.set(pos.x, pos.y, bmp.getWidth() + pos.x, bmp.getHeight() + pos.y);
    }

    public void setBmp(String fileName)
    {
        bmp = ResourcesHandler.getInstance().getResourceByName(fileName);
        dstRect.set(pos.x, pos.y, bmp.getWidth() + pos.x, bmp.getHeight() + pos.y);
    }
}

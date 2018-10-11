package com.keimyung.baldash.cuby;

import android.graphics.Bitmap;
import android.graphics.Point;
import android.graphics.Rect;

import com.keimyung.baldash.cuby.Handlers.ResourcesHandler;

public class Sprite {

    private Bitmap bmp;
    private Point pos;
    private Rect dstRect;

    public Sprite(String name, Point pos)
    {
        bmp = ResourcesHandler.getInstance().getResourceByName(name);
        this.pos = pos;
        dstRect = new Rect(pos.x, pos.y, bmp.getWidth() + pos.x, bmp.getHeight() + pos.y);
    }

    ///// GETTERS

    public Point getPos()
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

    public Rect getSpriteRect()
    {
        return dstRect;
    }

    ///// SETTERS

    public void setPos(Point newPos)
    {
        pos = newPos;
        dstRect.set(pos.x, pos.y, bmp.getWidth() + pos.x, bmp.getHeight() + pos.y);
    }

    public void setBmp(String fileName)
    {
        bmp = ResourcesHandler.getInstance().getResourceByName(fileName);
        dstRect.set(pos.x, pos.y, bmp.getWidth() + pos.x, bmp.getHeight() + pos.y);
    }

}

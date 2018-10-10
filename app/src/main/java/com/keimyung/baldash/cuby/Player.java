package com.keimyung.baldash.cuby;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Point;
import android.graphics.Rect;
import android.graphics.RectF;

public class Player implements GameObject {

    private Rect rect;
    private int color;

    public Player(Rect rect, int color)
    {
        this.rect = rect;
        this.color = color;
        ResourcesHandler.getInstance().addResource(R.drawable.cubypng, "cuby");
    }

    @Override
    public void draw(Canvas canvas)
    {
        Paint paint = new Paint();
        Bitmap cuby = ResourcesHandler.getInstance().getResourceByName("cuby");
        int offsetX = 100;
        int offsetY = 100;
        Rect dstRect = new Rect(offsetX, offsetY, cuby.getWidth() + offsetX, cuby.getHeight() + offsetY);

        paint.setColor(color);
        canvas.drawRect(rect, paint);
        canvas.drawBitmap(cuby, null, dstRect, null);
    }

    @Override
    public void update()
    {

    }

    public void update(Point p)
    {
        rect.set(p.x - rect.width()/2, p.y - rect.height()/2, p.x + rect.width()/2, p.y + rect.height()/2);
    }

}

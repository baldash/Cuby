package com.keimyung.baldash.cuby;

import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;

import java.util.HashMap;

public class ResourcesHandler {

    private static final ResourcesHandler instance = new ResourcesHandler();

    private HashMap<String, Bitmap> sprites;
    private Resources resources;

    private ResourcesHandler()
    {
        sprites = new HashMap<>();
    }

    public static ResourcesHandler getInstance()
    {
        return instance;
    }

    public void addResource(int file, String name)
    {
        Bitmap bm = BitmapFactory.decodeResource(resources, file);

        sprites.put(name, bm);
    }

    public Bitmap getResourceByName(String name)
    {
        return sprites.get(name);
    }

    public void setResources(Resources resources)
    {
        this.resources = resources;
    }

}

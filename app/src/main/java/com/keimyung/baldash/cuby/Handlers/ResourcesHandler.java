package com.keimyung.baldash.cuby.Handlers;

import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;

import com.keimyung.baldash.cuby.R;

import java.util.HashMap;

public class ResourcesHandler {

    private static ResourcesHandler instance = null;

    private HashMap<String, Bitmap> sprites = new HashMap<>();
    private Resources resources;

    ///// GETTERS

    public static ResourcesHandler getInstance()
    {
        if (instance == null)
            instance = new ResourcesHandler();
        return instance;
    }

    public Bitmap getResourceByName(String name)
    {
        return sprites.get(name);
    }

    ///// SETTERS

    public void setResources(Resources resources)
    {
        this.resources = resources;
    }

    ///// MTHODS

    public void initResources()
    {
        addResource(R.drawable.goodcubix, "cuby");
        addResource(R.drawable.basicplatform, "basic-platform");
        addResource(R.drawable.moving_v_platform, "moving-v-platform");
        addResource(R.drawable.ghost_platform, "ghost-platform");
        addResource(R.drawable.quick_platform, "quick-platform");
        addResource(R.drawable.jumping_platform, "jumping-platform");
        addResource(R.drawable.sky_background, "sky-background");
        addResource(R.drawable.big_bonus_collectable, "big-bonus-collectable");
        addResource(R.drawable.normal_collectable, "normal-bonus-collectable");
        addResource(R.drawable.malus_collectable, "malus-collectable");
    }

    public void addResource(int file, String name)
    {
        Bitmap bm = BitmapFactory.decodeResource(resources, file);

        sprites.put(name, bm);
    }

}

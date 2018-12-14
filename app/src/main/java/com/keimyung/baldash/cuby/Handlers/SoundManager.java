package com.keimyung.baldash.cuby.Handlers;

import android.content.Context;
import android.media.MediaPlayer;

import com.keimyung.baldash.cuby.R;

import java.util.HashMap;

public class SoundManager 
{
    private static SoundManager instance = null;

    Context context;
    HashMap<String, MediaPlayer> sounds = new HashMap<>();

    //// GETTERS

    public static SoundManager getInstance()
    {
        if (instance == null)
            instance = new SoundManager();
        return instance;
    }

    public MediaPlayer getSound(String name)
    {
        return sounds.get(name);
    }

    ///// SETTERS

    public void setContext(Context context)
    {
        this.context = context;
    }

    ///// METHODS

    public void initSounds()
    {
        addSound("main-theme", R.raw.main_theme);
        addSound("jump", R.raw.jump);
        addSound("land", R.raw.land);
        addSound("death", R.raw.death);
        addSound("bonus-collectable", R.raw.bonus_collectable);
        addSound("malus-collectable", R.raw.malus_collectable);
    }

    public void addSound(String name, int soundID)
    {
        MediaPlayer soundPlayer = MediaPlayer.create(context, soundID);

        sounds.put(name, soundPlayer);
    }

    public void playSound(String name)
    {
        sounds.get(name).start();
    }

    public void stopSound(String name)
    {
        sounds.get(name).stop();
    }
}

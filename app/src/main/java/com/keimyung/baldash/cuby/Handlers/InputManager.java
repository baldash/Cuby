package com.keimyung.baldash.cuby.Handlers;

import android.view.GestureDetector;
import android.view.MotionEvent;

import com.keimyung.baldash.cuby.GameManager;
import com.keimyung.baldash.cuby.Misc.Constants;

public class InputManager extends GestureDetector.SimpleOnGestureListener
{
    private GameManager gameManager;

    public InputManager(GameManager gameManager)
    {
        this.gameManager = gameManager;
    }

    ///// OVERRIDES

    // By default this method returns false and makes the gesture detector ignore all the inputs,
    // so we have to override it that way in order to make it work
    @Override
    public boolean onDown(MotionEvent e) {
        return true;
    }
}
